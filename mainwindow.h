#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include "logger.h"

using namespace MQ;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Logger* logger;
    void listenToBroadcast();

private slots:
    void on_pushButton_clicked();
    void onServerCreatedBroadcast();

private:
    Ui::MainWindow *ui;
    QUdpSocket* udpSocket;
};

#endif // MAINWINDOW_H
