/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QAction *actionJoin_Game;
    QAction *actionExit;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_server_ip;
    QLabel *label_server_port;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_console;
    QLabel *label_3;
    QComboBox *comboBox_servers;
    QLabel *label_4;
    QLCDNumber *lcdNumber_players;
    QPushButton *pushButton_3;
    QOpenGLWidget *openGLWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 480);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionJoin_Game = new QAction(MainWindow);
        actionJoin_Game->setObjectName(QStringLiteral("actionJoin_Game"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(560, 0, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 30, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 10, 61, 16));
        label_server_ip = new QLabel(centralWidget);
        label_server_ip->setObjectName(QStringLiteral("label_server_ip"));
        label_server_ip->setGeometry(QRect(60, 0, 47, 13));
        label_server_port = new QLabel(centralWidget);
        label_server_port->setObjectName(QStringLiteral("label_server_port"));
        label_server_port->setGeometry(QRect(60, 10, 47, 13));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 400, 640, 80));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 636, 76));
        label_console = new QLabel(scrollAreaWidgetContents);
        label_console->setObjectName(QStringLiteral("label_console"));
        label_console->setGeometry(QRect(0, 0, 640, 80));
        label_console->setCursor(QCursor(Qt::IBeamCursor));
        label_console->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_console->setWordWrap(true);
        label_console->setMargin(5);
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 30, 91, 16));
        comboBox_servers = new QComboBox(centralWidget);
        comboBox_servers->setObjectName(QStringLiteral("comboBox_servers"));
        comboBox_servers->setGeometry(QRect(100, 30, 121, 22));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(330, 30, 51, 16));
        lcdNumber_players = new QLCDNumber(centralWidget);
        lcdNumber_players->setObjectName(QStringLiteral("lcdNumber_players"));
        lcdNumber_players->setGeometry(QRect(390, 30, 64, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(460, 30, 75, 23));
        openGLWidget = new QOpenGLWidget(centralWidget);
        openGLWidget->setObjectName(QStringLiteral("openGLWidget"));
        openGLWidget->setGeometry(QRect(10, 70, 300, 300));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew_Game->setText(QApplication::translate("MainWindow", "New Game", 0));
        actionJoin_Game->setText(QApplication::translate("MainWindow", "Join Game", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Create Server", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Join Game", 0));
        label->setText(QApplication::translate("MainWindow", "Server IP:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Server Port:", 0));
        label_server_ip->setText(QApplication::translate("MainWindow", "#", 0));
        label_server_port->setText(QApplication::translate("MainWindow", "#", 0));
        label_console->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Available Servers:", 0));
        label_4->setText(QApplication::translate("MainWindow", "# Players:", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Start Game", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
