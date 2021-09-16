#include "ros/ros.h"
#include "hello_ros/test.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  // publish test.msg, a cache of 1000 message
  ros::Publisher chatter_pub = n.advertise<hello_ros::test>("chatter", 1000);
  // frequency of 10hz
  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    hello_ros::test msg;

    msg.x = 1;
    msg.y = 2;

    ROS_INFO("send x = %d, y = %d", msg.x, msg.y);

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
