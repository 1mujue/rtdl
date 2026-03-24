// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rtdl_demo_interfaces:srv/PlacePri.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__SRV__DETAIL__PLACE_PRI__FUNCTIONS_H_
#define RTDL_DEMO_INTERFACES__SRV__DETAIL__PLACE_PRI__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rtdl_demo_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "rtdl_demo_interfaces/srv/detail/place_pri__struct.h"

/// Initialize srv/PlacePri message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rtdl_demo_interfaces__srv__PlacePri_Request
 * )) before or use
 * rtdl_demo_interfaces__srv__PlacePri_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
bool
rtdl_demo_interfaces__srv__PlacePri_Request__init(rtdl_demo_interfaces__srv__PlacePri_Request * msg);

/// Finalize srv/PlacePri message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
void
rtdl_demo_interfaces__srv__PlacePri_Request__fini(rtdl_demo_interfaces__srv__PlacePri_Request * msg);

/// Create srv/PlacePri message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rtdl_demo_interfaces__srv__PlacePri_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
rtdl_demo_interfaces__srv__PlacePri_Request *
rtdl_demo_interfaces__srv__PlacePri_Request__create();

/// Destroy srv/PlacePri message.
/**
 * It calls
 * rtdl_demo_interfaces__srv__PlacePri_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
void
rtdl_demo_interfaces__srv__PlacePri_Request__destroy(rtdl_demo_interfaces__srv__PlacePri_Request * msg);

/// Check for srv/PlacePri message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
bool
rtdl_demo_interfaces__srv__PlacePri_Request__are_equal(const rtdl_demo_interfaces__srv__PlacePri_Request * lhs, const rtdl_demo_interfaces__srv__PlacePri_Request * rhs);

/// Copy a srv/PlacePri message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
bool
rtdl_demo_interfaces__srv__PlacePri_Request__copy(
  const rtdl_demo_interfaces__srv__PlacePri_Request * input,
  rtdl_demo_interfaces__srv__PlacePri_Request * output);

/// Initialize array of srv/PlacePri messages.
/**
 * It allocates the memory for the number of elements and calls
 * rtdl_demo_interfaces__srv__PlacePri_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
bool
rtdl_demo_interfaces__srv__PlacePri_Request__Sequence__init(rtdl_demo_interfaces__srv__PlacePri_Request__Sequence * array, size_t size);

/// Finalize array of srv/PlacePri messages.
/**
 * It calls
 * rtdl_demo_interfaces__srv__PlacePri_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
void
rtdl_demo_interfaces__srv__PlacePri_Request__Sequence__fini(rtdl_demo_interfaces__srv__PlacePri_Request__Sequence * array);

/// Create array of srv/PlacePri messages.
/**
 * It allocates the memory for the array and calls
 * rtdl_demo_interfaces__srv__PlacePri_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
rtdl_demo_interfaces__srv__PlacePri_Request__Sequence *
rtdl_demo_interfaces__srv__PlacePri_Request__Sequence__create(size_t size);

/// Destroy array of srv/PlacePri messages.
/**
 * It calls
 * rtdl_demo_interfaces__srv__PlacePri_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
void
rtdl_demo_interfaces__srv__PlacePri_Request__Sequence__destroy(rtdl_demo_interfaces__srv__PlacePri_Request__Sequence * array);

/// Check for srv/PlacePri message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
bool
rtdl_demo_interfaces__srv__PlacePri_Request__Sequence__are_equal(const rtdl_demo_interfaces__srv__PlacePri_Request__Sequence * lhs, const rtdl_demo_interfaces__srv__PlacePri_Request__Sequence * rhs);

/// Copy an array of srv/PlacePri messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
bool
rtdl_demo_interfaces__srv__PlacePri_Request__Sequence__copy(
  const rtdl_demo_interfaces__srv__PlacePri_Request__Sequence * input,
  rtdl_demo_interfaces__srv__PlacePri_Request__Sequence * output);

/// Initialize srv/PlacePri message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rtdl_demo_interfaces__srv__PlacePri_Response
 * )) before or use
 * rtdl_demo_interfaces__srv__PlacePri_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
bool
rtdl_demo_interfaces__srv__PlacePri_Response__init(rtdl_demo_interfaces__srv__PlacePri_Response * msg);

/// Finalize srv/PlacePri message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
void
rtdl_demo_interfaces__srv__PlacePri_Response__fini(rtdl_demo_interfaces__srv__PlacePri_Response * msg);

/// Create srv/PlacePri message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rtdl_demo_interfaces__srv__PlacePri_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
rtdl_demo_interfaces__srv__PlacePri_Response *
rtdl_demo_interfaces__srv__PlacePri_Response__create();

/// Destroy srv/PlacePri message.
/**
 * It calls
 * rtdl_demo_interfaces__srv__PlacePri_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
void
rtdl_demo_interfaces__srv__PlacePri_Response__destroy(rtdl_demo_interfaces__srv__PlacePri_Response * msg);

/// Check for srv/PlacePri message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
bool
rtdl_demo_interfaces__srv__PlacePri_Response__are_equal(const rtdl_demo_interfaces__srv__PlacePri_Response * lhs, const rtdl_demo_interfaces__srv__PlacePri_Response * rhs);

/// Copy a srv/PlacePri message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
bool
rtdl_demo_interfaces__srv__PlacePri_Response__copy(
  const rtdl_demo_interfaces__srv__PlacePri_Response * input,
  rtdl_demo_interfaces__srv__PlacePri_Response * output);

/// Initialize array of srv/PlacePri messages.
/**
 * It allocates the memory for the number of elements and calls
 * rtdl_demo_interfaces__srv__PlacePri_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
bool
rtdl_demo_interfaces__srv__PlacePri_Response__Sequence__init(rtdl_demo_interfaces__srv__PlacePri_Response__Sequence * array, size_t size);

/// Finalize array of srv/PlacePri messages.
/**
 * It calls
 * rtdl_demo_interfaces__srv__PlacePri_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
void
rtdl_demo_interfaces__srv__PlacePri_Response__Sequence__fini(rtdl_demo_interfaces__srv__PlacePri_Response__Sequence * array);

/// Create array of srv/PlacePri messages.
/**
 * It allocates the memory for the array and calls
 * rtdl_demo_interfaces__srv__PlacePri_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
rtdl_demo_interfaces__srv__PlacePri_Response__Sequence *
rtdl_demo_interfaces__srv__PlacePri_Response__Sequence__create(size_t size);

/// Destroy array of srv/PlacePri messages.
/**
 * It calls
 * rtdl_demo_interfaces__srv__PlacePri_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
void
rtdl_demo_interfaces__srv__PlacePri_Response__Sequence__destroy(rtdl_demo_interfaces__srv__PlacePri_Response__Sequence * array);

/// Check for srv/PlacePri message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
bool
rtdl_demo_interfaces__srv__PlacePri_Response__Sequence__are_equal(const rtdl_demo_interfaces__srv__PlacePri_Response__Sequence * lhs, const rtdl_demo_interfaces__srv__PlacePri_Response__Sequence * rhs);

/// Copy an array of srv/PlacePri messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rtdl_demo_interfaces
bool
rtdl_demo_interfaces__srv__PlacePri_Response__Sequence__copy(
  const rtdl_demo_interfaces__srv__PlacePri_Response__Sequence * input,
  rtdl_demo_interfaces__srv__PlacePri_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RTDL_DEMO_INTERFACES__SRV__DETAIL__PLACE_PRI__FUNCTIONS_H_
