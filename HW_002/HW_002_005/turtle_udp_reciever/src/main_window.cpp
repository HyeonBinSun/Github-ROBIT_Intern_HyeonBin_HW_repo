/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include <string>
#include "../include/turtle_udp_reciever/main_window.hpp"
#include <QByteArray>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace turtle_udp_reciever
{
  using namespace Qt;

  /*****************************************************************************
  ** Implementation [MainWindow]
  *****************************************************************************/

  MainWindow::MainWindow(int argc, char** argv, QWidget* parent) : QMainWindow(parent), qnode(argc, argv)
  {
    ui.setupUi(this);  // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    setWindowIcon(QIcon(":/images/icon.png"));

    myIP = QHostAddress("192.168.0.63");
    yourIP = QHostAddress("192.168.0.73");

    PORT =  5000;

    receive_Socket = new QUdpSocket;

    if(receive_Socket->bind(myIP), PORT){
        connect(receive_Socket, SIGNAL(readyRead()), this, SLOT(sub_udp()));
    }

    qnode.init();

    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
  }

  MainWindow::~MainWindow()
  {
  }

  void MainWindow::sub_udp()
  {
      udp::UDP udpfunc;

      int Value = 0;
     QByteArray key_data = udpfunc.UdpReadQByteArray(PORT, yourIP, *receive_Socket);

      Value = (int)(key_data[1] - 48);

      if(key_data[0] == 'A' || key_data[0] == 'L')
      {
          qnode.turtle_direc.angular.z = Value;
          qnode.turtle_direc.linear.x = 0;
      }
      else if(key_data[0] == 'D' || key_data[0] == 'R')
      {
          qnode.turtle_direc.angular.z = Value;
          qnode.turtle_direc.linear.x = 0;
      }￣
      else if(key_data[0] == 'W' || key_data[0] == 'F')
      {
          qnode.turtle_direc.linear.x = Value;
          qnode.turtle_direc.angular.z = 0;
      }
      else if(key_data[0] == 'S' || key_data[0] == 'B')
      {
          qnode.turtle_direc.linear.x = Value;
          qnode.turtle_direc.angular.z = 0;
      }
              qnode.pubMsg();
  }
  /*****************************************************************************
  ** Functions
  *****************************************************************************/

}  // namespace s
