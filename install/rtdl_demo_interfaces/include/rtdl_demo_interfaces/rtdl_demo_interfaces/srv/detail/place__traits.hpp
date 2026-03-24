// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rtdl_demo_interfaces:srv/Place.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__SRV__DETAIL__PLACE__TRAITS_HPP_
#define RTDL_DEMO_INTERFACES__SRV__DETAIL__PLACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rtdl_demo_interfaces/srv/detail/place__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rtdl_demo_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Place_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: object_name
  {
    out << "object_name: ";
    rosidl_generator_traits::value_to_yaml(msg.object_name, out);
    out << ", ";
  }

  // member: location_name
  {
    out << "location_name: ";
    rosidl_generator_traits::value_to_yaml(msg.location_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Place_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: object_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_name: ";
    rosidl_generator_traits::value_to_yaml(msg.object_name, out);
    out << "\n";
  }

  // member: location_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "location_name: ";
    rosidl_generator_traits::value_to_yaml(msg.location_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Place_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rtdl_demo_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rtdl_demo_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rtdl_demo_interfaces::srv::Place_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  rtdl_demo_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rtdl_demo_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const rtdl_demo_interfaces::srv::Place_Request & msg)
{
  return rtdl_demo_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rtdl_demo_interfaces::srv::Place_Request>()
{
  return "rtdl_demo_interfaces::srv::Place_Request";
}

template<>
inline const char * name<rtdl_demo_interfaces::srv::Place_Request>()
{
  return "rtdl_demo_interfaces/srv/Place_Request";
}

template<>
struct has_fixed_size<rtdl_demo_interfaces::srv::Place_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rtdl_demo_interfaces::srv::Place_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rtdl_demo_interfaces::srv::Place_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rtdl_demo_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Place_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Place_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Place_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace rtdl_demo_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use rtdl_demo_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rtdl_demo_interfaces::srv::Place_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  rtdl_demo_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rtdl_demo_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const rtdl_demo_interfaces::srv::Place_Response & msg)
{
  return rtdl_demo_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<rtdl_demo_interfaces::srv::Place_Response>()
{
  return "rtdl_demo_interfaces::srv::Place_Response";
}

template<>
inline const char * name<rtdl_demo_interfaces::srv::Place_Response>()
{
  return "rtdl_demo_interfaces/srv/Place_Response";
}

template<>
struct has_fixed_size<rtdl_demo_interfaces::srv::Place_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rtdl_demo_interfaces::srv::Place_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rtdl_demo_interfaces::srv::Place_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<rtdl_demo_interfaces::srv::Place>()
{
  return "rtdl_demo_interfaces::srv::Place";
}

template<>
inline const char * name<rtdl_demo_interfaces::srv::Place>()
{
  return "rtdl_demo_interfaces/srv/Place";
}

template<>
struct has_fixed_size<rtdl_demo_interfaces::srv::Place>
  : std::integral_constant<
    bool,
    has_fixed_size<rtdl_demo_interfaces::srv::Place_Request>::value &&
    has_fixed_size<rtdl_demo_interfaces::srv::Place_Response>::value
  >
{
};

template<>
struct has_bounded_size<rtdl_demo_interfaces::srv::Place>
  : std::integral_constant<
    bool,
    has_bounded_size<rtdl_demo_interfaces::srv::Place_Request>::value &&
    has_bounded_size<rtdl_demo_interfaces::srv::Place_Response>::value
  >
{
};

template<>
struct is_service<rtdl_demo_interfaces::srv::Place>
  : std::true_type
{
};

template<>
struct is_service_request<rtdl_demo_interfaces::srv::Place_Request>
  : std::true_type
{
};

template<>
struct is_service_response<rtdl_demo_interfaces::srv::Place_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // RTDL_DEMO_INTERFACES__SRV__DETAIL__PLACE__TRAITS_HPP_
