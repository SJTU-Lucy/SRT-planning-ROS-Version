#include <ros/ros.h>
#include "hello_ros/header.h"
#include "hello_ros/test.h"
#include <string>
#include <vector>

int main(int argc, char **argv) 
{ 
    ros::init(argc,argv,"hello"); 		   // 初始化ROS客户端库，"hello"为节点默认名
    ros::NodeHandle n; 				   // 创建句柄，把程序注册为节点管理器的节点
    Header test;
    test.print();
    ROS_INFO("Hello ROS!");			   // ROS流信息，输出到控制台并打印

    // double ret;
    // n.getParam("test", ret);
    // ROS_INFO("value of the parameter is............... %f", ret);

    double noise;
    if(n.getParam("noise", noise))
        ROS_INFO("noise is %f", noise);

    std::string string_var;
    if (n.getParam("string_var", string_var))
        ROS_INFO("string_var: %s", string_var.c_str());

    std::vector<int> vector_var;
    if (n.getParam("vector_var",vector_var))
        ROS_INFO("got vector");
    ros::spinOnce(); 			           // 信息回调处理函数
}
