cmake_minimum_required(VERSION 3.8)
project(rtdl_demo_bt)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(rtdl_demo_interfaces REQUIRED)
find_package(behaviortree_cpp REQUIRED)

add_executable(bt_runner
  src/bt_runner.cpp
  src/nav_to_node.cpp
  src/pick_node.cpp
  src/place_node.cpp
)

target_include_directories(bt_runner PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(bt_runner
  rclcpp
  ament_index_cpp
  rtdl_demo_interfaces
  behaviortree_cpp
)

install(TARGETS
  bt_runner
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

install(DIRECTORY trees/
  DESTINATION share/${PROJECT_NAME}/trees
)

ament_package()