/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <sstream>
#include "../include/turtle_udp_reciever/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace turtle_udp_reciever
{
  /*****************************************************************************
  ** Implementation
  *****************************************************************************/

  QNode::QNode(int argc, char** argv) : init_argc(argc), init_argv(argv)
  {
  }

  QNode::~QNode()
  {
    if (ros::isStarted())
    {
      ros::shutdown();  // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
    wait();
  }

  bool QNode::init()
  {
    ros::init(init_argc, init_argv, "turtle_udp_reciever");
    if (!ros::master::check())
    {
      return false;
    }
    ros::start();  // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    // Add your ros communications here.
    qt_control = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 30);
    start();
    return true;
  }

  void QNode::run()
  {
    ros::Rate loop_rate(33);
    while (ros::ok())
    {
      ros::spinOnce();
      loop_rate.sleep();
    }
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    Q_EMIT rosShutdown();  // used to signal the gui for a shutdown (useful to roslaunch)
  }

  void QNode::pubMsg()
  {
     // if(!CheckComu)
    //  {
          geometry_msgs::Twist msg;
          msg.angular = turtle_direc.angular;
          msg.linear = turtle_direc.linear;
          qt_control.publish(msg);
     //     CheckComu = false;
     // }
     // else
     // {
     //     return;
     // }
  }

}  // namespace s
