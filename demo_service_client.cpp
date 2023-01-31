#include "mastering_ros_demo/demo_server.h"
#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "ros/service_client.h"
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "demo_service_client");
  ros::NodeHandle node_obj;
  ros::Rate loop_rate(10);
  ros::ServiceClient client =
      node_obj.serviceClient<mastering_ros_demo::demo_server>("demo_server");

  while (ros::ok()) {
    mastering_ros_demo::demo_server srv;
    std::stringstream ss;
    ss << "Sending from here";
    srv.request.in = ss.str();
    if (client.call(srv)) {
      ROS_INFO("From Client [%s], Server says [%s]", srv.request.in.c_str(),
               srv.response.out.c_str());
    } else {
      ROS_INFO("Failed to connect server");
      return 0;
    }
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}