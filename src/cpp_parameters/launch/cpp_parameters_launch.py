from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="cpp_parameters",
            executable="minimal_param_node",
            name="custom_minimal_param_node",
            output="screen", # ensures output printed to console.
            emulate_tty=True, # ensures output printed to console.
            parameters=[
                {"my_parameter": "earth"}
            ]
        )
    ])