# Project 4: Map my world

In this project, I used the RTAB-Map ROS package to create a 2D occupancy grid and a 3D octomap from a simulated environment.
RTAB-Map (Real-Time Appearance-Based Mapping) is a popular solution for SLAM to develop robots that can map environments in 3D

## Results

### 2D Map

<p>
  <img src="https://github.com/RonaldoCD/Udacity-Robotics-Software-Engineer-Nanodegree-Projects/blob/main/Project%204:%20Map%20my%20world/my_robot/images/2D_map_env.png" width="800" title="2D Map">
</p>

### 3D Map

<p>
  <img src="https://github.com/RonaldoCD/Udacity-Robotics-Software-Engineer-Nanodegree-Projects/blob/main/Project%204:%20Map%20my%20world/my_robot/images/3D_map.png" width="800" title="3D Map">
</p>

### RTAB Viewer

<p>
  <img src="https://github.com/RonaldoCD/Udacity-Robotics-Software-Engineer-Nanodegree-Projects/blob/main/Project%204:%20Map%20my%20world/my_robot/images/Rtab_viewer.png" width="800" title="RTab Viewer">
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

3. Open another terminal (Ctrl+Shift+T), and launch the `mapping.launch` file. 
Here, the rtabmap-ros package will be launched.
```
$ source devel/setup.bash
$ roslaunch my_robot mapping.launch
```

4. Open another terminal, and run the `teleop` node.
```
$ source devel/setup.bash
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```

5. Click on this terminal, type keyboard to navigate the robot around. Navigate 
the robot to scan its surrounding environment. The rtabmap-ros package will save
the resulted map with the localized trajectory of the robot in a database file 
`~/.ros/rtabmap.db`.

6. Open another terminal, and open up the database file using `rtabmap-databaseViewer`
```
$ rtabmap-databaseViewer ~/.ros/rtabmap.db
```

* Choose View -> Constraints View and Graph View
* To see 3D Map, Choose Edit -> View 3D Map ...
