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
#include "../include/ros_qt_sub/main_window.hpp"
#include <std_msgs/String.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace ros_qt_sub
{
  using namespace Qt;

  /*****************************************************************************
  ** Implementation [MainWindow]
  *****************************************************************************/

  MainWindow::MainWindow(int argc, char** argv, QWidget* parent) : QMainWindow(parent), qnode(argc, argv)
  {
    ui.setupUi(this);  // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    setWindowIcon(QIcon(":/images/icon.png"));

    qnode.init();

    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
    qRegisterMetaType<std::string>("std::string");
    QObject::connect(&qnode, SIGNAL(subSignalspt(std::string)), this, SLOT(SubBufClear(std::string)));
  }

  MainWindow::~MainWindow()
  {
  }
  void MainWindow::SubBufClear(std::string msg){
      ui.label->clear();
    ui.label->setText(QString::fromStdString(msg));
      qnode.CheckR = false;
  }

  /*****************************************************************************
  ** Functions
  *****************************************************************************/

}  // namespace s
