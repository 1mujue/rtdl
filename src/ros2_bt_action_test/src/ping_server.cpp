#include <chrono>
#include <memory>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "ros2_bt_action_test/actions/ping.hpp"

using namespace std::chrono_literals;
using Ping = ros2_bt_action_test::action::Ping;
using GoalHandlePing = relcpp_action::ServerGoalHandle<Ping>;

class PingServer: public rclcpp::Node{
public:
    PingServer()
    : Node("ping_server"){
        using namespace std::placeholders;

        action_server_ = rclcpp_action::create_server<Ping>();
    }
};