#include "mastering_ros_demo/position.h"
#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/publisher.h"
#include "ros/ros.h"
#include <iostream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "demo_msg_publisher");
  ros::NodeHandle node_obj;
  ros::Publisher msg_publisher =
      node_obj.advertise<mastering_ros_demo::position>("/info_robot", 10);
  ros::Rate loop_rate(100000);

  while (ros::ok()) {
    mastering_ros_demo::position msg;
    msg.robot_name = "slicer";
    msg.x_pos = 32;
    msg.y_pos = 22;
    msg.z_pos = 23;
    msg_publisher.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}