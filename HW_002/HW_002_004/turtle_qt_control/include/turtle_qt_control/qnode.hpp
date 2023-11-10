/**
 * @file /include/turtle_qt_control/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef turtle_qt_control_QNODE_HPP_
#define turtle_qt_control_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>
#include <geometry_msgs/Twist.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace turtle_qt_control
{
  /*****************************************************************************
  ** Class
  *****************************************************************************/

  class QNode : public QThread
  {
    Q_OBJECT
  public:
    QNode(int argc, char** argv);
    virtual ~QNode();
    bool init();
    void run();

    bool CheckComu = true;
    geometry_msgs::Twist turtle_direc;
    void pubMsg();

  Q_SIGNALS:
    void rosShutdown();

  private:
    int init_argc;
    char** init_argv;

    ros::Publisher qt_control;
  };

}  // namespace s

#endif /* turtle_qt_control_QNODE_HPP_ */
