// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rtdl_demo_interfaces:msg/WorldState.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__BUILDER_HPP_
#define RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rtdl_demo_interfaces/msg/detail/world_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rtdl_demo_interfaces
{

namespace msg
{

namespace builder
{

class Init_WorldState_objects
{
public:
  explicit Init_WorldState_objects(::rtdl_demo_interfaces::msg::WorldState & msg)
  : msg_(msg)
  {}
  ::rtdl_demo_interfaces::msg::WorldState objects(::rtdl_demo_interfaces::msg::WorldState::_objects_type arg)
  {
    msg_.objects = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rtdl_demo_interfaces::msg::WorldState msg_;
};

class Init_WorldState_robot_yaw
{
public:
  explicit Init_WorldState_robot_yaw(::rtdl_demo_interfaces::msg::WorldState & msg)
  : msg_(msg)
  {}
  Init_WorldState_objects robot_yaw(::rtdl_demo_interfaces::msg::WorldState::_robot_yaw_type arg)
  {
    msg_.robot_yaw = std::move(arg);
    return Init_WorldState_objects(msg_);
  }

private:
  ::rtdl_demo_interfaces::msg::WorldState msg_;
};

class Init_WorldState_robot_y
{
public:
  explicit Init_WorldState_robot_y(::rtdl_demo_interfaces::msg::WorldState & msg)
  : msg_(msg)
  {}
  Init_WorldState_robot_yaw robot_y(::rtdl_demo_interfaces::msg::WorldState::_robot_y_type arg)
  {
    msg_.robot_y = std::move(arg);
    return Init_WorldState_robot_yaw(msg_);
  }

private:
  ::rtdl_demo_interfaces::msg::WorldState msg_;
};

class Init_WorldState_robot_x
{
public:
  explicit Init_WorldState_robot_x(::rtdl_demo_interfaces::msg::WorldState & msg)
  : msg_(msg)
  {}
  Init_WorldState_robot_y robot_x(::rtdl_demo_interfaces::msg::WorldState::_robot_x_type arg)
  {
    msg_.robot_x = std::move(arg);
    return Init_WorldState_robot_y(msg_);
  }

private:
  ::rtdl_demo_interfaces::msg::WorldState msg_;
};

class Init_WorldState_holding_object
{
public:
  explicit Init_WorldState_holding_object(::rtdl_demo_interfaces::msg::WorldState & msg)
  : msg_(msg)
  {}
  Init_WorldState_robot_x holding_object(::rtdl_demo_interfaces::msg::WorldState::_holding_object_type arg)
  {
    msg_.holding_object = std::move(arg);
    return Init_WorldState_robot_x(msg_);
  }

private:
  ::rtdl_demo_interfaces::msg::WorldState msg_;
};

class Init_WorldState_robot_room
{
public:
  Init_WorldState_robot_room()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WorldState_holding_object robot_room(::rtdl_demo_interfaces::msg::WorldState::_robot_room_type arg)
  {
    msg_.robot_room = std::move(arg);
    return Init_WorldState_holding_object(msg_);
  }

private:
  ::rtdl_demo_interfaces::msg::WorldState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rtdl_demo_interfaces::msg::WorldState>()
{
  return rtdl_demo_interfaces::msg::builder::Init_WorldState_robot_room();
}

}  // namespace rtdl_demo_interfaces

#endif  // RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__BUILDER_HPP_
