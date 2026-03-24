#include "rtdl_demo_bt/pick_node.hpp"

namespace rtdl_demo_bt
{

PickNode::PickNode(
  const std::string & name,
  const BT::NodeConfig & config,
  const rclcpp::Node::SharedPtr & ros_node)
: BtServiceNodeBase(name, config, ros_node)
{
  client_ = ros_node_->create_client<rtdl_demo_interfaces::srv::Pick>("/pick");
}

BT::PortsList PickNode::providedPorts()
{
  return {
    BT::InputPort<std::string>("object_name")
  };
}

BT::NodeStatus PickNode::tick()
{
  auto object_name = getInput<std::string>("object_name");
  if (!object_name) {
    throw BT::RuntimeError("missing required input [object_name]: ", object_name.error());
  }

  if (!wait_for_service<rtdl_demo_interfaces::srv::Pick>(client_, "/pick")) {
    return BT::NodeStatus::FAILURE;
  }

  auto request = std::make_shared<rtdl_demo_interfaces::srv::Pick::Request>();
  request->object_name = object_name.value();

  rtdl_demo_interfaces::srv::Pick::Response::SharedPtr response;
  if (!call_service_sync<rtdl_demo_interfaces::srv::Pick>(client_, request, response)) {
    RCLCPP_ERROR(ros_node_->get_logger(), "Call to /pick failed.");
    return BT::NodeStatus::FAILURE;
  }

  RCLCPP_INFO(
    ros_node_->get_logger(),
    "Pick(object=%s) -> success=%s, msg=%s",
    request->object_name.c_str(),
    response->success ? "true" : "false",
    response->message.c_str());

  return response->success ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}

}  // namespace rtdl_demo_bt