// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rtdl_demo_interfaces:msg/WorldState.idl
// generated code does not contain a copyright notice
#include "rtdl_demo_interfaces/msg/detail/world_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rtdl_demo_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rtdl_demo_interfaces/msg/detail/world_state__struct.h"
#include "rtdl_demo_interfaces/msg/detail/world_state__functions.h"
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

#include "rosidl_runtime_c/string.h"  // holding_object, robot_room
#include "rosidl_runtime_c/string_functions.h"  // holding_object, robot_room
#include "rtdl_demo_interfaces/msg/detail/object_state__functions.h"  // objects

// forward declare type support functions
size_t get_serialized_size_rtdl_demo_interfaces__msg__ObjectState(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_rtdl_demo_interfaces__msg__ObjectState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rtdl_demo_interfaces, msg, ObjectState)();


using _WorldState__ros_msg_type = rtdl_demo_interfaces__msg__WorldState;

static bool _WorldState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _WorldState__ros_msg_type * ros_message = static_cast<const _WorldState__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_room
  {
    const rosidl_runtime_c__String * str = &ros_message->robot_room;
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

  // Field name: holding_object
  {
    const rosidl_runtime_c__String * str = &ros_message->holding_object;
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

  // Field name: robot_x
  {
    cdr << ros_message->robot_x;
  }

  // Field name: robot_y
  {
    cdr << ros_message->robot_y;
  }

  // Field name: robot_yaw
  {
    cdr << ros_message->robot_yaw;
  }

  // Field name: objects
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, rtdl_demo_interfaces, msg, ObjectState
      )()->data);
    size_t size = ros_message->objects.size;
    auto array_ptr = ros_message->objects.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _WorldState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _WorldState__ros_msg_type * ros_message = static_cast<_WorldState__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_room
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->robot_room.data) {
      rosidl_runtime_c__String__init(&ros_message->robot_room);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->robot_room,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'robot_room'\n");
      return false;
    }
  }

  // Field name: holding_object
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->holding_object.data) {
      rosidl_runtime_c__String__init(&ros_message->holding_object);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->holding_object,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'holding_object'\n");
      return false;
    }
  }

  // Field name: robot_x
  {
    cdr >> ros_message->robot_x;
  }

  // Field name: robot_y
  {
    cdr >> ros_message->robot_y;
  }

  // Field name: robot_yaw
  {
    cdr >> ros_message->robot_yaw;
  }

  // Field name: objects
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, rtdl_demo_interfaces, msg, ObjectState
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);

    // Check there are at least 'size' remaining bytes in the CDR stream before resizing
    auto old_state = cdr.getState();
    bool correct_size = cdr.jump(size);
    cdr.setState(old_state);
    if (!correct_size) {
      fprintf(stderr, "sequence size exceeds remaining buffer\n");
      return false;
    }

    if (ros_message->objects.data) {
      rtdl_demo_interfaces__msg__ObjectState__Sequence__fini(&ros_message->objects);
    }
    if (!rtdl_demo_interfaces__msg__ObjectState__Sequence__init(&ros_message->objects, size)) {
      fprintf(stderr, "failed to create array for field 'objects'");
      return false;
    }
    auto array_ptr = ros_message->objects.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rtdl_demo_interfaces
size_t get_serialized_size_rtdl_demo_interfaces__msg__WorldState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _WorldState__ros_msg_type * ros_message = static_cast<const _WorldState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name robot_room
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->robot_room.size + 1);
  // field.name holding_object
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->holding_object.size + 1);
  // field.name robot_x
  {
    size_t item_size = sizeof(ros_message->robot_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_y
  {
    size_t item_size = sizeof(ros_message->robot_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name robot_yaw
  {
    size_t item_size = sizeof(ros_message->robot_yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name objects
  {
    size_t array_size = ros_message->objects.size;
    auto array_ptr = ros_message->objects.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_rtdl_demo_interfaces__msg__ObjectState(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _WorldState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rtdl_demo_interfaces__msg__WorldState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rtdl_demo_interfaces
size_t max_serialized_size_rtdl_demo_interfaces__msg__WorldState(
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

  // member: robot_room
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
  // member: holding_object
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
  // member: robot_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: robot_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: robot_yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: objects
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_rtdl_demo_interfaces__msg__ObjectState(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rtdl_demo_interfaces__msg__WorldState;
    is_plain =
      (
      offsetof(DataType, objects) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _WorldState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rtdl_demo_interfaces__msg__WorldState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_WorldState = {
  "rtdl_demo_interfaces::msg",
  "WorldState",
  _WorldState__cdr_serialize,
  _WorldState__cdr_deserialize,
  _WorldState__get_serialized_size,
  _WorldState__max_serialized_size
};

static rosidl_message_type_support_t _WorldState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_WorldState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rtdl_demo_interfaces, msg, WorldState)() {
  return &_WorldState__type_support;
}

#if defined(__cplusplus)
}
#endif
