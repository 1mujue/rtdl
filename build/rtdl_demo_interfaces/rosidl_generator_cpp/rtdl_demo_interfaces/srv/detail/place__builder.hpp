// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rtdl_demo_interfaces:srv/Place.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__SRV__DETAIL__PLACE__BUILDER_HPP_
#define RTDL_DEMO_INTERFACES__SRV__DETAIL__PLACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rtdl_demo_interfaces/srv/detail/place__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rtdl_demo_interfaces
{

namespace srv
{

namespace builder
{

class Init_Place_Request_location_name
{
public:
  explicit Init_Place_Request_location_name(::rtdl_demo_interfaces::srv::Place_Request & msg)
  : msg_(msg)
  {}
  ::rtdl_demo_interfaces::srv::Place_Request location_name(::rtdl_demo_interfaces::srv::Place_Request::_location_name_type arg)
  {
    msg_.location_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rtdl_demo_interfaces::srv::Place_Request msg_;
};

class Init_Place_Request_object_name
{
public:
  Init_Place_Request_object_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Place_Request_location_name object_name(::rtdl_demo_interfaces::srv::Place_Request::_object_name_type arg)
  {
    msg_.object_name = std::move(arg);
    return Init_Place_Request_location_name(msg_);
  }

private:
  ::rtdl_demo_interfaces::srv::Place_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rtdl_demo_interfaces::srv::Place_Request>()
{
  return rtdl_demo_interfaces::srv::builder::Init_Place_Request_object_name();
}

}  // namespace rtdl_demo_interfaces


namespace rtdl_demo_interfaces
{

namespace srv
{

namespace builder
{

class Init_Place_Response_message
{
public:
  explicit Init_Place_Response_message(::rtdl_demo_interfaces::srv::Place_Response & msg)
  : msg_(msg)
  {}
  ::rtdl_demo_interfaces::srv::Place_Response message(::rtdl_demo_interfaces::srv::Place_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rtdl_demo_interfaces::srv::Place_Response msg_;
};

class Init_Place_Response_success
{
public:
  Init_Place_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Place_Response_message success(::rtdl_demo_interfaces::srv::Place_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Place_Response_message(msg_);
  }

private:
  ::rtdl_demo_interfaces::srv::Place_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rtdl_demo_interfaces::srv::Place_Response>()
{
  return rtdl_demo_interfaces::srv::builder::Init_Place_Response_success();
}

}  // namespace rtdl_demo_interfaces

#endif  // RTDL_DEMO_INTERFACES__SRV__DETAIL__PLACE__BUILDER_HPP_
