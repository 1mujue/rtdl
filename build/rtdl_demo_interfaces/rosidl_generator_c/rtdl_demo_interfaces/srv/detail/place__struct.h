// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rtdl_demo_interfaces:srv/Place.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__SRV__DETAIL__PLACE__STRUCT_H_
#define RTDL_DEMO_INTERFACES__SRV__DETAIL__PLACE__STRUCT_H_

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
// Member 'location_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Place in the package rtdl_demo_interfaces.
typedef struct rtdl_demo_interfaces__srv__Place_Request
{
  rosidl_runtime_c__String object_name;
  rosidl_runtime_c__String location_name;
} rtdl_demo_interfaces__srv__Place_Request;

// Struct for a sequence of rtdl_demo_interfaces__srv__Place_Request.
typedef struct rtdl_demo_interfaces__srv__Place_Request__Sequence
{
  rtdl_demo_interfaces__srv__Place_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rtdl_demo_interfaces__srv__Place_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Place in the package rtdl_demo_interfaces.
typedef struct rtdl_demo_interfaces__srv__Place_Response
{
  bool success;
  rosidl_runtime_c__String message;
} rtdl_demo_interfaces__srv__Place_Response;

// Struct for a sequence of rtdl_demo_interfaces__srv__Place_Response.
typedef struct rtdl_demo_interfaces__srv__Place_Response__Sequence
{
  rtdl_demo_interfaces__srv__Place_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rtdl_demo_interfaces__srv__Place_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RTDL_DEMO_INTERFACES__SRV__DETAIL__PLACE__STRUCT_H_
