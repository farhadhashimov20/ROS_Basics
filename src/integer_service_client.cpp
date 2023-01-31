#include "mastering_ros_demo/integer_server.h"
#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "ros/service_client.h"
#include <iostream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "integer_service_client");
  ros::NodeHandle node_obj;
  ros::ServiceClient client =
      node_obj.serviceClient<mastering_ros_demo::integer_server>(
          "integer_server");
  ros::Rate loop_rate(0.5);
  int a = 32;
  while (ros::ok()) {

    mastering_ros_demo::integer_server srv;
    srv.request.in = a;
    if (client.call(srv)) {
      ROS_INFO("Sending [%d], getting [%d]", srv.request.in, srv.response.out);
    } else {
      ROS_INFO("Error::Can't reach server");
    }
    ++a;
    ros::spinOnce();
    loop_rate.sleep();
  }
}