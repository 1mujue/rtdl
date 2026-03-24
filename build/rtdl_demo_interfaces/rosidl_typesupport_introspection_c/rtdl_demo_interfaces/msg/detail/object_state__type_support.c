// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rtdl_demo_interfaces:msg/ObjectState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rtdl_demo_interfaces/msg/detail/object_state__rosidl_typesupport_introspection_c.h"
#include "rtdl_demo_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rtdl_demo_interfaces/msg/detail/object_state__functions.h"
#include "rtdl_demo_interfaces/msg/detail/object_state__struct.h"


// Include directives for member types
// Member `name`
// Member `room`
// Member `support`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rtdl_demo_interfaces__msg__ObjectState__rosidl_typesupport_introspection_c__ObjectState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rtdl_demo_interfaces__msg__ObjectState__init(message_memory);
}

void rtdl_demo_interfaces__msg__ObjectState__rosidl_typesupport_introspection_c__ObjectState_fini_function(void * message_memory)
{
  rtdl_demo_interfaces__msg__ObjectState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rtdl_demo_interfaces__msg__ObjectState__rosidl_typesupport_introspection_c__ObjectState_message_member_array[4] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rtdl_demo_interfaces__msg__ObjectState, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "room",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rtdl_demo_interfaces__msg__ObjectState, room),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "support",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rtdl_demo_interfaces__msg__ObjectState, support),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "held_by_robot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rtdl_demo_interfaces__msg__ObjectState, held_by_robot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rtdl_demo_interfaces__msg__ObjectState__rosidl_typesupport_introspection_c__ObjectState_message_members = {
  "rtdl_demo_interfaces__msg",  // message namespace
  "ObjectState",  // message name
  4,  // number of fields
  sizeof(rtdl_demo_interfaces__msg__ObjectState),
  rtdl_demo_interfaces__msg__ObjectState__rosidl_typesupport_introspection_c__ObjectState_message_member_array,  // message members
  rtdl_demo_interfaces__msg__ObjectState__rosidl_typesupport_introspection_c__ObjectState_init_function,  // function to initialize message memory (memory has to be allocated)
  rtdl_demo_interfaces__msg__ObjectState__rosidl_typesupport_introspection_c__ObjectState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rtdl_demo_interfaces__msg__ObjectState__rosidl_typesupport_introspection_c__ObjectState_message_type_support_handle = {
  0,
  &rtdl_demo_interfaces__msg__ObjectState__rosidl_typesupport_introspection_c__ObjectState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rtdl_demo_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rtdl_demo_interfaces, msg, ObjectState)() {
  if (!rtdl_demo_interfaces__msg__ObjectState__rosidl_typesupport_introspection_c__ObjectState_message_type_support_handle.typesupport_identifier) {
    rtdl_demo_interfaces__msg__ObjectState__rosidl_typesupport_introspection_c__ObjectState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rtdl_demo_interfaces__msg__ObjectState__rosidl_typesupport_introspection_c__ObjectState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
