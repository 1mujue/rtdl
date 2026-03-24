import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import RegisterEventHandler, EmitEvent
from launch.event_handlers import OnProcessExit
from launch.events import Shutdown
from webots_ros2_driver.webots_launcher import WebotsLauncher
from webots_ros2_driver.webots_controller import WebotsController

def generate_launch_description():
    package_dir = get_package_share_directory('rtdl_demo_webots')

    world = os.path.join(package_dir, 'worlds', 'rtdl_demo_webots.wbt')
    car_urdf = os.path.join(package_dir, 'resource', 'my_robot.urdf')
    bridge_urdf = os.path.join(package_dir, 'resource', 'bridge_robot.urdf')

    webots = WebotsLauncher(world=world)

    car_driver = WebotsController(
        robot_name='CAR',
        parameters=[
            {'robot_description': car_urdf},
        ]
    )
    bridge_driver = WebotsController(
        robot_name="BRIDGE",
        parameters=[
            {'robot_description': bridge_urdf}
        ]
    )

    return LaunchDescription([
        webots,
        car_driver,
        bridge_driver,
        RegisterEventHandler(
            OnProcessExit(
                target_action=webots,
                on_exit=[EmitEvent(event=Shutdown())],
            )
        )
    ])