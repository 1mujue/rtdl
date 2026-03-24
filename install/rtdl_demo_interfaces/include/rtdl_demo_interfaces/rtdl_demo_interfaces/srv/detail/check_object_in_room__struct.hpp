// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rtdl_demo_interfaces:srv/CheckObjectInRoom.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__SRV__DETAIL__CHECK_OBJECT_IN_ROOM__STRUCT_HPP_
#define RTDL_DEMO_INTERFACES__SRV__DETAIL__CHECK_OBJECT_IN_ROOM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rtdl_demo_interfaces__srv__CheckObjectInRoom_Request __attribute__((deprecated))
#else
# define DEPRECATED__rtdl_demo_interfaces__srv__CheckObjectInRoom_Request __declspec(deprecated)
#endif

namespace rtdl_demo_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CheckObjectInRoom_Request_
{
  using Type = CheckObjectInRoom_Request_<ContainerAllocator>;

  explicit CheckObjectInRoom_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->object_name = "";
      this->room_name = "";
    }
  }

  explicit CheckObjectInRoom_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : object_name(_alloc),
    room_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->object_name = "";
      this->room_name = "";
    }
  }

  // field types and members
  using _object_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _object_name_type object_name;
  using _room_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _room_name_type room_name;

  // setters for named parameter idiom
  Type & set__object_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->object_name = _arg;
    return *this;
  }
  Type & set__room_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->room_name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rtdl_demo_interfaces__srv__CheckObjectInRoom_Request
    std::shared_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rtdl_demo_interfaces__srv__CheckObjectInRoom_Request
    std::shared_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CheckObjectInRoom_Request_ & other) const
  {
    if (this->object_name != other.object_name) {
      return false;
    }
    if (this->room_name != other.room_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const CheckObjectInRoom_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CheckObjectInRoom_Request_

// alias to use template instance with default allocator
using CheckObjectInRoom_Request =
  rtdl_demo_interfaces::srv::CheckObjectInRoom_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rtdl_demo_interfaces


#ifndef _WIN32
# define DEPRECATED__rtdl_demo_interfaces__srv__CheckObjectInRoom_Response __attribute__((deprecated))
#else
# define DEPRECATED__rtdl_demo_interfaces__srv__CheckObjectInRoom_Response __declspec(deprecated)
#endif

namespace rtdl_demo_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CheckObjectInRoom_Response_
{
  using Type = CheckObjectInRoom_Response_<ContainerAllocator>;

  explicit CheckObjectInRoom_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->found = false;
    }
  }

  explicit CheckObjectInRoom_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->found = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _found_type =
    bool;
  _found_type found;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__found(
    const bool & _arg)
  {
    this->found = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rtdl_demo_interfaces__srv__CheckObjectInRoom_Response
    std::shared_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rtdl_demo_interfaces__srv__CheckObjectInRoom_Response
    std::shared_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CheckObjectInRoom_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->found != other.found) {
      return false;
    }
    return true;
  }
  bool operator!=(const CheckObjectInRoom_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CheckObjectInRoom_Response_

// alias to use template instance with default allocator
using CheckObjectInRoom_Response =
  rtdl_demo_interfaces::srv::CheckObjectInRoom_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rtdl_demo_interfaces

namespace rtdl_demo_interfaces
{

namespace srv
{

struct CheckObjectInRoom
{
  using Request = rtdl_demo_interfaces::srv::CheckObjectInRoom_Request;
  using Response = rtdl_demo_interfaces::srv::CheckObjectInRoom_Response;
};

}  // namespace srv

}  // namespace rtdl_demo_interfaces

#endif  // RTDL_DEMO_INTERFACES__SRV__DETAIL__CHECK_OBJECT_IN_ROOM__STRUCT_HPP_
