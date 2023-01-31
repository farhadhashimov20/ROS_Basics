#include "mastering_ros_demo/demo_server.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include "ros/service_server.h"
#include <iostream>
#include <sstream>
using namespace std;

bool demo_service_callback(
    mastering_ros_demo::demo_server::Request &request,
    mastering_ros_demo::demo_server::Response &response) {

  std::stringstream ss;
  ss << "Recieved Here";
  response.out = ss.str();
  ROS_INFO("From Client [%s], Server says [%s]", request.in.c_str(),
           response.out.c_str());
  return true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "demo_service_server");
  ros::NodeHandle node_obj;
  ros::ServiceServer service =
      node_obj.advertiseService("demo_server", demo_service_callback);
  ROS_INFO("Service server runnning");
  ros::spin();
  return 0;
}