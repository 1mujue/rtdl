#include "rtdl_demo_webots/WorldBridgeDriver.hpp"

#include <cmath>
#include <stdexcept>

#include "webots/robot.h"
#include "webots/supervisor.h"

#include <pluginlib/class_list_macros.hpp>

#include "rtdl_demo_interfaces/msg/object_state.hpp"

namespace rtdl_demo_webots{
std::string WorldBridgeDriver::roomOf(double x, double y)
{
  return (x < 0.0) ? "kitchen" : "living_room";
}

double WorldBridgeDriver::dist2d(const double * a, const double * b)
{
  const double dx = a[0] - b[0];
  const double dy = a[1] - b[1];
  return std::sqrt(dx * dx + dy * dy);
}
bool WorldBridgeDriver::isObjNearCar(const double* obj_pos, const double* car_pos){
  return dist2d(obj_pos, car_pos) < 1.5;
}
std::string WorldBridgeDriver::supportOfCup(const double * cup_pos, const double * table_pos)
{
  if (dist2d(cup_pos, table_pos) < 0.15) {
    return "table";
  }
  return "";
}
// rot3x3 是 Webots 返回的 3x3 朝向矩阵，按平面运动近似提取 yaw。
double WorldBridgeDriver::yawFromOrientation(const double * rot3x3)
{
  return std::atan2(rot3x3[3], rot3x3[0]);
}

void WorldBridgeDriver::init(
  webots_ros2_driver::WebotsNode * node,
  std::unordered_map<std::string, std::string> & properties)
{
  node_ = node;

  car_node_ = wb_supervisor_node_get_from_def("CAR");
  cup_node_ = wb_supervisor_node_get_from_def("CUP");
  table_node_ = wb_supervisor_node_get_from_def("TABLE");

  if (!car_node_ || !cup_node_ || !table_node_) {
    throw std::runtime_error("WorldBridgeDriver: failed to find DEF CAR/CUP/TABLE");
  }

  get_world_state_srv_ =
  node_->create_service<rtdl_demo_interfaces::srv::GetWorldState>(
      "/get_world_state",
      std::bind(
        &WorldBridgeDriver::handleGetWorldState,
        this,
        std::placeholders::_1,
        std::placeholders::_2));

  pick_pri_srv_ = 
  node_->create_service<rtdl_demo_interfaces::srv::PickPri>(
    "/pick_pri",
    std::bind(
      &WorldBridgeDriver::handlePickPri,
      this,
      std::placeholders::_1,
      std::placeholders::_2
    )
  );

  place_pri_srv_ = 
  node_->create_service<rtdl_demo_interfaces::srv::PlacePri>(
    "/place_pri",
    std::bind(
      &WorldBridgeDriver::handlePlacePri,
      this,
      std::placeholders::_1,
      std::placeholders::_2
    )
  );


  RCLCPP_INFO(node_->get_logger(), "WorldBridgeDriver initialized.");
}

void WorldBridgeDriver::updateCachedState()
{
  const double * car_pos = wb_supervisor_node_get_position(car_node_);
  const double* car_rot = wb_supervisor_node_get_orientation(car_node_);
  const double * cup_pos = wb_supervisor_node_get_position(cup_node_);
  const double * table_pos = wb_supervisor_node_get_position(table_node_);

  if (!car_pos || !car_rot || !cup_pos || !table_pos) {
    return;
  }
  cached_state_.robot_room = roomOf(car_pos[0], car_pos[1]);
  cached_state_.holding_object = carried_object_;

  cached_state_.robot_x = car_pos[0];
  cached_state_.robot_y = car_pos[1];
  cached_state_.robot_yaw = yawFromOrientation(car_rot);

  cached_state_.cup_room = roomOf(cup_pos[0], cup_pos[1]);
  cached_state_.cup_support = supportOfCup(cup_pos, table_pos);
}

void WorldBridgeDriver::handleGetWorldState(
  const std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState::Request> req,
  std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState::Response> res)
{
  res->success = true;
  res->message = "Real Webots world state queried successfully.";

  res->state.robot_room = cached_state_.robot_room;
  res->state.holding_object = cached_state_.holding_object;
  res->state.robot_x = cached_state_.robot_x;
  res->state.robot_y = cached_state_.robot_y;
  res->state.robot_yaw = cached_state_.robot_yaw;
  
  res->state.objects.clear();

  rtdl_demo_interfaces::msg::ObjectState cup_msg;
  cup_msg.name = "cup";
  cup_msg.room = cached_state_.cup_room;
  cup_msg.support = cached_state_.cup_support;
  cup_msg.held_by_robot = (cached_state_.holding_object == "cup");

  res->state.objects.push_back(cup_msg);
}

void WorldBridgeDriver::handlePickPri(
    const std::shared_ptr<rtdl_demo_interfaces::srv::PickPri::Request> req,
    std::shared_ptr<rtdl_demo_interfaces::srv::PickPri::Response> res
){
  if(!carried_object_.empty()){
    res->success = false;
    res->message = "The robot is already holding" + carried_object_;
    return;
  }
  const double* car_pos = wb_supervisor_node_get_position(car_node_);
  WbNodeRef obj_node = nullptr;
  if(req->object_name == "cup"){
    obj_node = cup_node_;
  }
  if(obj_node == nullptr){
    res->success = false;
    res->message = "The object: " + req->object_name + " doesn't exist in the world.";
    return;
  }
  const double* obj_pos = wb_supervisor_node_get_position(obj_node);
  if(!isObjNearCar(obj_pos, car_pos)){
    res->success = false;
    res->message = "The object: " + req->object_name + " is too far from car.";
    return;
  }
  WbFieldRef obj_physics = wb_supervisor_node_get_field(obj_node, "physics");
  wb_supervisor_field_remove_sf(obj_physics);
  carried_object_ = req->object_name;

  res->success = true;
  res->message = "Pick object: " + req->object_name + "successfully.";
}

bool getBoxSizeFromSolid(WbNodeRef solid_node, double size_out[3]) {
  if (!solid_node) {
    return false;
  }

  WbFieldRef children_field = wb_supervisor_node_get_field(solid_node, "children");
  if (!children_field) {
    return false;
  }

  const int child_count = wb_supervisor_field_get_count(children_field);
  if (child_count <= 0) {
    return false;
  }

  // 简化假设：第 0 个 child 就是 Shape
  WbNodeRef shape_node = wb_supervisor_field_get_mf_node(children_field, 0);
  if (!shape_node) {
    return false;
  }

  WbFieldRef geometry_field = wb_supervisor_node_get_field(shape_node, "geometry");
  if (!geometry_field) {
    return false;
  }

  WbNodeRef geometry_node = wb_supervisor_field_get_sf_node(geometry_field);
  if (!geometry_node) {
    return false;
  }

  // 可选：检查类型名是不是 Box
  const char *type_name = wb_supervisor_node_get_type_name(geometry_node);
  if (!type_name || std::strcmp(type_name, "Box") != 0) {
    return false;
  }

  WbFieldRef size_field = wb_supervisor_node_get_field(geometry_node, "size");
  if (!size_field) {
    return false;
  }

  const double *size = wb_supervisor_field_get_sf_vec3f(size_field);
  if (!size) {
    return false;
  }

  size_out[0] = size[0];
  size_out[1] = size[1];
  size_out[2] = size[2];
  return true;
}

bool getCylinderHeightFromSolid(WbNodeRef solid_node, double &height_out) {
  if (!solid_node) {
    return false;
  }

  WbFieldRef children_field = wb_supervisor_node_get_field(solid_node, "children");
  if (!children_field) {
    return false;
  }

  const int child_count = wb_supervisor_field_get_count(children_field);
  if (child_count <= 0) {
    return false;
  }

  // 简化假设：第 0 个 child 就是 Shape
  WbNodeRef shape_node = wb_supervisor_field_get_mf_node(children_field, 0);
  if (!shape_node) {
    return false;
  }

  WbFieldRef geometry_field = wb_supervisor_node_get_field(shape_node, "geometry");
  if (!geometry_field) {
    return false;
  }

  WbNodeRef geometry_node = wb_supervisor_field_get_sf_node(geometry_field);
  if (!geometry_node) {
    return false;
  }

  const char *type_name = wb_supervisor_node_get_type_name(geometry_node);
  if (!type_name || std::strcmp(type_name, "Cylinder") != 0) {
    return false;
  }

  WbFieldRef height_field = wb_supervisor_node_get_field(geometry_node, "height");
  if (!height_field) {
    return false;
  }

  height_out = wb_supervisor_field_get_sf_float(height_field);
  return true;
}


void WorldBridgeDriver::handlePlacePri(
    const std::shared_ptr<rtdl_demo_interfaces::srv::PlacePri::Request> req,
    std::shared_ptr<rtdl_demo_interfaces::srv::PlacePri::Response> res
){
  if(carried_object_.empty() || carried_object_ != req->object_name){
    res->success = false;
    res->message = "The robot doesn't hold object: " + req->object_name;
    return;
  }
  WbNodeRef support_node = nullptr;
  if(req->location_name == "table"){
    support_node = table_node_;
  }
  if(support_node == nullptr) {
    res->success = false;
    res->message = "The location: " + req->location_name + " doesn't exist in the world.";
    return;
  }
  WbFieldRef physics_field = wb_supervisor_node_get_field(cup_node_, "physics");
  if (physics_field) {
    wb_supervisor_field_import_sf_node_from_string(physics_field, "Physics { }");
  }
  WbFieldRef translations_field = wb_supervisor_node_get_field(cup_node_, "translations");
  carried_object_.clear();

  const double *table_pos = wb_supervisor_node_get_position(table_node_);
  if (!table_pos) {
    res->success = false;
    res->message = "Failed to read table position.";
    return;
  }

  double table_size[3];
  if (!getBoxSizeFromSolid(table_node_, table_size)) {
    res->success = false;
    res->message = "Failed to read table box size.";
    return;
  }

  double cup_height = 0.0;
  if (!getCylinderHeightFromSolid(cup_node_, cup_height)) {
    res->success = false;
    res->message = "Failed to read cup cylinder height.";
    return;
  }

  double place_pos[3];
  place_pos[0] = table_pos[0];
  place_pos[1] = table_pos[1];
  place_pos[2] = table_pos[2] + table_size[2] / 2.0 + cup_height / 2.0 + 0.005;

  WbFieldRef cup_translation = wb_supervisor_node_get_field(cup_node_, "translation");
  wb_supervisor_field_set_sf_vec3f(cup_translation, place_pos);


  res->success = true;
  res->message = "Place object: " + req->object_name + " on location: " + req->location_name + " successfully.";
}

void WorldBridgeDriver::step()
{
  updateCachedState();
  if(!carried_object_.empty()){
    WbNodeRef obj_node = carried_object_ == "cup" ? cup_node_ : nullptr;

    const double* car_pos = wb_supervisor_node_get_position(car_node_);
    const double* car_rot = wb_supervisor_node_get_orientation(car_node_);

    double yaw = yawFromOrientation(car_rot);

    double new_pos[3];
    new_pos[0] = car_pos[0] + 0.08 * std::cos(yaw);
    new_pos[1] = car_pos[1] + 0.08 * std::sin(yaw);
    new_pos[2] = 2;

    WbFieldRef obj_translation = wb_supervisor_node_get_field(obj_node, "translation");
    wb_supervisor_field_set_sf_vec3f(obj_translation, new_pos);
  }
}
}

PLUGINLIB_EXPORT_CLASS(
    rtdl_demo_webots::WorldBridgeDriver,
    webots_ros2_driver::PluginInterface
)