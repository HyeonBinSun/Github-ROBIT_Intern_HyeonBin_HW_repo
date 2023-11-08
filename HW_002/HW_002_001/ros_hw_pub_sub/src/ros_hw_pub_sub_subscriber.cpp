#include "ros/ros.h"
#include "ros_hw_pub_sub/hw_Msg.h" 

void msgCallback(const ros_hw_pub_sub::hw_Msg::ConstPtr& msg)
{
ROS_INFO("recieve data1 = %ld", msg->data1); 

ROS_INFO("recieve data2 = %ld", msg->data2);

ROS_INFO("recieve message = [%s]", msg->message.c_str()); 
}

int main(int argc, char **argv) 
{
ros::init(argc, argv, "ros_hw_pub_sub_subscriber");

ros::NodeHandle nh;
 
 ros_hw_pub_sub::hw_Msg msg;
 
 ros::Subscriber ros_hw_sub = nh.subscribe("hw_one_msg", 1000, msgCallback);
 
ros::spin();

return 0;
}
