#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

void send_move_base_goal(double point_x, double point_y, double orientation_w, MoveBaseClient & ac){
    move_base_msgs::MoveBaseGoal goal;

    // set up the frame parameters
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();

    // Define a position and orientation for the robot to reach
    goal.target_pose.pose.position.x = point_x;
    goal.target_pose.pose.position.y = point_y;
    goal.target_pose.pose.orientation.w = orientation_w;

    ROS_INFO("Sending goal");
    ac.sendGoal(goal);

    // Wait an infinite time for the results
    ac.waitForResult();

    // Check if the robot reached its goal
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
        ROS_INFO("The robot has reached the goal");
    }
    else
        ROS_INFO("The robot has failed to reach the goal");

}


int main(int argc, char** argv){
    // Initialize the simple_navigation_goals node
    ros::init(argc, argv, "pick_objects");

    ros::NodeHandle nh;
    nh.setParam("robot_at_pickup_point", false);
    nh.setParam("robot_at_dropoff_point", false);
    nh.setParam("robot_picked_object", false);
    
    double pick_up_point_x, pick_up_point_y, pick_up_orientation_w;
    double drop_off_point_x, drop_off_point_y, drop_off_orientation_w;  
    nh.getParam("pick_up_point_x", pick_up_point_x);
    nh.getParam("pick_up_point_y", pick_up_point_y);
    nh.getParam("pick_up_orientation_w", pick_up_orientation_w);
    nh.getParam("drop_off_point_x", drop_off_point_x);
    nh.getParam("drop_off_point_y", drop_off_point_y);
    nh.getParam("drop_off_orientation_w", drop_off_orientation_w);

    //tell the action client that we want to spin a thread by default
    MoveBaseClient ac("move_base", true);

    // Wait 5 sec for move_base action server to come up
    while(!ac.waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the move_base action server to come up");
    }

    // Send goal to pick up point
    send_move_base_goal(pick_up_point_x, pick_up_point_y, pick_up_orientation_w, ac);
    nh.setParam("robot_at_pickup_point", true);
    
    // Wait for 5 seconds
    ros::Duration(5).sleep();
    nh.setParam("robot_picked_object", true);
    
    // Send goal to drop off point
    send_move_base_goal(drop_off_point_x, drop_off_point_y, drop_off_orientation_w, ac);
    nh.setParam("robot_at_dropoff_point", true);
    return 0;
}