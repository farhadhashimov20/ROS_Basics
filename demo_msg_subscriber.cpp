#include "mastering_ros_demo/position.h"
#include "ros/forwards.h"
#include "ros/ros.h"
#include <iostream>
void callback_function(const mastering_ros_demo::position::ConstPtr &msg) {
  ROS_INFO("Received [%d]", msg->x_pos);
}
int main(int argc, char **argv) {
  ros::init(argc, argv, "demo_msg_subscriber");
  ros::NodeHandle node_obj;
  ros::Subscriber msg_subscriber =
      node_obj.subscribe("/info_robot", 10, callback_function);
  ros::spin();
  return 0;
}