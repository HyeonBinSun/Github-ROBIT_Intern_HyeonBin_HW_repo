/**
 * @file /include/turtle_qt_control/main_window.hpp
 *
 * @brief Qt based gui for %(package)s.
 *
 * @date November 2010
 **/
#ifndef turtle_qt_control_MAIN_WINDOW_H
#define turtle_qt_control_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include <QMessageBox>
#include <QKeyEvent>

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace turtle_qt_control
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
    void keyPressEvent(QKeyEvent * event);

  public Q_SLOTS:
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_frontButton_clicked();
    void on_backButton_clicked();

  private:
    Ui::MainWindowDesign ui;
    QNode qnode;
  };

}  // namespace s

#endif  // turtle_qt_control_MAIN_WINDOW_H
