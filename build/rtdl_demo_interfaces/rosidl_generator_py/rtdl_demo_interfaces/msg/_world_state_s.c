// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from rtdl_demo_interfaces:msg/WorldState.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "rtdl_demo_interfaces/msg/detail/world_state__struct.h"
#include "rtdl_demo_interfaces/msg/detail/world_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "rtdl_demo_interfaces/msg/detail/object_state__functions.h"
// end nested array functions include
bool rtdl_demo_interfaces__msg__object_state__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * rtdl_demo_interfaces__msg__object_state__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool rtdl_demo_interfaces__msg__world_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("rtdl_demo_interfaces.msg._world_state.WorldState", full_classname_dest, 48) == 0);
  }
  rtdl_demo_interfaces__msg__WorldState * ros_message = _ros_message;
  {  // robot_room
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_room");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->robot_room, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // holding_object
    PyObject * field = PyObject_GetAttrString(_pymsg, "holding_object");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->holding_object, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // robot_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->robot_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // robot_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->robot_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // robot_yaw
    PyObject * field = PyObject_GetAttrString(_pymsg, "robot_yaw");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->robot_yaw = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // objects
    PyObject * field = PyObject_GetAttrString(_pymsg, "objects");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'objects'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!rtdl_demo_interfaces__msg__ObjectState__Sequence__init(&(ros_message->objects), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create rtdl_demo_interfaces__msg__ObjectState__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    rtdl_demo_interfaces__msg__ObjectState * dest = ros_message->objects.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!rtdl_demo_interfaces__msg__object_state__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * rtdl_demo_interfaces__msg__world_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of WorldState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("rtdl_demo_interfaces.msg._world_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "WorldState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  rtdl_demo_interfaces__msg__WorldState * ros_message = (rtdl_demo_interfaces__msg__WorldState *)raw_ros_message;
  {  // robot_room
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->robot_room.data,
      strlen(ros_message->robot_room.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_room", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // holding_object
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->holding_object.data,
      strlen(ros_message->holding_object.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "holding_object", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robot_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->robot_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robot_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->robot_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robot_yaw
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->robot_yaw);
    {
      int rc = PyObject_SetAttrString(_pymessage, "robot_yaw", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // objects
    PyObject * field = NULL;
    size_t size = ros_message->objects.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    rtdl_demo_interfaces__msg__ObjectState * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->objects.data[i]);
      PyObject * pyitem = rtdl_demo_interfaces__msg__object_state__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "objects", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
