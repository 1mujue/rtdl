#pragma once

#include <string>
#include <unordered_map>

#include <geometry_msgs/msg/twist.hpp>
#include <rclcpp/rclcpp.hpp>

#include <webots/types.h>
#include <webots_ros2_driver/PluginInterface.hpp>
#include <webots_ros2_driver/WebotsNode.hpp>

namespace rtdl_demo_webots
{

class CarDriver : public webots_ros2_driver::PluginInterface
{
public:
  void init(
    webots_ros2_driver::WebotsNode * node,
    std::unordered_map<std::string, std::string> & parameters) override;

  void step() override;

private:
  void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);

  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_subscription_;
  geometry_msgs::msg::Twist cmd_vel_msg_{};

  WbDeviceTag left_front_;
  WbDeviceTag right_front_;
  WbDeviceTag left_rear_;
  WbDeviceTag right_rear_;
};

}  // namespace rtdl_demo_webots