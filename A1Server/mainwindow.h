#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../A1/client.h"
#include "../A1/server.h"
#include "../A1/socketwrappers.h"
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
    void SetUp();
private:
    Ui::MainWindow *ui;
    Server *commandConnection;
    Client *transferConnection;
};

#endif // MAINWINDOW_H
