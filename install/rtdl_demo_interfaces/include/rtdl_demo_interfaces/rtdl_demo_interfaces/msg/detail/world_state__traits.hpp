// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rtdl_demo_interfaces:msg/WorldState.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__TRAITS_HPP_
#define RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rtdl_demo_interfaces/msg/detail/world_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'objects'
#include "rtdl_demo_interfaces/msg/detail/object_state__traits.hpp"

namespace rtdl_demo_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const WorldState & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_room
  {
    out << "robot_room: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_room, out);
    out << ", ";
  }

  // member: holding_object
  {
    out << "holding_object: ";
    rosidl_generator_traits::value_to_yaml(msg.holding_object, out);
    out << ", ";
  }

  // member: robot_x
  {
    out << "robot_x: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_x, out);
    out << ", ";
  }

  // member: robot_y
  {
    out << "robot_y: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_y, out);
    out << ", ";
  }

  // member: robot_yaw
  {
    out << "robot_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_yaw, out);
    out << ", ";
  }

  // member: objects
  {
    if (msg.objects.size() == 0) {
      out << "objects: []";
    } else {
      out << "objects: [";
      size_t pending_items = msg.objects.size();
      for (auto item : msg.objects) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const WorldState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_room
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_room: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_room, out);
    out << "\n";
  }

  // member: holding_object
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "holding_object: ";
    rosidl_generator_traits::value_to_yaml(msg.holding_object, out);
    out << "\n";
  }

  // member: robot_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_x: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_x, out);
    out << "\n";
  }

  // member: robot_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_y: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_y, out);
    out << "\n";
  }

  // member: robot_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_yaw, out);
    out << "\n";
  }

  // member: objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.objects.size() == 0) {
      out << "objects: []\n";
    } else {
      out << "objects:\n";
      for (auto item : msg.objects) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const WorldState & msg, bool use_flow_style = false)
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
  const rtdl_demo_interfaces::msg::WorldState & msg,
  std::ostream & out, size_t indentation = 0)
{
  rtdl_demo_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rtdl_demo_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const rtdl_demo_interfaces::msg::WorldState & msg)
{
  return rtdl_demo_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rtdl_demo_interfaces::msg::WorldState>()
{
  return "rtdl_demo_interfaces::msg::WorldState";
}

template<>
inline const char * name<rtdl_demo_interfaces::msg::WorldState>()
{
  return "rtdl_demo_interfaces/msg/WorldState";
}

template<>
struct has_fixed_size<rtdl_demo_interfaces::msg::WorldState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rtdl_demo_interfaces::msg::WorldState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rtdl_demo_interfaces::msg::WorldState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__TRAITS_HPP_
