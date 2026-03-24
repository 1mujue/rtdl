// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rtdl_demo_interfaces:msg/ObjectState.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__MSG__DETAIL__OBJECT_STATE__STRUCT_HPP_
#define RTDL_DEMO_INTERFACES__MSG__DETAIL__OBJECT_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rtdl_demo_interfaces__msg__ObjectState __attribute__((deprecated))
#else
# define DEPRECATED__rtdl_demo_interfaces__msg__ObjectState __declspec(deprecated)
#endif

namespace rtdl_demo_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectState_
{
  using Type = ObjectState_<ContainerAllocator>;

  explicit ObjectState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->room = "";
      this->support = "";
      this->held_by_robot = false;
    }
  }

  explicit ObjectState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    room(_alloc),
    support(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->name = "";
      this->room = "";
      this->support = "";
      this->held_by_robot = false;
    }
  }

  // field types and members
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _room_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _room_type room;
  using _support_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _support_type support;
  using _held_by_robot_type =
    bool;
  _held_by_robot_type held_by_robot;

  // setters for named parameter idiom
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__room(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->room = _arg;
    return *this;
  }
  Type & set__support(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->support = _arg;
    return *this;
  }
  Type & set__held_by_robot(
    const bool & _arg)
  {
    this->held_by_robot = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator> *;
  using ConstRawPtr =
    const rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rtdl_demo_interfaces__msg__ObjectState
    std::shared_ptr<rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rtdl_demo_interfaces__msg__ObjectState
    std::shared_ptr<rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectState_ & other) const
  {
    if (this->name != other.name) {
      return false;
    }
    if (this->room != other.room) {
      return false;
    }
    if (this->support != other.support) {
      return false;
    }
    if (this->held_by_robot != other.held_by_robot) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectState_

// alias to use template instance with default allocator
using ObjectState =
  rtdl_demo_interfaces::msg::ObjectState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rtdl_demo_interfaces

#endif  // RTDL_DEMO_INTERFACES__MSG__DETAIL__OBJECT_STATE__STRUCT_HPP_
