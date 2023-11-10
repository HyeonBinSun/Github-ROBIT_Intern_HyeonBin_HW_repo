/**
 * @file /include/turtle_udp_reciever/main_window.hpp
 *
 * @brief Qt based gui for %(package)s.
 *
 * @date November 2010
 **/
#ifndef turtle_udp_reciever_MAIN_WINDOW_H
#define turtle_udp_reciever_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "udp.h"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace turtle_udp_reciever
{
  /*****************************************************************************
  ** Interface [MainWindow]
  *****************************************************************************/
  /**
   * @brief Qt central, all operations relating to the view part here.
   */
  class MainWindow : public QMainWindow
  {
    Q_OBJECT

  public:
    MainWindow(int argc, char** argv, QWidget* parent = 0);
    ~MainWindow();
    QHostAddress myIP;
    QHostAddress yourIP;
    uint16_t PORT;

    QUdpSocket* receive_Socket;

  public Q_SLOTS:
    void sub_udp();

  private:
    Ui::MainWindowDesign ui;
    QNode qnode;


  };

}  // namespace s

#endif  // turtle_udp_reciever_MAIN_WINDOW_H
