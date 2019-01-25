#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../A1/client.h"
#include "../A1/server.h"
#include <QMainWindow>

#define SERVER_PORT 7005
#define TRANSFER_PORT 70005

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool IsConnected();
    bool SendCmdQT(int command);
private slots:
    void on_connectButton_clicked();

    void on_sendButton_clicked();

    void on_getButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::MainWindow *ui;
    QString ip;
    int serverPort, clientPort;
    bool open;
    Client *commandConnection ;
    Server *transferConnection ;
};

#endif // MAINWINDOW_H
