#include "rtdl_demo_bt/nav_to_node.hpp"

namespace rtdl_demo_bt{
NavToNode::NavToNode(
    const std::string& name,
    const BT::NodeConfig& config,
    const rclcpp::Node::SharedPtr& ros_node
) : BtServiceNodeBase(name, config, ros_node){
    client_ = ros_node_->create_client<rtdl_demo_interfaces::srv::NavTo>("/nav_to");
}
BT::PortsList NavToNode::providedPorts(){
    return {
        BT::InputPort<std::string>("room_name")
    };
}
BT::NodeStatus NavToNode::tick() {
    auto room_name = getInput<std::string>("room_name");
    if (!room_name) {
        throw BT::RuntimeError("missing required input [room_name]: ", room_name.error());
    }
    if(!wait_for_service<rtdl_demo_interfaces::srv::NavTo>(client_, "/nav_to")){
        return BT::NodeStatus::FAILURE;
    }
    auto req = std::make_shared<rtdl_demo_interfaces::srv::NavTo::Request>();
    req->room_name = room_name.value();

    rtdl_demo_interfaces::srv::NavTo::Response::SharedPtr res;
    if (!call_service_sync<rtdl_demo_interfaces::srv::NavTo>(client_, req, res)) {
        RCLCPP_ERROR(ros_node_->get_logger(), "Call to /nav_to failed.");
        return BT::NodeStatus::FAILURE;
    }

    RCLCPP_INFO(
    ros_node_->get_logger(),
    "NavTo(room=%s) -> success=%s, msg=%s",
    req->room_name.c_str(),
    res->success ? "true" : "false",
    res->message.c_str());

    return res->success ? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
};
}