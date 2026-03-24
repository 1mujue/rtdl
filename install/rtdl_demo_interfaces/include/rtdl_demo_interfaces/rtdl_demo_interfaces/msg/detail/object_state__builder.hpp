// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rtdl_demo_interfaces:msg/ObjectState.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__MSG__DETAIL__OBJECT_STATE__BUILDER_HPP_
#define RTDL_DEMO_INTERFACES__MSG__DETAIL__OBJECT_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rtdl_demo_interfaces/msg/detail/object_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rtdl_demo_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObjectState_held_by_robot
{
public:
  explicit Init_ObjectState_held_by_robot(::rtdl_demo_interfaces::msg::ObjectState & msg)
  : msg_(msg)
  {}
  ::rtdl_demo_interfaces::msg::ObjectState held_by_robot(::rtdl_demo_interfaces::msg::ObjectState::_held_by_robot_type arg)
  {
    msg_.held_by_robot = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rtdl_demo_interfaces::msg::ObjectState msg_;
};

class Init_ObjectState_support
{
public:
  explicit Init_ObjectState_support(::rtdl_demo_interfaces::msg::ObjectState & msg)
  : msg_(msg)
  {}
  Init_ObjectState_held_by_robot support(::rtdl_demo_interfaces::msg::ObjectState::_support_type arg)
  {
    msg_.support = std::move(arg);
    return Init_ObjectState_held_by_robot(msg_);
  }

private:
  ::rtdl_demo_interfaces::msg::ObjectState msg_;
};

class Init_ObjectState_room
{
public:
  explicit Init_ObjectState_room(::rtdl_demo_interfaces::msg::ObjectState & msg)
  : msg_(msg)
  {}
  Init_ObjectState_support room(::rtdl_demo_interfaces::msg::ObjectState::_room_type arg)
  {
    msg_.room = std::move(arg);
    return Init_ObjectState_support(msg_);
  }

private:
  ::rtdl_demo_interfaces::msg::ObjectState msg_;
};

class Init_ObjectState_name
{
public:
  Init_ObjectState_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectState_room name(::rtdl_demo_interfaces::msg::ObjectState::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ObjectState_room(msg_);
  }

private:
  ::rtdl_demo_interfaces::msg::ObjectState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rtdl_demo_interfaces::msg::ObjectState>()
{
  return rtdl_demo_interfaces::msg::builder::Init_ObjectState_name();
}

}  // namespace rtdl_demo_interfaces

#endif  // RTDL_DEMO_INTERFACES__MSG__DETAIL__OBJECT_STATE__BUILDER_HPP_
