### To start Gazebo without world
```
ros2 launch articubot_one launch_sim.launch.py
```

### To start Gazebo with world
```
ros2 launch articubot_one launch_sim.launch.py world:=./src/articubot_one/worlds/obstacles.world
```

### To control simulated robot 
```
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```

## Using Camera in RViZ2 and Gazebo 

### New window camera

```
ros2 run rqt_image_view rqt_image_view
```

### To have uncompressed image
```
ros2 run image_transport republish compressed raw --ros-args -r in/compressed:=/camera/image_raw/compressed -r out:=/camera/image_raw/uncompressed
```

### To check all image formats that ROS2 can see
```
ros2 run image_transport list_transports
```

# Notes
- Gazebo represents the real-world movements, while RViz represents the simulated world.
- make sure the caster wheel is frictionless (shown in ```robot_core.xacro``` CASTER WHEEL LINK).
- ```launch_sim.launch.py``` combines launching Rviz, Gazebo, and spawn_entity.
- [WANT TO USE JOYSTICK?](https://youtu.be/IjFcr5r0nMs?si=jjGV6RP34PZ4Pcl5&t=1044)

