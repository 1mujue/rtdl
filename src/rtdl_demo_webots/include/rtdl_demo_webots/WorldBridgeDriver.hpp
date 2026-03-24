#pragma once

#include <string>
#include <unordered_map>

#include <rclcpp/rclcpp.hpp>

#include <webots/types.h>
#include <webots_ros2_driver/PluginInterface.hpp>
#include <webots_ros2_driver/WebotsNode.hpp>

#include "rtdl_demo_interfaces/srv/get_world_state.hpp"
#include "rtdl_demo_interfaces/srv/pick_pri.hpp"
#include "rtdl_demo_interfaces/srv/place_pri.hpp"

namespace rtdl_demo_webots{
class WorldBridgeDriver: public webots_ros2_driver::PluginInterface{
public:
    void init(
        webots_ros2_driver::WebotsNode* node,
        std::unordered_map<std::string, std::string>& properties
    ) override;
    void step() override;
private:
    struct CachedState{
        std::string robot_room;
        std::string holding_object;

        double robot_x{0.0};
        double robot_y{0.0};
        double robot_yaw{0.0};

        std::string cup_room;
        std::string cup_support;
    };
    static std::string roomOf(double x, double y); 
    static double dist2d(const double * a, const double * b);
    static std::string supportOfCup(const double * cup_pos, const double * table_pos);
    static double yawFromOrientation(const double* rot3x3);
    bool isObjNearCar(const double*, const double*);

    void updateCachedState();

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

    WbNodeRef car_node_{0};
    WbNodeRef cup_node_{0};
    WbNodeRef table_node_{0};

    CachedState cached_state_{};
    std::string carried_object_;

    rclcpp::Service<rtdl_demo_interfaces::srv::GetWorldState>::SharedPtr get_world_state_srv_;
    rclcpp::Service<rtdl_demo_interfaces::srv::PickPri>::SharedPtr pick_pri_srv_;
    rclcpp::Service<rtdl_demo_interfaces::srv::PlacePri>::SharedPtr place_pri_srv_;
};
}