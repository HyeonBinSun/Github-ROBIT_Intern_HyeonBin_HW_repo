#include "ros/ros.h"
#include "ros_hw_pub_sub/hw_Msg.h"
#include <stdio.h>

using namespace std;

int main(int argc, char **argv) 
{
ros::init(argc, argv, "ros_hw_pub_sub_publisher");

 ros::NodeHandle nh; 
 
ros::Publisher ros_hw_pub = nh.advertise<ros_hw_pub_sub::hw_Msg>("hw_one_msg", 100);

ros::Rate loop_rate(50);

ros_hw_pub_sub::hw_Msg msg;

while (ros::ok())
{
    msg.stamp = ros::Time::now();
    cin >> msg.data1;
    cin >> msg.data2;
    cin >> msg.message;

if(cin.fail() || cin.bad())
{
    ROS_ERROR("ERROR %d : Try Again", 0);
    cin.clear();
    cin.ignore(100, '\n');
    continue;
}

ROS_INFO("send data1 = %ld", msg.data1); 

ROS_INFO("send data2 = %ld", msg.data2);

ROS_INFO("send message = %s", msg.message.c_str()); 

ros_hw_pub.publish(msg);

ros::spinOnce();
loop_rate.sleep();

}

return 0;

}
