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
#include "rtdl_demo_interfaces/srv/check_object_in_room.hpp"
#include "rtdl_demo_interfaces/srv/get_world_state.hpp"
#include "rtdl_demo_interfaces/srv/nav_to.hpp"
#include "rtdl_demo_interfaces/srv/pick.hpp"
#include "rtdl_demo_interfaces/srv/pick_pri.hpp"
#include "rtdl_demo_interfaces/srv/place.hpp"
#include "rtdl_demo_interfaces/srv/place_pri.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

struct RoomInfo{
    std::string name;
    double nav_x;
    double nav_y;
};

struct SupportInfo{
    std::string name;
    std::string room;
    double x;
    double y;
};

struct ObjectInfo{
    std::string name;
    std::string room;
    std::string support;
    bool held_by_robot;
};

class SkillServer: public rclcpp::Node{
public:
    SkillServer() : Node("skill_server"){
        check_object_in_room_srv_ = 
        this->create_service<rtdl_demo_interfaces::srv::CheckObjectInRoom>(
            "/check_object_in_room",
            std::bind(&SkillServer::handle_check_object_in_room, this, _1, _2)
        );

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
        if (!response->success) {
            RCLCPP_ERROR(
            this->get_logger(),
            "/get_world_state returned failure: %s",
            response->message.c_str());
            return false;
        }

        state = response->state;
        return true;
    }

    void handle_check_object_in_room(
        const std::shared_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom::Request> req,
        std::shared_ptr<rtdl_demo_interfaces::srv::CheckObjectInRoom::Response> res
    ) {
        rtdl_demo_interfaces::msg::WorldState state;
        if(!query_world_state(state)){
            res->success = false;
            res->found = false;
            res->message = "Failed to query real world state.";
            return;
        }

        for(const auto& obj: state.objects){
            if(obj.name == req->object_name){
                res->success = true;
                res->found = (obj.room == req->room_name);
                res->message = res->found? "Object found in room." : "Object not in room.";
                return;
            }
        }
        res->success = false;
        res->found = false;
        res->message = "Unknown object: " + req->object_name;
    }
    static double normalize_angle(double angle){
        while(angle > M_PI) angle -= 2.0 * M_PI;
        while(angle < -M_PI) angle += 2.0 * M_PI;
        return angle;
    }
    void publish_cmd(double lx, double angz){
        geometry_msgs::msg::Twist cmd;
        cmd.linear.x = lx;
        cmd.angular.z = angz;
        cmd_vel_pub_->publish(cmd);
    }
    void stop_robot(){
        publish_cmd(0.0, 0.0);
    }
    bool room_goal(const std::string& room_name, double& goal_x, double& goal_y){
        if(room_name == "living_room"){
            goal_x = 0.5;
            goal_y = 0.0;
            return true;
        } 
        else if(room_name == "kitchen"){
            goal_x = -0.5;
            goal_y = 0;
            return true;
        }
        return false;
    }
    void handle_nav_to(
        const std::shared_ptr<rtdl_demo_interfaces::srv::NavTo::Request> request,
        std::shared_ptr<rtdl_demo_interfaces::srv::NavTo::Response> response)
        {
        double goal_x = 0.0;
        double goal_y = 0.0;

        if (!room_goal(request->room_name, goal_x, goal_y)) {
            response->success = false;
            response->message = "Unknown room: " + request->room_name;
            return;
        }

        constexpr double kLin = 0.8;
        constexpr double kAng = 1.5;
        constexpr double kMaxLin = 0.3;
        constexpr double kGoalTolerance = 0.08;
        constexpr double kHeadingThreshold = 0.3;
        constexpr int kMaxSteps = 400;

        for (int i = 0; i < kMaxSteps; ++i) {
            rtdl_demo_interfaces::msg::WorldState state;
            if (!query_world_state(state)) {
            stop_robot();
            response->success = false;
            response->message = "Failed to query world state during navigation.";
            return;
            }

            const double dx = goal_x - state.robot_x;
            const double dy = goal_y - state.robot_y;
            const double distance = std::sqrt(dx * dx + dy * dy);

            if (distance < kGoalTolerance) {
            stop_robot();
            response->success = true;
            response->message = "Reached room: " + request->room_name;
            return;
            }

            const double goal_heading = std::atan2(dy, dx);
            const double heading_error = normalize_angle(goal_heading - state.robot_yaw);

            double linear_x = 0.0;
            double angular_z = 0.0;

            if (std::abs(heading_error) > kHeadingThreshold) {
            linear_x = 0.0;
            angular_z = kAng * heading_error;
            } else {
            linear_x = std::min(kLin * distance, kMaxLin);
            angular_z = kAng * heading_error;
            }

            publish_cmd(linear_x, angular_z);
            rclcpp::sleep_for(std::chrono::milliseconds(100));
        }

        stop_robot();
        response->success = false;
        response->message = "Navigation timeout while going to room: " + request->room_name;
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

private:
    rclcpp::Service<rtdl_demo_interfaces::srv::CheckObjectInRoom>::SharedPtr check_object_in_room_srv_;
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