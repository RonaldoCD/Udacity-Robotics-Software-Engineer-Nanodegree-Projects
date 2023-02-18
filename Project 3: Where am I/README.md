# Project 3: Where am I

Welcome to the Where Am I? localization project! In this project, I used the ROS AMCL package to accurately localize a mobile robot inside a map in a Gazebo simulation environment.

## Results

### Localized robot

<p>
  <img src="https://github.com/RonaldoCD/Udacity-Robotics-Software-Engineer-Nanodegree-Projects/blob/main/Project%203:%20Where%20am%20I/images/Localized%203.png" width="800" title="2D Map">
</p>

### Unlocalized robot

<p>
  <img src="https://github.com/RonaldoCD/Udacity-Robotics-Software-Engineer-Nanodegree-Projects/blob/main/Project%203:%20Where%20am%20I/images/Unlocalized.png" width="800" title="3D Map">
</p>


## Build and Launch

1. Move back to `catkin_ws\` and build
```
$ cd ..
$ catkin_make
```

2. Launch the world and robot
```
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```

3. Open another terminal (Ctrl+Shift+T), and launch the `amcl.launch` file. Here,
the map_server, amcl, and move_back packages will be launched.
```
$ source devel/setup.bash
$ roslaunch my_robot amcl.launch
```

4. Open another terminal, and run the `teleop` node.
```
$ source devel/setup.bash
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

5. Click on this terminal, type keyboard to navigate the robot around. The 
localization algorithm will update particles as the robot pose is updated.

6. Click on the Gazebo window and kidnap the robot to a random position in the
house. Let the robot rotate for a while, it can quickly localize.
