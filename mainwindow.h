#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include "logger.h"
#include "mqserver.h"
#include "mqgame.h"
#include "Views/Headers/mqrender.h"

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
    void setupSDL();
private slots:
    void on_pushButton_clicked();
    void onServerCreatedBroadcast();
    void updatePlayersCounter();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void handleResponse();

private:
    Ui::MainWindow *ui;
    QUdpSocket* udpSocket;
    MQServer* server;
    int image_w = 300;
    int image_h = 300;
    MQRender* mqrender;
    MQGame* mqgame;
    QThreadPool* mq_thread_pl;
};

#endif // MAINWINDOW_H
