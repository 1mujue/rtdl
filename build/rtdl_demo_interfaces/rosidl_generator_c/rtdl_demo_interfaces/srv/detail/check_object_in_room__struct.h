// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rtdl_demo_interfaces:srv/CheckObjectInRoom.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__SRV__DETAIL__CHECK_OBJECT_IN_ROOM__STRUCT_H_
#define RTDL_DEMO_INTERFACES__SRV__DETAIL__CHECK_OBJECT_IN_ROOM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'object_name'
// Member 'room_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/CheckObjectInRoom in the package rtdl_demo_interfaces.
typedef struct rtdl_demo_interfaces__srv__CheckObjectInRoom_Request
{
  rosidl_runtime_c__String object_name;
  rosidl_runtime_c__String room_name;
} rtdl_demo_interfaces__srv__CheckObjectInRoom_Request;

// Struct for a sequence of rtdl_demo_interfaces__srv__CheckObjectInRoom_Request.
typedef struct rtdl_demo_interfaces__srv__CheckObjectInRoom_Request__Sequence
{
  rtdl_demo_interfaces__srv__CheckObjectInRoom_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rtdl_demo_interfaces__srv__CheckObjectInRoom_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/CheckObjectInRoom in the package rtdl_demo_interfaces.
typedef struct rtdl_demo_interfaces__srv__CheckObjectInRoom_Response
{
  bool success;
  rosidl_runtime_c__String message;
  bool found;
} rtdl_demo_interfaces__srv__CheckObjectInRoom_Response;

// Struct for a sequence of rtdl_demo_interfaces__srv__CheckObjectInRoom_Response.
typedef struct rtdl_demo_interfaces__srv__CheckObjectInRoom_Response__Sequence
{
  rtdl_demo_interfaces__srv__CheckObjectInRoom_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rtdl_demo_interfaces__srv__CheckObjectInRoom_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RTDL_DEMO_INTERFACES__SRV__DETAIL__CHECK_OBJECT_IN_ROOM__STRUCT_H_
