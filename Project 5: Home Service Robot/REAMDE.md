# Project 5: Home Service Robot

In this project the robot will move to the pick-up and drop-off points of the Gazebo world. To localize itself in the environment, the robot will use the Adaptive Monte Carlo Localization algorithm (AMCL) using odometry and laser data. To do mapping the robot applies the SLAM (Simultaneous Localization and Mapping) algorithm that in our case uses data from the RGB-D camera installed in the robot. Finally, to navigate in the environment the robot uses the Dijkstra's algorithm, which is a variant from the Uniform Cost Search algorithm. 

Inside the amcl_demo.lanch file the nodes that implement localization, mapping and navigation are launched from the turtlebot_navigation package. Also, a map of the environment is provided in this file.

## Results

### Path Planning

<p>
  <img src="https://github.com/RonaldoCD/Udacity-Robotics-Software-Engineer-Nanodegree-Projects/blob/main/Project%205:%20Home%20Service%20Robot/images/path_planning.png" width="800" title="2D Map">
</p>

## Project Description  
Directory Structure  
```
.Home-Sevice-Robot                                        # Home Service Robot Project
├── catkin_ws                                             # Catkin workspace
│   ├── src
│   │   ├── add_markers                                   # add_markers package        
│   │   │   ├── launch
│   │   │   │   ├── add_markers.launch                    # launch file for add_markers node
│   │   │   ├── src
│   │   │   │   ├── add_markers.cpp                       # source code for add_markers node
│   │   │   │   ├── add_markers_by_time.cpp               # source code for add_markers_by_time node
│   │   ├── pick_objects                                  # pick_objects package     
│   │   │   ├── config
│   │   │   │   ├── goal_coordinates_params.yaml          # parameters file for goal coordinates
│   │   │   ├── launch
│   │   │   │   ├── pick_objects.launch                   # launch file for pick_objects node
│   │   │   ├── src
│   │   │   │   ├── pick_objects.cpp                      # source code for pick_objects node
│   │   ├── scripts                                       # shell scripts files
│   │   │   ├── add_marker.sh                             # shell script to add markers to rviz   
│   │   │   ├── home_service.sh                           # shell script to launch home service robot demo  
│   │   │   ├── pick_objects.sh                           # shell script to send multiple goals  
│   │   │   ├── test_navigation.sh                        # shell script to test localization and navigation
│   │   │   ├── test_slam.sh                              # shell script to test SLAM
│   │   ├── slam_gmapping                                 # gmapping_demo.launch file
│   │   ├── turtlebot                                     # keyboard_teleop.launch file
│   │   ├── turtlebot_interactions                        # view_navigation.launch file
│   │   ├── turtlebot_simulator                           # turtlebot_world.launch file package        
│   │   ├── CMakeLists.txt                                # compiler instructions
```

## Run the project  
* Clone this repository
* Navigate to the src folder and clone the necessary repositories  
```
cd RoboND-Term1-P5-Home-Service-Robot/catkin_ws/src  
git clone https://github.com/ros-perception/slam_gmapping.git  
git clone https://github.com/turtlebot/turtlebot.git  
git clone https://github.com/turtlebot/turtlebot_interactions.git  
git clone https://github.com/turtlebot/turtlebot_simulator.git  
```
* Open the repository, make and source  
```
cd /home/workspace/catkin_ws/
catkin_make
source devel/setup.bash
```
* Launch the home service robot
```
./src/scripts/home_service.sh
```
* Done. 
