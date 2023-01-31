#include "mastering_ros_demo/integer_server.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "ros/service_server.h"
#include <iostream>
#include <sstream>
using namespace std;

bool callback_function(mastering_ros_demo::integer_server::Request &req,
                       mastering_ros_demo::integer_server::Response &res) {

  res.out = req.in * 3;
  ROS_INFO("[%d] is recieved from client, [%d] is sended to client", req.in,
           res.out);
  return true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "integer_service_server");
  ros::NodeHandle node_obj;
  ros::ServiceServer service =
      node_obj.advertiseService("integer_server", callback_function);
  ROS_INFO("Server::ON");
  ros::spin();
  return 0;
}