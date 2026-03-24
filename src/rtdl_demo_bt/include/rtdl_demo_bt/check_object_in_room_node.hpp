#pragma once

#include <memory>
#include <string>

#include "rtdl_demo_bt/bt_service_node_base.hpp"
#include "rtdl_demo_interfaces/srv/check_object_in_room.hpp"

namespace rtdl_demo_bt{
class CheckObjectInRoomNode: public BtServiceNodeBase{
public:
    CheckObjectInRoomNode(
        const std::string& name,
        const BT::NodeConfig& config,
        const rclcpp::Node::SharedPtr& ros_node
    );
    
    static BT::PortsList providedPorts();
    BT::NodeStatus tick() override;
private:
    rclcpp::Client<rtdl_demo_interfaces::srv::CheckObjectInRoom>::SharedPtr client_;
};
}