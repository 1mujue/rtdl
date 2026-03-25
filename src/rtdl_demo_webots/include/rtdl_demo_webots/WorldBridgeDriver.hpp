#pragma once

#include <string>
#include <unordered_map>

#include <rclcpp/rclcpp.hpp>

#include <webots/types.h>
#include <webots_ros2_driver/PluginInterface.hpp>
#include <webots_ros2_driver/WebotsNode.hpp>

#include "rtdl_demo_interfaces/msg/robot_state.hpp"
#include "rtdl_demo_interfaces/msg/object_state.hpp"
#include "rtdl_demo_interfaces/msg/world_state.hpp"
#include "rtdl_demo_interfaces/srv/get_world_state.hpp"
#include "rtdl_demo_interfaces/srv/pick_pri.hpp"
#include "rtdl_demo_interfaces/srv/place_pri.hpp"

struct RobotEntry{
    std::string name;
    WbNodeRef node{0};
};
struct ObjectEntry{
    std::string name;
    std::string type;
    bool is_support{false};
    bool is_pickable{false};
    WbNodeRef node{0};
};

namespace rtdl_demo_webots{
class WorldBridgeDriver: public webots_ros2_driver::PluginInterface{
public:
    void init(
        webots_ros2_driver::WebotsNode* node,
        std::unordered_map<std::string, std::string>& properties
    ) override;
    void step() override;
private:
    void updateCachedState();
    void registerEntities();
    std::string inferSupportName(const ObjectEntry& o, const double* object_pos);
    bool isHeldByAnyRobot(const std::string& obj_name) const ;
    std::string holderRobotName(const std::string& obj_name) const;
    ObjectEntry* findObject(const std::string& name);
    RobotEntry* findRobot(const std::string& name);
    bool isNear(const double* a_pos, const double* b_pos, double threshold) const ;
    void enablePhysics(WbNodeRef ref);
    void disablePhysics(WbNodeRef ref);
    bool getBoxSizeFromSolid(WbNodeRef solid_node, double size_out[3]) const ;
    bool getCylinderHeightFromSolid(WbNodeRef solid_node, double &height_out) const ;
    bool isOnSupport(
    const ObjectEntry & object,
    const double * object_pos,
    const ObjectEntry & support,
    const double * support_pos) const;
    void handleGetWorldState(
        const std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState::Request> req,
        std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState::Response> res
    );
    void handlePickPri(
        const std::shared_ptr<rtdl_demo_interfaces::srv::PickPri::Request> req,
        std::shared_ptr<rtdl_demo_interfaces::srv::PickPri::Response> res
    );
    void handlePlacePri(
        const std::shared_ptr<rtdl_demo_interfaces::srv::PlacePri::Request> req,
        std::shared_ptr<rtdl_demo_interfaces::srv::PlacePri::Response> res
    );

    webots_ros2_driver::WebotsNode* node_{nullptr};

    std::unordered_map<std::string, RobotEntry> robots_;
    std::unordered_map<std::string, ObjectEntry> objects_;
    std::unordered_map<std::string, std::string> carried_by_robot_;

    rtdl_demo_interfaces::msg::WorldState cached_state_{};

    rclcpp::Service<rtdl_demo_interfaces::srv::GetWorldState>::SharedPtr get_world_state_srv_;
    rclcpp::Service<rtdl_demo_interfaces::srv::PickPri>::SharedPtr pick_pri_srv_;
    rclcpp::Service<rtdl_demo_interfaces::srv::PlacePri>::SharedPtr place_pri_srv_;

    const std::string kMainRobotName = "CAR";
};
}