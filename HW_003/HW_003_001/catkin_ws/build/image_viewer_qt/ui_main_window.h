/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QComboBox *WcomboBox;
    QComboBox *HcomboBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(944, 704);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        WcomboBox = new QComboBox(centralwidget);
        WcomboBox->addItem(QString());
        WcomboBox->addItem(QString());
        WcomboBox->addItem(QString());
        WcomboBox->addItem(QString());
        WcomboBox->addItem(QString());
        WcomboBox->addItem(QString());
        WcomboBox->setObjectName(QString::fromUtf8("WcomboBox"));
        WcomboBox->setGeometry(QRect(130, 170, 171, 81));
        HcomboBox = new QComboBox(centralwidget);
        HcomboBox->addItem(QString());
        HcomboBox->addItem(QString());
        HcomboBox->addItem(QString());
        HcomboBox->addItem(QString());
        HcomboBox->addItem(QString());
        HcomboBox->addItem(QString());
        HcomboBox->setObjectName(QString::fromUtf8("HcomboBox"));
        HcomboBox->setGeometry(QRect(390, 170, 171, 81));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 100, 111, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(440, 100, 111, 51));
        label_2->setFont(font);
        MainWindowDesign->setCentralWidget(centralwidget);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", nullptr));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", nullptr));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", nullptr));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", nullptr));
        WcomboBox->setItemText(0, QApplication::translate("MainWindowDesign", "1920", nullptr));
        WcomboBox->setItemText(1, QApplication::translate("MainWindowDesign", "1280", nullptr));
        WcomboBox->setItemText(2, QApplication::translate("MainWindowDesign", "864", nullptr));
        WcomboBox->setItemText(3, QApplication::translate("MainWindowDesign", "640", nullptr));
        WcomboBox->setItemText(4, QApplication::translate("MainWindowDesign", "432", nullptr));
        WcomboBox->setItemText(5, QApplication::translate("MainWindowDesign", "176", nullptr));

        HcomboBox->setItemText(0, QApplication::translate("MainWindowDesign", "1080", nullptr));
        HcomboBox->setItemText(1, QApplication::translate("MainWindowDesign", "720", nullptr));
        HcomboBox->setItemText(2, QApplication::translate("MainWindowDesign", "480", nullptr));
        HcomboBox->setItemText(3, QApplication::translate("MainWindowDesign", "360", nullptr));
        HcomboBox->setItemText(4, QApplication::translate("MainWindowDesign", "240", nullptr));
        HcomboBox->setItemText(5, QApplication::translate("MainWindowDesign", "144", nullptr));

        label->setText(QApplication::translate("MainWindowDesign", "Width", nullptr));
        label_2->setText(QApplication::translate("MainWindowDesign", "Height", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
