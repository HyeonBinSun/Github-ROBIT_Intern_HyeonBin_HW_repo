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
#include <QTextEdit>
#include <iostream>
#include "../include/ros_qt_pub/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace ros_qt_pub
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

  void MainWindow::on_pushButton_clicked()
  {
      if(ui.textEdit->toPlainText().isEmpty()){

          QMessageBox::warning(nullptr, "Warning", "Text Empty");
          qnode.CheckS = true;
          return;
      }
      else
      {
          qnode.CheckS = false;
          qnode.pubData = ui.textEdit->toPlainText().toStdString();
          qnode.pubMsg();
          ui.textEdit->clear();
      }

  }
  /*****************************************************************************
  ** Functions
  *****************************************************************************/

}  // namespace s
