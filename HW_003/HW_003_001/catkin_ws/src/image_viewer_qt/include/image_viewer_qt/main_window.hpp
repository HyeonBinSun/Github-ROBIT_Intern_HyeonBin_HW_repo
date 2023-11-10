/**
 * @file /include/image_viewer_qt/main_window.hpp
 *
 * @brief Qt based gui for %(package)s.
 *
 * @date November 2010
 **/
#ifndef image_viewer_qt_MAIN_WINDOW_H
#define image_viewer_qt_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

#include <QComboBox>

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace image_viewer_qt
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

  public Q_SLOTS:
    void on_HcomboBox_currentindexChanged(int index);
    void on_WcomboBox_currentindexChanged(int index);

  private:
    Ui::MainWindowDesign ui;
    QNode qnode;
  };

}  // namespace s

#endif  // image_viewer_qt_MAIN_WINDOW_H
