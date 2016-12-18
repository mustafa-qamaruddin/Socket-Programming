#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include "logger.h"
#include "mqserver.h"

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
    void updatePlayersCounter();
private slots:
    void on_pushButton_clicked();
    void onServerCreatedBroadcast();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QUdpSocket* udpSocket;
    MQServer* server;
};

#endif // MAINWINDOW_H
