// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from rtdl_demo_interfaces:msg/WorldState.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rtdl_demo_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "rtdl_demo_interfaces/msg/detail/world_state__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace rtdl_demo_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rtdl_demo_interfaces
cdr_serialize(
  const rtdl_demo_interfaces::msg::WorldState & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rtdl_demo_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rtdl_demo_interfaces::msg::WorldState & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rtdl_demo_interfaces
get_serialized_size(
  const rtdl_demo_interfaces::msg::WorldState & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rtdl_demo_interfaces
max_serialized_size_WorldState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rtdl_demo_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rtdl_demo_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rtdl_demo_interfaces, msg, WorldState)();

#ifdef __cplusplus
}
#endif

#endif  // RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
