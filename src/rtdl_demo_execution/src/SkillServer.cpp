#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

#include "geometry_msgs/msg/twist.hpp"

#include "rclcpp/rclcpp.hpp"

#include "rtdl_demo_interfaces/msg/object_state.hpp"
#include "rtdl_demo_interfaces/msg/world_state.hpp"
#include "rtdl_demo_interfaces/srv/get_world_state.hpp"
#include "rtdl_demo_interfaces/srv/nav_to.hpp"
#include "rtdl_demo_interfaces/srv/pick.hpp"
#include "rtdl_demo_interfaces/srv/pick_pri.hpp"
#include "rtdl_demo_interfaces/srv/place.hpp"
#include "rtdl_demo_interfaces/srv/place_pri.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

static double normalize_angle(double angle){
    while(angle > M_PI) angle -= 2.0 * M_PI;
    while(angle < -M_PI) angle += 2.0 * M_PI;
    return angle;
}

class SkillServer: public rclcpp::Node{
public:
    SkillServer() : Node("skill_server"){
        nav_to_srv_ = 
        this->create_service<rtdl_demo_interfaces::srv::NavTo>(
            "/nav_to",
            std::bind(&SkillServer::handle_nav_to, this, _1, _2)
        );

        pick_srv_ = 
        this->create_service<rtdl_demo_interfaces::srv::Pick>(
            "/pick",
            std::bind(&SkillServer::handle_pick, this, _1, _2)
        );

        place_srv_ = 
        this->create_service<rtdl_demo_interfaces::srv::Place>(
            "/place",
            std::bind(&SkillServer::handle_place, this, _1, _2)
        );

        client_group_ = 
        this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);

        get_world_state_client_ = 
        this->create_client<rtdl_demo_interfaces::srv::GetWorldState>(
            "/get_world_state",
            rmw_qos_profile_services_default,
            client_group_
        );

        pick_pri_client_ = 
        this->create_client<rtdl_demo_interfaces::srv::PickPri>(
            "/pick_pri",
            rmw_qos_profile_services_default,
            client_group_
        );

        place_pri_client_ = 
        this->create_client<rtdl_demo_interfaces::srv::PlacePri>(
            "/place_pri",
            rmw_qos_profile_services_default,
            client_group_
        );

        cmd_vel_pub_ =
        this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

        RCLCPP_INFO(this->get_logger(), "SkillServer started.");
    }
