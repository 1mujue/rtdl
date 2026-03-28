#include "rtdl_demo_webots/WorldBridgeDriver.hpp"

#include <cmath>
#include <stdexcept>

#include "webots/robot.h"
#include "webots/supervisor.h"

#include <pluginlib/class_list_macros.hpp>

#include "rtdl_demo_interfaces/msg/object_state.hpp"

namespace rtdl_demo_webots
{
  double dist2d(const double *a, const double *b)
  {
    const double dx = a[0] - b[0];
    const double dy = a[1] - b[1];
    return std::sqrt(dx * dx + dy * dy);
  }
  // rot3x3 是 Webots 返回的 3x3 朝向矩阵，按平面运动近似提取 yaw。
  double yawFromOrientation(const double *rot3x3)
  {
    return std::atan2(rot3x3[3], rot3x3[0]);
  }
  void WorldBridgeDriver::init(
      webots_ros2_driver::WebotsNode *node,
      std::unordered_map<std::string, std::string> &properties)
  {
    node_ = node;

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
                std::placeholders::_2));

    place_pri_srv_ =
        node_->create_service<rtdl_demo_interfaces::srv::PlacePri>(
            "/place_pri",
            std::bind(
                &WorldBridgeDriver::handlePlacePri,
                this,
                std::placeholders::_1,
                std::placeholders::_2));

    registerEntities();

    RCLCPP_INFO(node_->get_logger(), "WorldBridgeDriver initialized.");
  }
  void WorldBridgeDriver::registerEntities(){
    robots_["CAR"] = {"CAR", wb_supervisor_node_get_from_def("CAR")};

    objects_["CUP"] = {"CUP", "CUP", false, true, wb_supervisor_node_get_from_def("CUP")};
    objects_["TABLE"] = {"TABLE","TABLE", true, false, wb_supervisor_node_get_from_def("TABLE")};
  }
  std::string WorldBridgeDriver::inferSupportName(
    const ObjectEntry & object,
    const double * object_pos)
  {
    for (const auto & kv : objects_) {
      if (!kv.second.is_support || !kv.second.node) {
        continue;
      }
      const auto& candidate = kv.second;
      const double * support_pos = wb_supervisor_node_get_position(candidate.node);
      if (!support_pos) {
        continue;
      }

      if (isOnSupport(object, object_pos, candidate, support_pos)) {
        return candidate.name;
      }
    }
    return "";
  }
  bool WorldBridgeDriver::isHeldByAnyRobot(const std::string & object_name) const
  {
    for (const auto & kv : carried_by_robot_) {
      if (kv.second == object_name) {
        return true;
      }
    }
    return false;
  }

  std::string WorldBridgeDriver::holderRobotName(const std::string & object_name) const
  {
    for (const auto & kv : carried_by_robot_) {
      if (kv.second == object_name) {
        return kv.first;
      }
    }
    return "";
  }
  ObjectEntry* WorldBridgeDriver::findObject(const std::string& name){
    return objects_.find(name) == objects_.end() ? nullptr: &objects_[name];
  }
  RobotEntry* WorldBridgeDriver::findRobot(const std::string& name){
    return robots_.find(name) == robots_.end() ? nullptr: &robots_[name];
  }
  bool WorldBridgeDriver::isNear(const double* a_pos, const double* b_pos, double threshold) const {
    return dist2d(a_pos, b_pos) <= threshold;
  }
  void WorldBridgeDriver::disablePhysics(WbNodeRef node)
  {
    if (!node) {
      return;
    }
    WbFieldRef physics_field = wb_supervisor_node_get_field(node, "physics");
    if (physics_field) {
      wb_supervisor_field_remove_sf(physics_field);
    }
  }

  void WorldBridgeDriver::enablePhysics(WbNodeRef node)
  {
    if (!node) {
      return;
    }
    WbFieldRef physics_field = wb_supervisor_node_get_field(node, "physics");
    if (physics_field) {
      wb_supervisor_field_import_sf_node_from_string(physics_field, "Physics { }");
    }
  }
  
  bool WorldBridgeDriver::isOnSupport(
    const ObjectEntry & object,
    const double * object_pos,
    const ObjectEntry & support,
    const double * support_pos) const
  {
    if (!object_pos || !support_pos || !object.node || !support.node) {
      return false;
    }

    // 当前版本只支持：support 是 Box，object 是 Cylinder
    double support_size[3];
    if (!getBoxSizeFromSolid(support.node, support_size)) {
      return false;
    }

    double object_height = 0.0;
    if (!getCylinderHeightFromSolid(object.node, object_height)) {
      return false;
    }

    // support 顶面高度
    const double support_top_z = support_pos[2] + support_size[2] / 2.0;

    // object 底面高度
    const double object_bottom_z = object_pos[2] - object_height / 2.0;

    // 1) 高度接近：允许一点容差
    constexpr double kHeightTolerance = 0.03;
    const bool height_ok =
      std::abs(object_bottom_z - support_top_z) <= kHeightTolerance;

    if (!height_ok) {
      return false;
    }

    // 2) 水平投影在 support 顶面范围内
    // 先简单按 support 中心矩形判断，留一点 margin
    const double half_x = support_size[0] / 2.0;
    const double half_y = support_size[1] / 2.0;

    constexpr double kInsideMargin = 0.01;

    const bool inside_x =
      object_pos[0] >= support_pos[0] - half_x - kInsideMargin &&
      object_pos[0] <= support_pos[0] + half_x + kInsideMargin;

    const bool inside_y =
      object_pos[1] >= support_pos[1] - half_y - kInsideMargin &&
      object_pos[1] <= support_pos[1] + half_y + kInsideMargin;

    return inside_x && inside_y;
  }

  void WorldBridgeDriver::updateCachedState()
  {
    cached_state_.robots.clear();
    cached_state_.objects.clear();

    // 1. robots
    for (const auto & kv : robots_) {
      const auto robot = kv.second;
      if (!robot.node) {
        continue;
      }

      const double * pos = wb_supervisor_node_get_position(robot.node);
      const double * rot = wb_supervisor_node_get_orientation(robot.node);
      if (!pos || !rot) {
        continue;
      }

      rtdl_demo_interfaces::msg::RobotState robot_msg;
      robot_msg.name = robot.name;
      robot_msg.x = pos[0];
      robot_msg.y = pos[1];
      robot_msg.z = pos[2];
      robot_msg.yaw = yawFromOrientation(rot);

      auto it = carried_by_robot_.find(robot.name);
      robot_msg.held_object_name = (it == carried_by_robot_.end()) ? "" : it->second;
      cached_state_.robots.push_back(robot_msg);
    }

    // 2. objects
    for (const auto & kv : objects_) {
      const auto object = kv.second;
      if (!object.node) {
        continue;
      }

      const double * pos = wb_supervisor_node_get_position(object.node);
      if (!pos) {
        continue;
      }

      rtdl_demo_interfaces::msg::ObjectState object_msg;
      object_msg.name = object.name;
      object_msg.type = object.type;
      object_msg.x = pos[0];
      object_msg.y = pos[1];
      object_msg.z = pos[2];

      object_msg.held_by_robot = isHeldByAnyRobot(object.name);
      object_msg.holder_robot_name = holderRobotName(object.name);

      if (object_msg.held_by_robot) {
        object_msg.support_name = "";
      } else {
        object_msg.support_name = inferSupportName(object, pos);
      }

      cached_state_.objects.push_back(object_msg);
    }
  }

  void WorldBridgeDriver::handleGetWorldState(
      const std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState::Request> req,
      std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState::Response> res)
  {
    res->success = true;
    res->message = "Real Webots world state queried successfully.";
    res->state = cached_state_;
  }

  void WorldBridgeDriver::handlePickPri(
  const std::shared_ptr<rtdl_demo_interfaces::srv::PickPri::Request> req,
  std::shared_ptr<rtdl_demo_interfaces::srv::PickPri::Response> res)
  {
    const std::string robot_name = req->robot_name;
    const std::string object_name = req->object_name;
    constexpr double kPickDistanceThreshold = 0.5;

    auto robot_it = robots_.find(robot_name);
    if (robot_it == robots_.end() || !robot_it->second.node) {
      res->success = false;
      res->message = "Robot " + robot_name + " does not exist.";
      return;
    }

    auto object_it = objects_.find(object_name);
    if (object_it == objects_.end() || !object_it->second.node) {
      res->success = false;
      res->message = "Object " + object_name + " does not exist.";
      return;
    }

    auto & robot = robot_it->second;
    auto & object = object_it->second;

    if (!object.is_pickable) {
      res->success = false;
      res->message = "Object " + object_name + " is not pickable.";
      return;
    }

    auto carry_it = carried_by_robot_.find(robot_name);
    if (carry_it != carried_by_robot_.end() && !carry_it->second.empty()) {
      res->success = false;
      res->message = "Robot " + robot_name + " is already holding " + carry_it->second + ".";
      return;
    }

    if (isHeldByAnyRobot(object_name)) {
      res->success = false;
      res->message =
        "Object " + object_name + " is already held by robot " + holderRobotName(object_name) + ".";
      return;
    }

    const double * robot_pos = wb_supervisor_node_get_position(robot.node);
    const double * object_pos = wb_supervisor_node_get_position(object.node);

    if (!robot_pos || !object_pos) {
      res->success = false;
      res->message = "Failed to read robot/object positions.";
      return;
    }

    if (!isNear(robot_pos, object_pos, kPickDistanceThreshold)) {
      res->success = false;
      res->message = "Object " + object_name + " is too far from robot " + robot_name + ".";
      return;
    }

    disablePhysics(object.node);
    carried_by_robot_[robot_name] = object_name;

    res->success = true;
    res->message = "Pick object " + object_name + " successfully.";
  }

  void WorldBridgeDriver::handlePlacePri(
  const std::shared_ptr<rtdl_demo_interfaces::srv::PlacePri::Request> req,
  std::shared_ptr<rtdl_demo_interfaces::srv::PlacePri::Response> res)
  {
    const std::string robot_name = req->robot_name;
    const std::string object_name = req->object_name;
    const std::string support_name = req->location_name;
    constexpr double kPlaceDistanceThreshold = 2;
    constexpr double kEpsilon = 0.005;

    auto robot_it = robots_.find(robot_name);
    if (robot_it == robots_.end() || !robot_it->second.node) {
      res->success = false;
      res->message = "Robot " + robot_name + " does not exist.";
      return;
    }

    auto object_it = objects_.find(object_name);
    if (object_it == objects_.end() || !object_it->second.node) {
      res->success = false;
      res->message = "Object " + object_name + " does not exist.";
      return;
    }

    auto support_it = objects_.find(support_name);
    if (support_it == objects_.end() || !support_it->second.node) {
      res->success = false;
      res->message = "Support " + support_name + " does not exist.";
      return;
    }

    auto & robot = robot_it->second;
    auto & object = object_it->second;
    auto & support = support_it->second;

    if (!support.is_support) {
      res->success = false;
      res->message = support_name + " is not a support object.";
      return;
    }

    auto carry_it = carried_by_robot_.find(robot_name);
    if (carry_it == carried_by_robot_.end() || carry_it->second != object_name) {
      res->success = false;
      res->message = "Robot " + robot_name + " is not holding object " + object_name + ".";
      return;
    }

    const double * robot_pos = wb_supervisor_node_get_position(robot.node);
    const double * support_pos = wb_supervisor_node_get_position(support.node);

    if (!robot_pos || !support_pos) {
      res->success = false;
      res->message = "Failed to read robot/support positions.";
      return;
    }

    if (!isNear(robot_pos, support_pos, kPlaceDistanceThreshold)) {
      res->success = false;
      res->message = "Support " + support_name + " is too far from robot " + robot_name + ".";
      return;
    }

    double support_size[3];
    if (!getBoxSizeFromSolid(support.node, support_size)) {
      res->success = false;
      res->message = "Failed to read support size for " + support_name + ".";
      return;
    }

    double object_height = 0.0;
    if (!getCylinderHeightFromSolid(object.node, object_height)) {
      res->success = false;
      res->message = "Failed to read object height for " + object_name + ".";
      return;
    }

    double place_pos[3];
    place_pos[0] = support_pos[0];
    place_pos[1] = support_pos[1];
    place_pos[2] = support_pos[2] + support_size[2] / 2.0 + object_height / 2.0 + kEpsilon;

    WbFieldRef translation_field = wb_supervisor_node_get_field(object.node, "translation");
    if (!translation_field) {
      res->success = false;
      res->message = "Failed to access translation field for object " + object_name + ".";
      return;
    }

    wb_supervisor_field_set_sf_vec3f(translation_field, place_pos);
    enablePhysics(object.node);
    carried_by_robot_[robot_name].clear();

    res->success = true;
    res->message =
      "Place object " + object_name + " on support " + support_name + " successfully.";
  }
  void WorldBridgeDriver::step()
  {
    for (const auto & kv : carried_by_robot_) {
      const std::string & robot_name = kv.first;
      const std::string & object_name = kv.second;

      if (object_name.empty()) {
        continue;
      }

      auto robot_it = robots_.find(robot_name);
      auto object_it = objects_.find(object_name);

      if (robot_it == robots_.end() || object_it == objects_.end()) {
        continue;
      }
      if (!robot_it->second.node || !object_it->second.node) {
        continue;
      }

      const double * robot_pos = wb_supervisor_node_get_position(robot_it->second.node);
      const double * robot_rot = wb_supervisor_node_get_orientation(robot_it->second.node);
      if (!robot_pos || !robot_rot) {
        continue;
      }

      const double yaw = yawFromOrientation(robot_rot);

      double new_pos[3];
      new_pos[0] = robot_pos[0] + 0.08 * std::cos(yaw);
      new_pos[1] = robot_pos[1] + 0.08 * std::sin(yaw);
      new_pos[2] = 0.5;

      WbFieldRef translation_field =
        wb_supervisor_node_get_field(object_it->second.node, "translation");
      if (translation_field) {
        wb_supervisor_field_set_sf_vec3f(translation_field, new_pos);
      }
    }

    updateCachedState();
  }

  bool WorldBridgeDriver::getBoxSizeFromSolid(WbNodeRef solid_node, double size_out[3]) const{
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

  bool WorldBridgeDriver::getCylinderHeightFromSolid(WbNodeRef solid_node, double &height_out) const {
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
}
PLUGINLIB_EXPORT_CLASS(
    rtdl_demo_webots::WorldBridgeDriver,
    webots_ros2_driver::PluginInterface)