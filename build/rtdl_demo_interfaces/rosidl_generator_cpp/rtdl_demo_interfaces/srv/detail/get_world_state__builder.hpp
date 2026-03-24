// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rtdl_demo_interfaces:srv/GetWorldState.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__SRV__DETAIL__GET_WORLD_STATE__BUILDER_HPP_
#define RTDL_DEMO_INTERFACES__SRV__DETAIL__GET_WORLD_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rtdl_demo_interfaces/srv/detail/get_world_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rtdl_demo_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rtdl_demo_interfaces::srv::GetWorldState_Request>()
{
  return ::rtdl_demo_interfaces::srv::GetWorldState_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace rtdl_demo_interfaces


namespace rtdl_demo_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetWorldState_Response_state
{
public:
  explicit Init_GetWorldState_Response_state(::rtdl_demo_interfaces::srv::GetWorldState_Response & msg)
  : msg_(msg)
  {}
  ::rtdl_demo_interfaces::srv::GetWorldState_Response state(::rtdl_demo_interfaces::srv::GetWorldState_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rtdl_demo_interfaces::srv::GetWorldState_Response msg_;
};

class Init_GetWorldState_Response_message
{
public:
  explicit Init_GetWorldState_Response_message(::rtdl_demo_interfaces::srv::GetWorldState_Response & msg)
  : msg_(msg)
  {}
  Init_GetWorldState_Response_state message(::rtdl_demo_interfaces::srv::GetWorldState_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GetWorldState_Response_state(msg_);
  }

private:
  ::rtdl_demo_interfaces::srv::GetWorldState_Response msg_;
};

class Init_GetWorldState_Response_success
{
public:
  Init_GetWorldState_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetWorldState_Response_message success(::rtdl_demo_interfaces::srv::GetWorldState_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetWorldState_Response_message(msg_);
  }

private:
  ::rtdl_demo_interfaces::srv::GetWorldState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rtdl_demo_interfaces::srv::GetWorldState_Response>()
{
  return rtdl_demo_interfaces::srv::builder::Init_GetWorldState_Response_success();
}

}  // namespace rtdl_demo_interfaces

#endif  // RTDL_DEMO_INTERFACES__SRV__DETAIL__GET_WORLD_STATE__BUILDER_HPP_
