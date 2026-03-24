// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rtdl_demo_interfaces:msg/WorldState.idl
// generated code does not contain a copyright notice
#include "rtdl_demo_interfaces/msg/detail/world_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `robot_room`
// Member `holding_object`
#include "rosidl_runtime_c/string_functions.h"
// Member `objects`
#include "rtdl_demo_interfaces/msg/detail/object_state__functions.h"

bool
rtdl_demo_interfaces__msg__WorldState__init(rtdl_demo_interfaces__msg__WorldState * msg)
{
  if (!msg) {
    return false;
  }
  // robot_room
  if (!rosidl_runtime_c__String__init(&msg->robot_room)) {
    rtdl_demo_interfaces__msg__WorldState__fini(msg);
    return false;
  }
  // holding_object
  if (!rosidl_runtime_c__String__init(&msg->holding_object)) {
    rtdl_demo_interfaces__msg__WorldState__fini(msg);
    return false;
  }
  // robot_x
  // robot_y
  // robot_yaw
  // objects
  if (!rtdl_demo_interfaces__msg__ObjectState__Sequence__init(&msg->objects, 0)) {
    rtdl_demo_interfaces__msg__WorldState__fini(msg);
    return false;
  }
  return true;
}

void
rtdl_demo_interfaces__msg__WorldState__fini(rtdl_demo_interfaces__msg__WorldState * msg)
{
  if (!msg) {
    return;
  }
  // robot_room
  rosidl_runtime_c__String__fini(&msg->robot_room);
  // holding_object
  rosidl_runtime_c__String__fini(&msg->holding_object);
  // robot_x
  // robot_y
  // robot_yaw
  // objects
  rtdl_demo_interfaces__msg__ObjectState__Sequence__fini(&msg->objects);
}

bool
rtdl_demo_interfaces__msg__WorldState__are_equal(const rtdl_demo_interfaces__msg__WorldState * lhs, const rtdl_demo_interfaces__msg__WorldState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_room
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->robot_room), &(rhs->robot_room)))
  {
    return false;
  }
  // holding_object
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->holding_object), &(rhs->holding_object)))
  {
    return false;
  }
  // robot_x
  if (lhs->robot_x != rhs->robot_x) {
    return false;
  }
  // robot_y
  if (lhs->robot_y != rhs->robot_y) {
    return false;
  }
  // robot_yaw
  if (lhs->robot_yaw != rhs->robot_yaw) {
    return false;
  }
  // objects
  if (!rtdl_demo_interfaces__msg__ObjectState__Sequence__are_equal(
      &(lhs->objects), &(rhs->objects)))
  {
    return false;
  }
  return true;
}

bool
rtdl_demo_interfaces__msg__WorldState__copy(
  const rtdl_demo_interfaces__msg__WorldState * input,
  rtdl_demo_interfaces__msg__WorldState * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_room
  if (!rosidl_runtime_c__String__copy(
      &(input->robot_room), &(output->robot_room)))
  {
    return false;
  }
  // holding_object
  if (!rosidl_runtime_c__String__copy(
      &(input->holding_object), &(output->holding_object)))
  {
    return false;
  }
  // robot_x
  output->robot_x = input->robot_x;
  // robot_y
  output->robot_y = input->robot_y;
  // robot_yaw
  output->robot_yaw = input->robot_yaw;
  // objects
  if (!rtdl_demo_interfaces__msg__ObjectState__Sequence__copy(
      &(input->objects), &(output->objects)))
  {
    return false;
  }
  return true;
}

rtdl_demo_interfaces__msg__WorldState *
rtdl_demo_interfaces__msg__WorldState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rtdl_demo_interfaces__msg__WorldState * msg = (rtdl_demo_interfaces__msg__WorldState *)allocator.allocate(sizeof(rtdl_demo_interfaces__msg__WorldState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rtdl_demo_interfaces__msg__WorldState));
  bool success = rtdl_demo_interfaces__msg__WorldState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rtdl_demo_interfaces__msg__WorldState__destroy(rtdl_demo_interfaces__msg__WorldState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rtdl_demo_interfaces__msg__WorldState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rtdl_demo_interfaces__msg__WorldState__Sequence__init(rtdl_demo_interfaces__msg__WorldState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rtdl_demo_interfaces__msg__WorldState * data = NULL;

  if (size) {
    data = (rtdl_demo_interfaces__msg__WorldState *)allocator.zero_allocate(size, sizeof(rtdl_demo_interfaces__msg__WorldState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rtdl_demo_interfaces__msg__WorldState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rtdl_demo_interfaces__msg__WorldState__fini(&data[i - 1]);
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
rtdl_demo_interfaces__msg__WorldState__Sequence__fini(rtdl_demo_interfaces__msg__WorldState__Sequence * array)
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
      rtdl_demo_interfaces__msg__WorldState__fini(&array->data[i]);
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

rtdl_demo_interfaces__msg__WorldState__Sequence *
rtdl_demo_interfaces__msg__WorldState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rtdl_demo_interfaces__msg__WorldState__Sequence * array = (rtdl_demo_interfaces__msg__WorldState__Sequence *)allocator.allocate(sizeof(rtdl_demo_interfaces__msg__WorldState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rtdl_demo_interfaces__msg__WorldState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rtdl_demo_interfaces__msg__WorldState__Sequence__destroy(rtdl_demo_interfaces__msg__WorldState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rtdl_demo_interfaces__msg__WorldState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rtdl_demo_interfaces__msg__WorldState__Sequence__are_equal(const rtdl_demo_interfaces__msg__WorldState__Sequence * lhs, const rtdl_demo_interfaces__msg__WorldState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rtdl_demo_interfaces__msg__WorldState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rtdl_demo_interfaces__msg__WorldState__Sequence__copy(
  const rtdl_demo_interfaces__msg__WorldState__Sequence * input,
  rtdl_demo_interfaces__msg__WorldState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rtdl_demo_interfaces__msg__WorldState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rtdl_demo_interfaces__msg__WorldState * data =
      (rtdl_demo_interfaces__msg__WorldState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rtdl_demo_interfaces__msg__WorldState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rtdl_demo_interfaces__msg__WorldState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rtdl_demo_interfaces__msg__WorldState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
