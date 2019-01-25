#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetUp()
{
    //listen for command connection
    commandConnection = new Server(SERVER_PORT);
    QMessageBox::information(this, "Server", "Command connection successful");

    const char *transferIP = commandConnection->GetTransferIP();
    QMessageBox::information(this, "Server", transferIP);

    //create a transfer connection back
    transferConnection = new Client("127.0.0.1", 70005);
    QMessageBox::information(this, "Server", "Transferconnection successful");

    //Wait for commands
        //send || recv || exit
}
