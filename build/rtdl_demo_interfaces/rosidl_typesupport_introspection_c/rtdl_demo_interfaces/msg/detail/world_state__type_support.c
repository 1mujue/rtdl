// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rtdl_demo_interfaces:msg/WorldState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rtdl_demo_interfaces/msg/detail/world_state__rosidl_typesupport_introspection_c.h"
#include "rtdl_demo_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rtdl_demo_interfaces/msg/detail/world_state__functions.h"
#include "rtdl_demo_interfaces/msg/detail/world_state__struct.h"


// Include directives for member types
// Member `robot_room`
// Member `holding_object`
#include "rosidl_runtime_c/string_functions.h"
// Member `objects`
#include "rtdl_demo_interfaces/msg/object_state.h"
// Member `objects`
#include "rtdl_demo_interfaces/msg/detail/object_state__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rtdl_demo_interfaces__msg__WorldState__init(message_memory);
}

void rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_fini_function(void * message_memory)
{
  rtdl_demo_interfaces__msg__WorldState__fini(message_memory);
}

size_t rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__size_function__WorldState__objects(
  const void * untyped_member)
{
  const rtdl_demo_interfaces__msg__ObjectState__Sequence * member =
    (const rtdl_demo_interfaces__msg__ObjectState__Sequence *)(untyped_member);
  return member->size;
}

const void * rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__get_const_function__WorldState__objects(
  const void * untyped_member, size_t index)
{
  const rtdl_demo_interfaces__msg__ObjectState__Sequence * member =
    (const rtdl_demo_interfaces__msg__ObjectState__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__get_function__WorldState__objects(
  void * untyped_member, size_t index)
{
  rtdl_demo_interfaces__msg__ObjectState__Sequence * member =
    (rtdl_demo_interfaces__msg__ObjectState__Sequence *)(untyped_member);
  return &member->data[index];
}

void rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__fetch_function__WorldState__objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rtdl_demo_interfaces__msg__ObjectState * item =
    ((const rtdl_demo_interfaces__msg__ObjectState *)
    rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__get_const_function__WorldState__objects(untyped_member, index));
  rtdl_demo_interfaces__msg__ObjectState * value =
    (rtdl_demo_interfaces__msg__ObjectState *)(untyped_value);
  *value = *item;
}

void rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__assign_function__WorldState__objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rtdl_demo_interfaces__msg__ObjectState * item =
    ((rtdl_demo_interfaces__msg__ObjectState *)
    rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__get_function__WorldState__objects(untyped_member, index));
  const rtdl_demo_interfaces__msg__ObjectState * value =
    (const rtdl_demo_interfaces__msg__ObjectState *)(untyped_value);
  *item = *value;
}

bool rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__resize_function__WorldState__objects(
  void * untyped_member, size_t size)
{
  rtdl_demo_interfaces__msg__ObjectState__Sequence * member =
    (rtdl_demo_interfaces__msg__ObjectState__Sequence *)(untyped_member);
  rtdl_demo_interfaces__msg__ObjectState__Sequence__fini(member);
  return rtdl_demo_interfaces__msg__ObjectState__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_message_member_array[6] = {
  {
    "robot_room",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rtdl_demo_interfaces__msg__WorldState, robot_room),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "holding_object",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rtdl_demo_interfaces__msg__WorldState, holding_object),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rtdl_demo_interfaces__msg__WorldState, robot_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rtdl_demo_interfaces__msg__WorldState, robot_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "robot_yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rtdl_demo_interfaces__msg__WorldState, robot_yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rtdl_demo_interfaces__msg__WorldState, objects),  // bytes offset in struct
    NULL,  // default value
    rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__size_function__WorldState__objects,  // size() function pointer
    rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__get_const_function__WorldState__objects,  // get_const(index) function pointer
    rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__get_function__WorldState__objects,  // get(index) function pointer
    rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__fetch_function__WorldState__objects,  // fetch(index, &value) function pointer
    rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__assign_function__WorldState__objects,  // assign(index, value) function pointer
    rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__resize_function__WorldState__objects  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_message_members = {
  "rtdl_demo_interfaces__msg",  // message namespace
  "WorldState",  // message name
  6,  // number of fields
  sizeof(rtdl_demo_interfaces__msg__WorldState),
  rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_message_member_array,  // message members
  rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_init_function,  // function to initialize message memory (memory has to be allocated)
  rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_message_type_support_handle = {
  0,
  &rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rtdl_demo_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rtdl_demo_interfaces, msg, WorldState)() {
  rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rtdl_demo_interfaces, msg, ObjectState)();
  if (!rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_message_type_support_handle.typesupport_identifier) {
    rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rtdl_demo_interfaces__msg__WorldState__rosidl_typesupport_introspection_c__WorldState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
