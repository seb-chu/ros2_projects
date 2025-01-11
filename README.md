### To start world
```
ros2 launch articubot_one launch_sim.launch.py
```

### To control simulated robot 
```
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```

# Notes
- Gazebo represents the real-world movements, while RViz represents the simulated world.
- make sure the caster wheel is frictionless (shown in ```robot_core.xacro``` CASTER WHEEL LINK).
- ```launch_sim.launch.py``` combines launching Rviz, Gazebo, and spawn_entity.
