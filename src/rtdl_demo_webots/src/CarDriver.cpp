#include "rtdl_demo_webots/CarDriver.hpp"

#include <cmath>
#include <functional>
#include <stdexcept>

#include <webots/motor.h>
#include <webots/robot.h>

#include <pluginlib/class_list_macros.hpp>

namespace rtdl_demo_webots
{

namespace
{
constexpr double kHalfWheelDistance = 0.06;
constexpr double kWheelRadius = 0.04;
}  // namespace

void CarDriver::init(
  webots_ros2_driver::WebotsNode * node,
  std::unordered_map<std::string, std::string> & /*parameters*/)
{
  left_front_ = wb_robot_get_device("rm_wheel1");
  right_front_ = wb_robot_get_device("rm_wheel2");
  left_rear_ = wb_robot_get_device("rm_wheel3");
  right_rear_ = wb_robot_get_device("rm_wheel4");

  if (!left_front_ || !right_front_ || !left_rear_ || !right_rear_) {
    throw std::runtime_error("Failed to get one or more motors: rm_wheel1/2/3/4");
  }

  wb_motor_set_position(left_front_, INFINITY);
  wb_motor_set_position(right_front_, INFINITY);
  wb_motor_set_position(left_rear_, INFINITY);
  wb_motor_set_position(right_rear_, INFINITY);

  wb_motor_set_velocity(left_front_, 0.0);
  wb_motor_set_velocity(right_front_, 0.0);
  wb_motor_set_velocity(left_rear_, 0.0);
  wb_motor_set_velocity(right_rear_, 0.0);

  cmd_vel_subscription_ = node->create_subscription<geometry_msgs::msg::Twist>(
    "/cmd_vel",
    rclcpp::SensorDataQoS().reliable(),
    std::bind(&CarDriver::cmdVelCallback, this, std::placeholders::_1));
  
  RCLCPP_INFO(node->get_logger(), "CarDriver initialized.");
}

void CarDriver::cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
{
  cmd_vel_msg_.linear = msg->linear;
  cmd_vel_msg_.angular = msg->angular;

  RCLCPP_INFO(
  rclcpp::get_logger("CarDriver"),
  "cmd_vel received: linear.x=%.3f angular.z=%.3f",
  msg->linear.x, msg->angular.z);
}

void CarDriver::step()
{
  const double forward_speed = cmd_vel_msg_.linear.x;
  const double angular_speed = cmd_vel_msg_.angular.z;

  const double left =
    (forward_speed - angular_speed * kHalfWheelDistance) / kWheelRadius;
  const double right =
    (forward_speed + angular_speed * kHalfWheelDistance) / kWheelRadius;

  wb_motor_set_velocity(left_front_, left);
  wb_motor_set_velocity(left_rear_, left);
  wb_motor_set_velocity(right_front_, right);
  wb_motor_set_velocity(right_rear_, right);
}

}  // namespace rtdl_demo_webots

PLUGINLIB_EXPORT_CLASS(rtdl_demo_webots::CarDriver, webots_ros2_driver::PluginInterface)