/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcameraviewfinder.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Stop_Camera;
    QCameraViewfinder *widget_Camera_View;
    QPushButton *pushButton_Start_Camera;
    QPushButton *pushButton_Image_Capture;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_Stop_Camera = new QPushButton(centralwidget);
        pushButton_Stop_Camera->setObjectName(QString::fromUtf8("pushButton_Stop_Camera"));

        gridLayout->addWidget(pushButton_Stop_Camera, 0, 1, 1, 1);

        widget_Camera_View = new QCameraViewfinder(centralwidget);
        widget_Camera_View->setObjectName(QString::fromUtf8("widget_Camera_View"));

        gridLayout->addWidget(widget_Camera_View, 2, 0, 1, 2);

        pushButton_Start_Camera = new QPushButton(centralwidget);
        pushButton_Start_Camera->setObjectName(QString::fromUtf8("pushButton_Start_Camera"));

        gridLayout->addWidget(pushButton_Start_Camera, 0, 0, 1, 1);

        pushButton_Image_Capture = new QPushButton(centralwidget);
        pushButton_Image_Capture->setObjectName(QString::fromUtf8("pushButton_Image_Capture"));

        gridLayout->addWidget(pushButton_Image_Capture, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_Stop_Camera->setText(QCoreApplication::translate("MainWindow", "Stop Camera", nullptr));
        pushButton_Start_Camera->setText(QCoreApplication::translate("MainWindow", "Start Camera", nullptr));
        pushButton_Image_Capture->setText(QCoreApplication::translate("MainWindow", "Capture Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
