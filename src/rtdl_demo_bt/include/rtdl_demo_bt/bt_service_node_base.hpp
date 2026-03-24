#pragma once

#include <chrono>
#include <memory>
#include <string>

#include "behaviortree_cpp/action_node.h"
#include "rclcpp/rclcpp.hpp"

namespace rtdl_demo_bt
{

class BtServiceNodeBase : public BT::SyncActionNode
{
public:
  BtServiceNodeBase(
        const std::string & name,
        const BT::NodeConfig & config,
        const rclcpp::Node::SharedPtr & ros_node)
    : BT::SyncActionNode(name, config), ros_node_(ros_node)
    {
    }

protected:
    template<typename ServiceT>
    bool wait_for_service(
        const typename rclcpp::Client<ServiceT>::SharedPtr & client,
        const std::string & service_name,
        std::chrono::milliseconds timeout = std::chrono::seconds(2))
    {
        if (!client->wait_for_service(timeout)) {
        RCLCPP_ERROR(
            ros_node_->get_logger(),
            "Service [%s] is not available.",
            service_name.c_str());
        return false;
        }
        return true;
    }

    template<typename ServiceT>
    bool call_service_sync(
        const typename rclcpp::Client<ServiceT>::SharedPtr & client,
        const typename ServiceT::Request::SharedPtr & request,
        typename ServiceT::Response::SharedPtr & response_out,
        std::chrono::milliseconds timeout = std::chrono::seconds(5))
    {
        auto future = client->async_send_request(request);
        auto ret = rclcpp::spin_until_future_complete(ros_node_, future, timeout);
        if (ret != rclcpp::FutureReturnCode::SUCCESS) {
        return false;
        }
        response_out = future.get();
        return true;
    }

    rclcpp::Node::SharedPtr ros_node_;
};

}  // namespace rtdl_demo_bt