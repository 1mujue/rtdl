// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rtdl_demo_interfaces:msg/ObjectState.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__MSG__DETAIL__OBJECT_STATE__STRUCT_H_
#define RTDL_DEMO_INTERFACES__MSG__DETAIL__OBJECT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'room'
// Member 'support'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ObjectState in the package rtdl_demo_interfaces.
typedef struct rtdl_demo_interfaces__msg__ObjectState
{
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String room;
  rosidl_runtime_c__String support;
  bool held_by_robot;
} rtdl_demo_interfaces__msg__ObjectState;

// Struct for a sequence of rtdl_demo_interfaces__msg__ObjectState.
typedef struct rtdl_demo_interfaces__msg__ObjectState__Sequence
{
  rtdl_demo_interfaces__msg__ObjectState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rtdl_demo_interfaces__msg__ObjectState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RTDL_DEMO_INTERFACES__MSG__DETAIL__OBJECT_STATE__STRUCT_H_
