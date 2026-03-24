// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rtdl_demo_interfaces:msg/WorldState.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__STRUCT_H_
#define RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_room'
// Member 'holding_object'
#include "rosidl_runtime_c/string.h"
// Member 'objects'
#include "rtdl_demo_interfaces/msg/detail/object_state__struct.h"

/// Struct defined in msg/WorldState in the package rtdl_demo_interfaces.
typedef struct rtdl_demo_interfaces__msg__WorldState
{
  rosidl_runtime_c__String robot_room;
  rosidl_runtime_c__String holding_object;
  double robot_x;
  double robot_y;
  double robot_yaw;
  rtdl_demo_interfaces__msg__ObjectState__Sequence objects;
} rtdl_demo_interfaces__msg__WorldState;

// Struct for a sequence of rtdl_demo_interfaces__msg__WorldState.
typedef struct rtdl_demo_interfaces__msg__WorldState__Sequence
{
  rtdl_demo_interfaces__msg__WorldState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rtdl_demo_interfaces__msg__WorldState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__STRUCT_H_
