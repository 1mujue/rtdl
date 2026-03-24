#include "rtdl_demo_bt/check_object_in_room_node.hpp"
#include <utility>

namespace rtdl_demo_bt{
CheckObjectInRoomNode::CheckObjectInRoomNode(
        const std::string& name,
        const BT::NodeConfig& config,
        const rclcpp::Node::SharedPtr& ros_node
    ): BtServiceNodeBase(name, config, ros_node){
    client_ = 
    ros_node_->create_client<rtdl_demo_interfaces::srv::CheckObjectInRoom>(
        "/check_object_in_room"
    );
}
BT::PortsList CheckObjectInRoomNode::providedPorts(){
    return {
        BT::InputPort<std::string>("object_name"),
        BT::InputPort<std::string>("room_name")
    };
}
BT::NodeStatus CheckObjectInRoomNode::tick() {
    auto object_name = getInput<std::string>("object_name");
    auto room_name = getInput<std::string>("room_name");
    if (!object_name) {
        throw BT::RuntimeError("missing required input [object_name]: ", object_name.error());
    }
    if (!room_name) {
        throw BT::RuntimeError("missing required input [room_name]: ", room_name.error());
    }
    if(!wait_for_service<rtdl_demo_interfaces::srv::CheckObjectInRoom>(
        client_, "/check_object_in_room"
    )){
        return BT::NodeStatus::FAILURE;
    }
    auto req = 
    std::make_shared<rtdl_demo_interfaces::srv::CheckObjectInRoom::Request>();
    req->object_name = object_name.value();
    req->room_name = room_name.value();
    rtdl_demo_interfaces::srv::CheckObjectInRoom::Response::SharedPtr res;
    if(!call_service_sync<rtdl_demo_interfaces::srv::CheckObjectInRoom>(
        client_, req, res
    )){
        RCLCPP_ERROR(ros_node_->get_logger(), "Call to /check_object_in_room failed.");
        return BT::NodeStatus::FAILURE;
    }
    if(!res->success){
        RCLCPP_ERROR(
            ros_node_->get_logger(),
            "/check_object_in_room returned error: %s",
            res->message.c_str()
        );
        return BT::NodeStatus::FAILURE;
    }
    RCLCPP_INFO(
        ros_node_->get_logger(),
        "CheckObjectInRoom(object=%s, room=%s) -> found=%s",
        req->object_name.c_str(),
        req->room_name.c_str(),
        res->found? "true" : "false"
    );
    return res->found? BT::NodeStatus::SUCCESS : BT::NodeStatus::FAILURE;
}
}