// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rtdl_demo_interfaces:srv/CheckObjectInRoom.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__SRV__DETAIL__CHECK_OBJECT_IN_ROOM__BUILDER_HPP_
#define RTDL_DEMO_INTERFACES__SRV__DETAIL__CHECK_OBJECT_IN_ROOM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rtdl_demo_interfaces/srv/detail/check_object_in_room__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rtdl_demo_interfaces
{

namespace srv
{

namespace builder
{

class Init_CheckObjectInRoom_Request_room_name
{
public:
  explicit Init_CheckObjectInRoom_Request_room_name(::rtdl_demo_interfaces::srv::CheckObjectInRoom_Request & msg)
  : msg_(msg)
  {}
  ::rtdl_demo_interfaces::srv::CheckObjectInRoom_Request room_name(::rtdl_demo_interfaces::srv::CheckObjectInRoom_Request::_room_name_type arg)
  {
    msg_.room_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rtdl_demo_interfaces::srv::CheckObjectInRoom_Request msg_;
};

class Init_CheckObjectInRoom_Request_object_name
{
public:
  Init_CheckObjectInRoom_Request_object_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CheckObjectInRoom_Request_room_name object_name(::rtdl_demo_interfaces::srv::CheckObjectInRoom_Request::_object_name_type arg)
  {
    msg_.object_name = std::move(arg);
    return Init_CheckObjectInRoom_Request_room_name(msg_);
  }

private:
  ::rtdl_demo_interfaces::srv::CheckObjectInRoom_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rtdl_demo_interfaces::srv::CheckObjectInRoom_Request>()
{
  return rtdl_demo_interfaces::srv::builder::Init_CheckObjectInRoom_Request_object_name();
}

}  // namespace rtdl_demo_interfaces


namespace rtdl_demo_interfaces
{

namespace srv
{

namespace builder
{

class Init_CheckObjectInRoom_Response_found
{
public:
  explicit Init_CheckObjectInRoom_Response_found(::rtdl_demo_interfaces::srv::CheckObjectInRoom_Response & msg)
  : msg_(msg)
  {}
  ::rtdl_demo_interfaces::srv::CheckObjectInRoom_Response found(::rtdl_demo_interfaces::srv::CheckObjectInRoom_Response::_found_type arg)
  {
    msg_.found = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rtdl_demo_interfaces::srv::CheckObjectInRoom_Response msg_;
};

class Init_CheckObjectInRoom_Response_message
{
public:
  explicit Init_CheckObjectInRoom_Response_message(::rtdl_demo_interfaces::srv::CheckObjectInRoom_Response & msg)
  : msg_(msg)
  {}
  Init_CheckObjectInRoom_Response_found message(::rtdl_demo_interfaces::srv::CheckObjectInRoom_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_CheckObjectInRoom_Response_found(msg_);
  }

private:
  ::rtdl_demo_interfaces::srv::CheckObjectInRoom_Response msg_;
};

class Init_CheckObjectInRoom_Response_success
{
public:
  Init_CheckObjectInRoom_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CheckObjectInRoom_Response_message success(::rtdl_demo_interfaces::srv::CheckObjectInRoom_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_CheckObjectInRoom_Response_message(msg_);
  }

private:
  ::rtdl_demo_interfaces::srv::CheckObjectInRoom_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::rtdl_demo_interfaces::srv::CheckObjectInRoom_Response>()
{
  return rtdl_demo_interfaces::srv::builder::Init_CheckObjectInRoom_Response_success();
}

}  // namespace rtdl_demo_interfaces

#endif  // RTDL_DEMO_INTERFACES__SRV__DETAIL__CHECK_OBJECT_IN_ROOM__BUILDER_HPP_
