#include <ros/ros.h>
 
#include <dynamic_reconfigure/server.h>
#include "hello_ros/dynamicConfig.h"
 
void callback(hello_ros::dynamicConfig& config, uint32_t level) {
  ROS_INFO("Reconfigure Request: %d %f %s %s %d", 
            config.int_param, config.double_param, 
            config.str_param.c_str(), 
            config.bool_param?"True":"False", 
            config.size);
}

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "dynamic_test");
 
    dynamic_reconfigure::Server<hello_ros::dynamicConfig> server;
    dynamic_reconfigure::Server<hello_ros::dynamicConfig>::CallbackType f;
 
    f = boost::bind(&callback, _1, _2);
    server.setCallback(f);
 
    ROS_INFO("Spinning node");
    ros::spin();
    return 0;
}
