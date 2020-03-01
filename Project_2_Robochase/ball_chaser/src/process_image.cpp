#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>


ros::ServiceClient client;


void drive_robot(float lin_x, float ang_z)
{
    
    ball_chaser::DriveToTarget service;
    service.request.linear_x = lin_x;
    service.request.angular_z = ang_z;
    
    if (!client.call(service)) {
        ROS_ERROR("Failed to call service command_robot");
    }
}


void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;
    bool is_ball_found = false;
    float lin_x = 0;
    float ang_z = 0;
    for (int i = 0; i < img.height * img.step; i += 3) {
	if (img.data[i] == white_pixel && img.data[i + 1] == white_pixel && img.data[i + 2] == white_pixel) {
	    is_ball_found = true;
	    int row_found = i % img.step;
	    if (row_found < img.step / 3) {
            // Turn Left
            lin_x = 0.0;
            ang_z = 0.2;
	    }
	    else if (row_found > img.step * 2 / 3) {
            // Turn Right
            lin_x = 0.0;
            ang_z = -0.2;
	    }
	    else {
            // Move Forward
            lin_x = 0.5;
    		ang_z = 0.0;
	    }
	        break;
        }
    }	
    drive_robot(lin_x, ang_z);
}

int main(int argc, char** argv)
{

    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");


    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    ros::spin();

    return 0;
}
