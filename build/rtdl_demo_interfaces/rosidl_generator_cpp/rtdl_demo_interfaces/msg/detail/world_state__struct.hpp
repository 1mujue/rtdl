// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rtdl_demo_interfaces:msg/WorldState.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__STRUCT_HPP_
#define RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'objects'
#include "rtdl_demo_interfaces/msg/detail/object_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rtdl_demo_interfaces__msg__WorldState __attribute__((deprecated))
#else
# define DEPRECATED__rtdl_demo_interfaces__msg__WorldState __declspec(deprecated)
#endif

namespace rtdl_demo_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WorldState_
{
  using Type = WorldState_<ContainerAllocator>;

  explicit WorldState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_room = "";
      this->holding_object = "";
      this->robot_x = 0.0;
      this->robot_y = 0.0;
      this->robot_yaw = 0.0;
    }
  }

  explicit WorldState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : robot_room(_alloc),
    holding_object(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->robot_room = "";
      this->holding_object = "";
      this->robot_x = 0.0;
      this->robot_y = 0.0;
      this->robot_yaw = 0.0;
    }
  }

  // field types and members
  using _robot_room_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _robot_room_type robot_room;
  using _holding_object_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _holding_object_type holding_object;
  using _robot_x_type =
    double;
  _robot_x_type robot_x;
  using _robot_y_type =
    double;
  _robot_y_type robot_y;
  using _robot_yaw_type =
    double;
  _robot_yaw_type robot_yaw;
  using _objects_type =
    std::vector<rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator>>>;
  _objects_type objects;

  // setters for named parameter idiom
  Type & set__robot_room(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->robot_room = _arg;
    return *this;
  }
  Type & set__holding_object(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->holding_object = _arg;
    return *this;
  }
  Type & set__robot_x(
    const double & _arg)
  {
    this->robot_x = _arg;
    return *this;
  }
  Type & set__robot_y(
    const double & _arg)
  {
    this->robot_y = _arg;
    return *this;
  }
  Type & set__robot_yaw(
    const double & _arg)
  {
    this->robot_yaw = _arg;
    return *this;
  }
  Type & set__objects(
    const std::vector<rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rtdl_demo_interfaces::msg::ObjectState_<ContainerAllocator>>> & _arg)
  {
    this->objects = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator> *;
  using ConstRawPtr =
    const rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rtdl_demo_interfaces__msg__WorldState
    std::shared_ptr<rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rtdl_demo_interfaces__msg__WorldState
    std::shared_ptr<rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WorldState_ & other) const
  {
    if (this->robot_room != other.robot_room) {
      return false;
    }
    if (this->holding_object != other.holding_object) {
      return false;
    }
    if (this->robot_x != other.robot_x) {
      return false;
    }
    if (this->robot_y != other.robot_y) {
      return false;
    }
    if (this->robot_yaw != other.robot_yaw) {
      return false;
    }
    if (this->objects != other.objects) {
      return false;
    }
    return true;
  }
  bool operator!=(const WorldState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WorldState_

// alias to use template instance with default allocator
using WorldState =
  rtdl_demo_interfaces::msg::WorldState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rtdl_demo_interfaces

#endif  // RTDL_DEMO_INTERFACES__MSG__DETAIL__WORLD_STATE__STRUCT_HPP_
