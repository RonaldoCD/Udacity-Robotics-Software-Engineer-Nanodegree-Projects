#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>
#include <iostream>
#include <vector>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    ROS_INFO_STREAM("Moving the robot");

    // Request centered joint angles [1.57, 1.57]
    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    // Call the safe_move service and pass the requested joint angles
    if (!client.call(srv))
        ROS_ERROR("Failed to call service safe_move");
}

std::vector<float> get_robot_vel(uint left_side_limit, uint right_side_limit, int col){
    // set linear_x and angular_z values
    std::vector<float> velocities;
    velocities.reserve(2);
    velocities.push_back(0.0);
    velocities.push_back(0.0);
    std::cout << "---------------" << "\n";
    std::cout << "Velocities start: (" << velocities[0] << "," << velocities[1] << ")\n"; 
    float ang_z = 0.4; // change value to change angular_z
    float lin_x = 0.4; // change value to change linear_x

    if (col <= left_side_limit){
        std::cout << "Left\n";
        velocities[1] = ang_z;
        
    } else if (col > left_side_limit && col < right_side_limit){
        velocities[0] = lin_x;
        std::cout << "Middle\n";

    } else{
        std::cout << "Right\n";
        velocities[1] = -ang_z;
    }
    std::cout << "Velocities end: (" << velocities[0] << "," << velocities[1] << ")\n";
    std::cout << "---------------" << "\n";
    return velocities;
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;
    int idx;
    uint left_side_limit = 0.25 * img.width;
    uint right_side_limit = 0.75 * img.width;
    float lin_x = 0.0;
    float ang_z = 0.0;
    std::vector<float> velocities;

    for (int row = img.height; row > 0; row--){
        for (int col = 0; col < img.width; col++){
            idx = (row * img.step) + (col * 3);
            if((img.data[idx] == 255) && (img.data[idx+1] == 255) && (img.data[idx+2] == 255)){
                velocities = get_robot_vel(left_side_limit, right_side_limit, col);
                lin_x = velocities[0];
                ang_z = velocities[1];
                drive_robot(lin_x, ang_z);
                return;
            }
        }
    }
    drive_robot(lin_x, ang_z);
    return;
     

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
