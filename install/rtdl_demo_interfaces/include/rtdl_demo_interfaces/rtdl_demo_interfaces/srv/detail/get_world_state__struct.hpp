// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rtdl_demo_interfaces:srv/GetWorldState.idl
// generated code does not contain a copyright notice

#ifndef RTDL_DEMO_INTERFACES__SRV__DETAIL__GET_WORLD_STATE__STRUCT_HPP_
#define RTDL_DEMO_INTERFACES__SRV__DETAIL__GET_WORLD_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rtdl_demo_interfaces__srv__GetWorldState_Request __attribute__((deprecated))
#else
# define DEPRECATED__rtdl_demo_interfaces__srv__GetWorldState_Request __declspec(deprecated)
#endif

namespace rtdl_demo_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetWorldState_Request_
{
  using Type = GetWorldState_Request_<ContainerAllocator>;

  explicit GetWorldState_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetWorldState_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    rtdl_demo_interfaces::srv::GetWorldState_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const rtdl_demo_interfaces::srv::GetWorldState_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rtdl_demo_interfaces::srv::GetWorldState_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rtdl_demo_interfaces::srv::GetWorldState_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rtdl_demo_interfaces::srv::GetWorldState_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rtdl_demo_interfaces::srv::GetWorldState_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rtdl_demo_interfaces::srv::GetWorldState_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rtdl_demo_interfaces::srv::GetWorldState_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rtdl_demo_interfaces__srv__GetWorldState_Request
    std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rtdl_demo_interfaces__srv__GetWorldState_Request
    std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetWorldState_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetWorldState_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetWorldState_Request_

// alias to use template instance with default allocator
using GetWorldState_Request =
  rtdl_demo_interfaces::srv::GetWorldState_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rtdl_demo_interfaces


// Include directives for member types
// Member 'state'
#include "rtdl_demo_interfaces/msg/detail/world_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rtdl_demo_interfaces__srv__GetWorldState_Response __attribute__((deprecated))
#else
# define DEPRECATED__rtdl_demo_interfaces__srv__GetWorldState_Response __declspec(deprecated)
#endif

namespace rtdl_demo_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetWorldState_Response_
{
  using Type = GetWorldState_Response_<ContainerAllocator>;

  explicit GetWorldState_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit GetWorldState_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    state(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _state_type =
    rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator>;
  _state_type state;

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
  Type & set__state(
    const rtdl_demo_interfaces::msg::WorldState_<ContainerAllocator> & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rtdl_demo_interfaces::srv::GetWorldState_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const rtdl_demo_interfaces::srv::GetWorldState_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rtdl_demo_interfaces::srv::GetWorldState_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rtdl_demo_interfaces::srv::GetWorldState_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rtdl_demo_interfaces::srv::GetWorldState_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rtdl_demo_interfaces::srv::GetWorldState_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rtdl_demo_interfaces::srv::GetWorldState_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rtdl_demo_interfaces::srv::GetWorldState_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rtdl_demo_interfaces__srv__GetWorldState_Response
    std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rtdl_demo_interfaces__srv__GetWorldState_Response
    std::shared_ptr<rtdl_demo_interfaces::srv::GetWorldState_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetWorldState_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetWorldState_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetWorldState_Response_

// alias to use template instance with default allocator
using GetWorldState_Response =
  rtdl_demo_interfaces::srv::GetWorldState_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace rtdl_demo_interfaces

namespace rtdl_demo_interfaces
{

namespace srv
{

struct GetWorldState
{
  using Request = rtdl_demo_interfaces::srv::GetWorldState_Request;
  using Response = rtdl_demo_interfaces::srv::GetWorldState_Response;
};

}  // namespace srv

}  // namespace rtdl_demo_interfaces

#endif  // RTDL_DEMO_INTERFACES__SRV__DETAIL__GET_WORLD_STATE__STRUCT_HPP_
