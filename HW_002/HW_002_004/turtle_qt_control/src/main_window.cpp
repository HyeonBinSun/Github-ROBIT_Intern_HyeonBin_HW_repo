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
#include "../include/turtle_qt_control/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace turtle_qt_control
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
  }

  MainWindow::~MainWindow()
  {
  }
void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_A)
    {
       qnode.turtle_direc.angular.z = -2;
       qnode.turtle_direc.linear.x = 0;
       qnode.pubMsg();
    }
    if(event->key() == Qt::Key_D)
    {
       qnode.turtle_direc.angular.z = 2;
       qnode.turtle_direc.linear.x = 0;
       qnode.pubMsg();
    }
    if(event->key() == Qt::Key_W)
    {
       qnode.turtle_direc.linear.x = 2;
       qnode.turtle_direc.angular.z = 0;
       qnode.pubMsg();
    }
    if(event->key() == Qt::Key_S)
    {
       qnode.turtle_direc.linear.x = -2;
       qnode.turtle_direc.angular.z = 0;
       qnode.pubMsg();
    }

}
  void MainWindow::on_leftButton_clicked(){
      qnode.turtle_direc.angular.z = -2;
      qnode.turtle_direc.linear.x = 0;
      qnode.pubMsg();
  }
  void MainWindow::on_rightButton_clicked(){
      qnode.turtle_direc.angular.z = 2;
      qnode.turtle_direc.linear.x = 0;
      qnode.pubMsg();
  }
  void MainWindow::on_frontButton_clicked(){
      qnode.turtle_direc.linear.x = 2;
      qnode.turtle_direc.angular.z = 0;
      qnode.pubMsg();
  }

  void MainWindow::on_backButton_clicked(){
      qnode.turtle_direc.linear.x = -2;
      qnode.turtle_direc.angular.z = 0;
      qnode.pubMsg();
  }

  /*****************************************************************************
  ** Functions
  *****************************************************************************/

}  // namespace s
