/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionQuit;
    QWidget *centralWidget;
    QPushButton *pushButton_f1;
    QPushButton *pushButton_f2;
    QPushButton *pushButton_f3;
    QFrame *frame;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 800);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(70,70,70);"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_f1 = new QPushButton(centralWidget);
        pushButton_f1->setObjectName(QString::fromUtf8("pushButton_f1"));
        pushButton_f1->setGeometry(QRect(10, 726, 89, 25));
        pushButton_f1->setStyleSheet(QString::fromUtf8("color: white;"));
        pushButton_f2 = new QPushButton(centralWidget);
        pushButton_f2->setObjectName(QString::fromUtf8("pushButton_f2"));
        pushButton_f2->setGeometry(QRect(100, 726, 89, 25));
        pushButton_f2->setStyleSheet(QString::fromUtf8("color: white;"));
        pushButton_f3 = new QPushButton(centralWidget);
        pushButton_f3->setObjectName(QString::fromUtf8("pushButton_f3"));
        pushButton_f3->setGeometry(QRect(190, 726, 89, 25));
        pushButton_f3->setStyleSheet(QString::fromUtf8("color: white;"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 1201, 821));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        graphicsView = new QGraphicsView(frame);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 22, 1181, 701));
        graphicsView->setContextMenuPolicy(Qt::DefaultContextMenu);
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(80, 80, 80);"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 722, 1181, 31));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(70, 70, 70);"));
        MainWindow->setCentralWidget(centralWidget);
        frame->raise();
        widget->raise();
        pushButton_f1->raise();
        pushButton_f2->raise();
        pushButton_f3->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 22));
        menuBar->setStyleSheet(QString::fromUtf8("color: white;"));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuMenu->setStyleSheet(QString::fromUtf8("color: white"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMenu->addAction(actionSave);
        menuMenu->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Node View Dummy", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        pushButton_f1->setText(QCoreApplication::translate("MainWindow", "Filter 1", nullptr));
        pushButton_f2->setText(QCoreApplication::translate("MainWindow", "Filter 2", nullptr));
        pushButton_f3->setText(QCoreApplication::translate("MainWindow", "Filter 3", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
