// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rtdl_demo_interfaces:msg/ObjectState.idl
// generated code does not contain a copyright notice
#include "rtdl_demo_interfaces/msg/detail/object_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rtdl_demo_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rtdl_demo_interfaces/msg/detail/object_state__struct.h"
#include "rtdl_demo_interfaces/msg/detail/object_state__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // name, room, support
#include "rosidl_runtime_c/string_functions.h"  // name, room, support

// forward declare type support functions


using _ObjectState__ros_msg_type = rtdl_demo_interfaces__msg__ObjectState;

static bool _ObjectState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ObjectState__ros_msg_type * ros_message = static_cast<const _ObjectState__ros_msg_type *>(untyped_ros_message);
  // Field name: name
  {
    const rosidl_runtime_c__String * str = &ros_message->name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: room
  {
    const rosidl_runtime_c__String * str = &ros_message->room;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: support
  {
    const rosidl_runtime_c__String * str = &ros_message->support;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: held_by_robot
  {
    cdr << (ros_message->held_by_robot ? true : false);
  }

  return true;
}

static bool _ObjectState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ObjectState__ros_msg_type * ros_message = static_cast<_ObjectState__ros_msg_type *>(untyped_ros_message);
  // Field name: name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->name.data) {
      rosidl_runtime_c__String__init(&ros_message->name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'name'\n");
      return false;
    }
  }

  // Field name: room
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->room.data) {
      rosidl_runtime_c__String__init(&ros_message->room);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->room,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'room'\n");
      return false;
    }
  }

  // Field name: support
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->support.data) {
      rosidl_runtime_c__String__init(&ros_message->support);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->support,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'support'\n");
      return false;
    }
  }

  // Field name: held_by_robot
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->held_by_robot = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rtdl_demo_interfaces
size_t get_serialized_size_rtdl_demo_interfaces__msg__ObjectState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ObjectState__ros_msg_type * ros_message = static_cast<const _ObjectState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->name.size + 1);
  // field.name room
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->room.size + 1);
  // field.name support
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->support.size + 1);
  // field.name held_by_robot
  {
    size_t item_size = sizeof(ros_message->held_by_robot);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ObjectState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rtdl_demo_interfaces__msg__ObjectState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rtdl_demo_interfaces
size_t max_serialized_size_rtdl_demo_interfaces__msg__ObjectState(
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

  // member: name
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
  // member: room
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
  // member: support
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
  // member: held_by_robot
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
    using DataType = rtdl_demo_interfaces__msg__ObjectState;
    is_plain =
      (
      offsetof(DataType, held_by_robot) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ObjectState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rtdl_demo_interfaces__msg__ObjectState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ObjectState = {
  "rtdl_demo_interfaces::msg",
  "ObjectState",
  _ObjectState__cdr_serialize,
  _ObjectState__cdr_deserialize,
  _ObjectState__get_serialized_size,
  _ObjectState__max_serialized_size
};

static rosidl_message_type_support_t _ObjectState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ObjectState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rtdl_demo_interfaces, msg, ObjectState)() {
  return &_ObjectState__type_support;
}

#if defined(__cplusplus)
}
#endif
