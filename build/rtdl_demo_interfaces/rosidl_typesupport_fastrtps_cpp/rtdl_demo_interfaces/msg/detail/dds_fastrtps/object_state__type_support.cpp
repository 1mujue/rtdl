// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rtdl_demo_interfaces:msg/ObjectState.idl
// generated code does not contain a copyright notice
#include "rtdl_demo_interfaces/msg/detail/object_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rtdl_demo_interfaces/msg/detail/object_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace rtdl_demo_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rtdl_demo_interfaces
cdr_serialize(
  const rtdl_demo_interfaces::msg::ObjectState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: name
  cdr << ros_message.name;
  // Member: room
  cdr << ros_message.room;
  // Member: support
  cdr << ros_message.support;
  // Member: held_by_robot
  cdr << (ros_message.held_by_robot ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rtdl_demo_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rtdl_demo_interfaces::msg::ObjectState & ros_message)
{
  // Member: name
  cdr >> ros_message.name;

  // Member: room
  cdr >> ros_message.room;

  // Member: support
  cdr >> ros_message.support;

  // Member: held_by_robot
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.held_by_robot = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rtdl_demo_interfaces
get_serialized_size(
  const rtdl_demo_interfaces::msg::ObjectState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.name.size() + 1);
  // Member: room
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.room.size() + 1);
  // Member: support
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.support.size() + 1);
  // Member: held_by_robot
  {
    size_t item_size = sizeof(ros_message.held_by_robot);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rtdl_demo_interfaces
max_serialized_size_ObjectState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: name
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: room
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: support
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: held_by_robot
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rtdl_demo_interfaces::msg::ObjectState;
    is_plain =
      (
      offsetof(DataType, held_by_robot) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ObjectState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rtdl_demo_interfaces::msg::ObjectState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ObjectState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rtdl_demo_interfaces::msg::ObjectState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ObjectState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rtdl_demo_interfaces::msg::ObjectState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ObjectState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ObjectState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ObjectState__callbacks = {
  "rtdl_demo_interfaces::msg",
  "ObjectState",
  _ObjectState__cdr_serialize,
  _ObjectState__cdr_deserialize,
  _ObjectState__get_serialized_size,
  _ObjectState__max_serialized_size
};

static rosidl_message_type_support_t _ObjectState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ObjectState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rtdl_demo_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rtdl_demo_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<rtdl_demo_interfaces::msg::ObjectState>()
{
  return &rtdl_demo_interfaces::msg::typesupport_fastrtps_cpp::_ObjectState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rtdl_demo_interfaces, msg, ObjectState)() {
  return &rtdl_demo_interfaces::msg::typesupport_fastrtps_cpp::_ObjectState__handle;
}

#ifdef __cplusplus
}
#endif
