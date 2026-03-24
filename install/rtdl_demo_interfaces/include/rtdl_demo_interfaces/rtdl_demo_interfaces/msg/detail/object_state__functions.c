// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rtdl_demo_interfaces:msg/ObjectState.idl
// generated code does not contain a copyright notice
#include "rtdl_demo_interfaces/msg/detail/object_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
// Member `room`
// Member `support`
#include "rosidl_runtime_c/string_functions.h"

bool
rtdl_demo_interfaces__msg__ObjectState__init(rtdl_demo_interfaces__msg__ObjectState * msg)
{
  if (!msg) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    rtdl_demo_interfaces__msg__ObjectState__fini(msg);
    return false;
  }
  // room
  if (!rosidl_runtime_c__String__init(&msg->room)) {
    rtdl_demo_interfaces__msg__ObjectState__fini(msg);
    return false;
  }
  // support
  if (!rosidl_runtime_c__String__init(&msg->support)) {
    rtdl_demo_interfaces__msg__ObjectState__fini(msg);
    return false;
  }
  // held_by_robot
  return true;
}

void
rtdl_demo_interfaces__msg__ObjectState__fini(rtdl_demo_interfaces__msg__ObjectState * msg)
{
  if (!msg) {
    return;
  }
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // room
  rosidl_runtime_c__String__fini(&msg->room);
  // support
  rosidl_runtime_c__String__fini(&msg->support);
  // held_by_robot
}

bool
rtdl_demo_interfaces__msg__ObjectState__are_equal(const rtdl_demo_interfaces__msg__ObjectState * lhs, const rtdl_demo_interfaces__msg__ObjectState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // room
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->room), &(rhs->room)))
  {
    return false;
  }
  // support
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->support), &(rhs->support)))
  {
    return false;
  }
  // held_by_robot
  if (lhs->held_by_robot != rhs->held_by_robot) {
    return false;
  }
  return true;
}

bool
rtdl_demo_interfaces__msg__ObjectState__copy(
  const rtdl_demo_interfaces__msg__ObjectState * input,
  rtdl_demo_interfaces__msg__ObjectState * output)
{
  if (!input || !output) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // room
  if (!rosidl_runtime_c__String__copy(
      &(input->room), &(output->room)))
  {
    return false;
  }
  // support
  if (!rosidl_runtime_c__String__copy(
      &(input->support), &(output->support)))
  {
    return false;
  }
  // held_by_robot
  output->held_by_robot = input->held_by_robot;
  return true;
}

rtdl_demo_interfaces__msg__ObjectState *
rtdl_demo_interfaces__msg__ObjectState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rtdl_demo_interfaces__msg__ObjectState * msg = (rtdl_demo_interfaces__msg__ObjectState *)allocator.allocate(sizeof(rtdl_demo_interfaces__msg__ObjectState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rtdl_demo_interfaces__msg__ObjectState));
  bool success = rtdl_demo_interfaces__msg__ObjectState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rtdl_demo_interfaces__msg__ObjectState__destroy(rtdl_demo_interfaces__msg__ObjectState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rtdl_demo_interfaces__msg__ObjectState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rtdl_demo_interfaces__msg__ObjectState__Sequence__init(rtdl_demo_interfaces__msg__ObjectState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rtdl_demo_interfaces__msg__ObjectState * data = NULL;

  if (size) {
    data = (rtdl_demo_interfaces__msg__ObjectState *)allocator.zero_allocate(size, sizeof(rtdl_demo_interfaces__msg__ObjectState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rtdl_demo_interfaces__msg__ObjectState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rtdl_demo_interfaces__msg__ObjectState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rtdl_demo_interfaces__msg__ObjectState__Sequence__fini(rtdl_demo_interfaces__msg__ObjectState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rtdl_demo_interfaces__msg__ObjectState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rtdl_demo_interfaces__msg__ObjectState__Sequence *
rtdl_demo_interfaces__msg__ObjectState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rtdl_demo_interfaces__msg__ObjectState__Sequence * array = (rtdl_demo_interfaces__msg__ObjectState__Sequence *)allocator.allocate(sizeof(rtdl_demo_interfaces__msg__ObjectState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rtdl_demo_interfaces__msg__ObjectState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rtdl_demo_interfaces__msg__ObjectState__Sequence__destroy(rtdl_demo_interfaces__msg__ObjectState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rtdl_demo_interfaces__msg__ObjectState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rtdl_demo_interfaces__msg__ObjectState__Sequence__are_equal(const rtdl_demo_interfaces__msg__ObjectState__Sequence * lhs, const rtdl_demo_interfaces__msg__ObjectState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rtdl_demo_interfaces__msg__ObjectState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rtdl_demo_interfaces__msg__ObjectState__Sequence__copy(
  const rtdl_demo_interfaces__msg__ObjectState__Sequence * input,
  rtdl_demo_interfaces__msg__ObjectState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rtdl_demo_interfaces__msg__ObjectState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rtdl_demo_interfaces__msg__ObjectState * data =
      (rtdl_demo_interfaces__msg__ObjectState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rtdl_demo_interfaces__msg__ObjectState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rtdl_demo_interfaces__msg__ObjectState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rtdl_demo_interfaces__msg__ObjectState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
