# Project 2: Go chase it
This project consists in designing and building a mobile robot and house it in the world environment designed in the previous project. Then, program the robot with C++ nodes in ROS to chase a while colored ball.


![Go chase it](https://github.com/RonaldoCD/Udacity-Robotics-Software-Engineer-Nanodegree-Projects/blob/main/Project%202:%20Go%20chase%20it/images/go_chase_it_video.mp4)

## Project structure

```
.Project2                          # Go Chase It Project
    ├── my_robot                       # my_robot package                   
    │   ├── launch                     # launch folder for launch files   
    │   │   ├── robot_description.launch
    │   │   ├── world.launch
    │   ├── meshes                     # meshes folder for sensors
    │   │   ├── hokuyo.dae
    │   ├── urdf                       # urdf folder for xarco files
    │   │   ├── my_robot.gazebo
    │   │   ├── my_robot.xacro
    │   ├── world                      # world folder for world files
    │   │   ├── my_world.world
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info
    ├── ball_chaser                    # ball_chaser package                   
    │   ├── launch                     # launch folder for launch files   
    │   │   ├── ball_chaser.launch
    │   ├── src                        # source folder for C++ scripts
    │   │   ├── drive_bot.cpp
    │   │   ├── process_images.cpp
    │   ├── srv                        # service folder for ROS services
    │   │   ├── DriveToTarget.srv
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info                  
    └──             
```

## Build and Launch

1. Clone and initialize project with a catkin workspace
```console
$ mkdir catkin_ws && cd catkin_ws
$ git clone https://github.com/RonaldoCD/Udacity-Robotics-Software-Engineer-Nanodegree-Projects.git
$ mv Udacity-Robotics-Software-Engineer-Nanodegree-Projects src
$ cd src && catkin_init_workspace
```

2. Move back to `catkin_ws\` and build
```
$ cd ..
$ catkin_make
```

3. Launch the world
```
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```

4. Open another terminal (Ctrl+Shift+T), and launch the `ball_chaser` package
```
$ source devel/setup.bash
$ roslaunch ball_chaser ball_chaser.launch
```

5. Play around! Pick up the white ball and place in front of the mobile robot. The robot will follow the ball.

## Prerequisites

Install Gazebo and ROS on Linux