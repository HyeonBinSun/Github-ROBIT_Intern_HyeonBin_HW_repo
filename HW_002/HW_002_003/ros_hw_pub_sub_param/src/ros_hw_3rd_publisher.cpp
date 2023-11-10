#include "ros/ros.h"
#include "ros_hw_pub_sub_param/hw_Msg.h"
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char **argv) 
{
ros::init(argc, argv, "ros_hw_3rd_publisher");

 ros::NodeHandle nh; 
 
ros::Publisher ros_hw_pub_3rd = nh.advertise<ros_hw_pub_sub_param::hw_Msg>("hw_one_msg", 100);

ros::Rate loop_rate(50);

ros_hw_pub_sub_param::hw_Msg msg;

std::string message;
int data1, data2;

while (ros::ok())
{
nh.getParam("DATA1", data1);
nh.getParam("DATA2", data2);
nh.getParam("MESSAGE", message);

ROS_INFO("send data1 = %d", data1);

ROS_INFO("send data2 = %d", data2);

ROS_INFO("send message = %s", message.c_str());

msg.data1 = data1;
msg.data2 = data2;
msg.message = message;

ros_hw_pub_3rd.publish(msg);

ros::spinOnce();
loop_rate.sleep();

}

return 0;

}
