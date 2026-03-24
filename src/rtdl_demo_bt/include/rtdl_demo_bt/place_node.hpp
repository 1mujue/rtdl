#pragma once

#include <memory>
#include <string>

#include "rtdl_demo_bt/bt_service_node_base.hpp"
#include "rtdl_demo_interfaces/srv/place.hpp"

namespace rtdl_demo_bt
{

class PlaceNode : public BtServiceNodeBase
{
public:
  PlaceNode(
    const std::string & name,
    const BT::NodeConfig & config,
    const rclcpp::Node::SharedPtr & ros_node);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;

private:
  rclcpp::Client<rtdl_demo_interfaces::srv::Place>::SharedPtr client_;
};

}  // namespace rtdl_demo_bt