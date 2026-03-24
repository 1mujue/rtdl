cmake_minimum_required(VERSION 3.8)
project(ros2_bt_action_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(behaviortree_cpp REQUIRED)
find_package(behaviortree_ros2 REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# 生成本包内的 action 接口
rosidl_generate_interfaces(${PROJECT_NAME}
  "action/Ping.action"
)

# 运行时导出接口依赖
ament_export_dependencies(rosidl_default_runtime)

# ----------------------------
# Action Server
# ----------------------------
add_executable(ping_server src/ping_server.cpp)
ament_target_dependencies(ping_server
  rclcpp
  rclcpp_action
)

# ----------------------------
# BT Executor
# ----------------------------
add_executable(bt_executor src/bt_executor.cpp)
ament_target_dependencies(bt_executor
  rclcpp
  rclcpp_action
  behaviortree_cpp
  behaviortree_ros2
)

# 因为 action 和节点在同一个 package，
# 需要把生成的 C++ typesupport 链接进来
rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

target_link_libraries(ping_server "${cpp_typesupport_target}")
target_link_libraries(bt_executor "${cpp_typesupport_target}")

install(TARGETS
  ping_server
  bt_executor
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()