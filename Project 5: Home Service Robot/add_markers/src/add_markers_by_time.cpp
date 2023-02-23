#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

void set_marker_coordinates(visualization_msgs::Marker & marker, double point_x, double point_y, double orientation_w){
	marker.pose.position.x = point_x;
    marker.pose.position.y = point_y;
    marker.pose.orientation.w = orientation_w;
}

int main( int argc, char** argv )
{
	ros::init(argc, argv, "add_markers_by_time");
	ros::NodeHandle nh;
	ros::Rate r(1);
	ros::Publisher marker_pub = nh.advertise<visualization_msgs::Marker>("visualization_marker", 1);

	double pick_up_point_x, pick_up_point_y, pick_up_orientation_w;
	double drop_off_point_x, drop_off_point_y, drop_off_orientation_w;  
	
    pick_up_point_x = -4.0;
    pick_up_point_y = 2.0;
    pick_up_orientation_w = 1.0;
    drop_off_point_x = 4.0;
    drop_off_point_y = -4.0;
    drop_off_orientation_w = 1.0;


	// Set shape type to be a cube
	visualization_msgs::Marker marker;
	marker.type = visualization_msgs::Marker::CUBE;
	marker.header.frame_id = "map";

	// Set the namespace and id for this marker.  This serves to create a unique ID
	// Any marker sent with the same namespace and id will overwrite the old one
	marker.ns = "add_markers";
	marker.id = 0;

	// Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
	set_marker_coordinates(marker, pick_up_point_x, pick_up_point_y, pick_up_orientation_w);

	// Set the scale of the marker -- 1x1x1 here means 1m on a side
	marker.scale.x = 0.3;
	marker.scale.y = 0.3;
	marker.scale.z = 0.2;

	// Set the color -- be sure to set alpha to something non-zero!
	marker.color.r = 1.0f;
	marker.color.g = 0.0f;
	marker.color.b = 0.0f;
	marker.color.a = 1.0;

	while (ros::ok())
	{
		while (marker_pub.getNumSubscribers() < 1)
		{
			if (!ros::ok())
			{
				return 0;
			}
			ROS_WARN_ONCE("Please create a subscriber to the marker!!");
			sleep(1);
		}

		// Set the frame ID and timestamp
		marker.header.stamp = ros::Time::now();

		// Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
		marker.action = visualization_msgs::Marker::ADD;

		marker.lifetime = ros::Duration();

		// Publish the marker
		
        ROS_INFO("Publishing pick up marker");
		marker_pub.publish(marker);
        ros::Duration(5).sleep();

        ROS_INFO("Deleting marker");
        marker.action = visualization_msgs::Marker::DELETE;
        marker_pub.publish(marker);
        ros::Duration(5).sleep();

        marker.action = visualization_msgs::Marker::ADD;
        set_marker_coordinates(marker, drop_off_point_x, drop_off_point_y, drop_off_orientation_w);

        ROS_INFO("Publishing drop-off marker");

		marker_pub.publish(marker);
		ros::Duration(5).sleep();

        
        // ros::Duration(5).sleep();

        return 0;

	}  // end of while



	// DELETE MARKER
	


	// ADD MARKER AT DROP OFF ZONE
	// Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
	
	
}




