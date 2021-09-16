#include "ros/ros.h"
#include "hello_ros/test.h"

// callback function for listener, notice that msg is a pointer
void chatterCallback(const hello_ros::test::ConstPtr& msg)
{
  ROS_INFO("I heard: x = %d, y = %d", msg->x, msg->y);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  // subscribe from "chatter", use callback function chatterCallback
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ros::spin();

  return 0;
}