private:
    void publish_cmd(double lx, double angz){
        geometry_msgs::msg::Twist cmd;
        cmd.linear.x = lx;
        cmd.angular.z = angz;
        cmd_vel_pub_->publish(cmd);
    }
    void stop_robot(){
        publish_cmd(0.0, 0.0);
    }
    void handle_pick(
        const std::shared_ptr<rtdl_demo_interfaces::srv::Pick::Request> req,
        std::shared_ptr<rtdl_demo_interfaces::srv::Pick::Response> res
    ) {
        using namespace std::chrono_literals;

        if (!pick_pri_client_->wait_for_service(2s)) {
            res->success = false;
            RCLCPP_ERROR(this->get_logger(), "/pick_pri service is not available.");
            res->message = "/pick failed to call /pick_pri service.";
            return;
        }

        auto pri_req =
            std::make_shared<rtdl_demo_interfaces::srv::PickPri::Request>();
        pri_req->object_name = req->object_name;

        auto future = pick_pri_client_->async_send_request(pri_req);

        if (future.wait_for(2s) != std::future_status::ready) {
            res->success = false;
            RCLCPP_ERROR(this->get_logger(), "Timeout while waiting for /pick_pri.");
            res->message = "/pick_pri go timeout when called by /pick";
            return;
        }

        auto pri_res = future.get();
        res->success = pri_res->success;
        res->message = pri_res->message;
    }
    void handle_place(
        const std::shared_ptr<rtdl_demo_interfaces::srv::Place::Request> req,
        std::shared_ptr<rtdl_demo_interfaces::srv::Place::Response> res
    ) {
        using namespace std::chrono_literals;

        if (!place_pri_client_->wait_for_service(2s)) {
            res->success = false;
            RCLCPP_ERROR(this->get_logger(), "/place_pri service is not available.");
            res->message = "/place failed to call /place_pri service.";
            return;
        }

        auto pri_req =
            std::make_shared<rtdl_demo_interfaces::srv::PlacePri::Request>();

        pri_req->object_name = req->object_name;
        pri_req->location_name = req->location_name;

        auto future = place_pri_client_->async_send_request(pri_req);

        if (future.wait_for(2s) != std::future_status::ready) {
            res->success = false;
            RCLCPP_ERROR(this->get_logger(), "Timeout while waiting for /place_pri.");
            res->message = "/place_pri go timeout when called by /place";
            return;
        }

        auto pri_res = future.get();
        res->success = pri_res->success;
        res->message = pri_res->message;
    }
    void handle_nav_to(
    const std::shared_ptr<rtdl_demo_interfaces::srv::NavTo::Request> req,
    std::shared_ptr<rtdl_demo_interfaces::srv::NavTo::Response> res)
    {
        const double goal_x = req->x;
        const double goal_y = req->y;
        const double kGoalTolerance = req->tolerance;
        const std::string robot_name = req->robot_name;

        constexpr double kHeadingThreshold = 0.30;
        constexpr double kLin = 0.8;
        constexpr double kAng = 1.5;
        constexpr double kMaxLin = 0.3;
        constexpr double kMaxAng = 1.2;
        constexpr int kMaxSteps = 400;
        constexpr auto kControlPeriod = std::chrono::milliseconds(100);

        RCLCPP_INFO(
            this->get_logger(),
            "NavTo start: goal=(%.3f, %.3f)",
            goal_x, goal_y);

        for (int i = 0; i < kMaxSteps; ++i) {
            rtdl_demo_interfaces::msg::WorldState state;
            if (!query_world_state(state)) {
                stop_robot();
                res->success = false;
                res->message = "Failed to query world state during navigation.";
                return;
            }

            rtdl_demo_interfaces::msg::RobotState rob_state;
            bool isFind = false;
            for(const auto& it: state.robots){
                if(it.name == robot_name){
                    rob_state = it;
                    isFind = true;
                    break;
                }
            }

            if(!isFind){
                RCLCPP_ERROR(
                    this->get_logger(), "can't find robot called %s in the world.",
                    robot_name.c_str()
                );
                return;
            }

            const double dx = goal_x - rob_state.x;
            const double dy = goal_y - rob_state.y;
            const double distance = std::sqrt(dx * dx + dy * dy);

            if (distance < kGoalTolerance) {
                stop_robot();
                res->success = true;
                res->message = "Reached target.";
                RCLCPP_INFO(
                    this->get_logger(),
                    "NavTo success: robot=(%.3f, %.3f), goal=(%.3f, %.3f)",
                    rob_state.x, rob_state.y, goal_x, goal_y);
                return;
            }

            const double goal_heading = std::atan2(dy, dx);
            const double heading_error =
            normalize_angle(goal_heading - rob_state.yaw);

            double linear_x = 0.0;
            double angular_z = 0.0;

            if (std::abs(heading_error) > kHeadingThreshold) {
                linear_x = 0.0;
                angular_z = kAng * heading_error;
            } else {
                linear_x = std::min(kLin * distance, kMaxLin);
                angular_z = kAng * heading_error;
            }

            angular_z = std::clamp(angular_z, -kMaxAng, kMaxAng);

            publish_cmd(linear_x, angular_z);
            rclcpp::sleep_for(kControlPeriod);
        }

        stop_robot();
        res->success = false;
        res->message = "Navigation timeout.";
        RCLCPP_WARN(
            this->get_logger(),
            "NavTo timeout: goal=(%.3f, %.3f)",
            goal_x, goal_y);
    }
    bool query_world_state(rtdl_demo_interfaces::msg::WorldState & state)
    {
        using namespace std::chrono_literals;

        if (!get_world_state_client_->wait_for_service(2s)) {
            RCLCPP_ERROR(this->get_logger(), "/get_world_state service is not available.");
            return false;
        }

        auto request =
            std::make_shared<rtdl_demo_interfaces::srv::GetWorldState::Request>();

        auto future = get_world_state_client_->async_send_request(request);

        if (future.wait_for(2s) != std::future_status::ready) {
            RCLCPP_ERROR(this->get_logger(), "Timeout while waiting for /get_world_state.");
            return false;
        }

        auto response = future.get();
        if (!response || !response->success) {
            RCLCPP_ERROR(this->get_logger(), "Failed to get world state.");
            return false;
        }

        state = response->state;
        return true;
    }
private:
    rclcpp::Service<rtdl_demo_interfaces::srv::NavTo>::SharedPtr nav_to_srv_;
    rclcpp::Service<rtdl_demo_interfaces::srv::Pick>::SharedPtr pick_srv_;
    rclcpp::Service<rtdl_demo_interfaces::srv::Place>::SharedPtr place_srv_;

    rclcpp::Client<rtdl_demo_interfaces::srv::GetWorldState>::SharedPtr get_world_state_client_;
    rclcpp::CallbackGroup::SharedPtr client_group_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::Client<rtdl_demo_interfaces::srv::PickPri>::SharedPtr pick_pri_client_;
    rclcpp::Client<rtdl_demo_interfaces::srv::PlacePri>::SharedPtr place_pri_client_;
};

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SkillServer>();
    rclcpp::executors::MultiThreadedExecutor executor(
        rclcpp::ExecutorOptions(), 2
    );
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}