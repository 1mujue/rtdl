// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rtdl_demo_interfaces:msg/ObjectState.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__MSG__DETAIL__OBJECT_STATE__TRAITS_HPP_
#define RTDL_DEMO_INTERFACES__MSG__DETAIL__OBJECT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rtdl_demo_interfaces/msg/detail/object_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rtdl_demo_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjectState & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: room
  {
    out << "room: ";
    rosidl_generator_traits::value_to_yaml(msg.room, out);
    out << ", ";
  }

  // member: support
  {
    out << "support: ";
    rosidl_generator_traits::value_to_yaml(msg.support, out);
    out << ", ";
  }

  // member: held_by_robot
  {
    out << "held_by_robot: ";
    rosidl_generator_traits::value_to_yaml(msg.held_by_robot, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: room
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "room: ";
    rosidl_generator_traits::value_to_yaml(msg.room, out);
    out << "\n";
  }

  // member: support
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "support: ";
    rosidl_generator_traits::value_to_yaml(msg.support, out);
    out << "\n";
  }

  // member: held_by_robot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "held_by_robot: ";
    rosidl_generator_traits::value_to_yaml(msg.held_by_robot, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rtdl_demo_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rtdl_demo_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rtdl_demo_interfaces::msg::ObjectState & msg,
  std::ostream & out, size_t indentation = 0)
{
  rtdl_demo_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rtdl_demo_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rtdl_demo_interfaces::msg::ObjectState & msg)
{
  return rtdl_demo_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rtdl_demo_interfaces::msg::ObjectState>()
{
  return "rtdl_demo_interfaces::msg::ObjectState";
}

template<>
inline const char * name<rtdl_demo_interfaces::msg::ObjectState>()
{
  return "rtdl_demo_interfaces/msg/ObjectState";
}

template<>
struct has_fixed_size<rtdl_demo_interfaces::msg::ObjectState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rtdl_demo_interfaces::msg::ObjectState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rtdl_demo_interfaces::msg::ObjectState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RTDL_DEMO_INTERFACES__MSG__DETAIL__OBJECT_STATE__TRAITS_HPP_
