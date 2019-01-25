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

void MainWindow::on_connectButton_clicked()
{
    ip = ui->ipText->toPlainText();
    serverPort = ui->serverPortText->toPlainText().toInt();
    clientPort = ui->clientPortText->toPlainText().toInt();

    commandConnection = new Client(qPrintable(ip), serverPort);
    QMessageBox::information(this, "Client", "Command connection successful");

    transferConnection = new Server(TRANSFER_PORT);
    QMessageBox::information(this, "Client", "Transferconnection successful");
}

bool MainWindow::IsConnected() {
    if(commandConnection == NULL) {
        QMessageBox::information(this, "Client", "No command connection");
        return false;
    } else if (transferConnection == NULL){
        QMessageBox::information(this, "Client", "No transfer connection");
        return false;
    }
    return true;
}

void MainWindow::on_getButton_clicked()
{
    if(IsConnected()) {
        SendCmdQT(GET);
        //RecvFile();
    } else {
        QMessageBox::information(this, "Client", "No Connection");
    }
}

void MainWindow::on_sendButton_clicked()
{
    if(IsConnected()) {
        SendCmdQT(SEND);
        //RecvFile();
    } else {
        QMessageBox::information(this, "Client", "No Connection");
    }
}

void MainWindow::on_exitButton_clicked()
{
    if(IsConnected()) {
        SendCmdQT(EXIT);
        //RecvFile();
    } else {
        QMessageBox::information(this, "Client", "No Connection");
    }
}

bool MainWindow::SendCmdQT(int command)
{
    QString filename;
    QByteArray ba;
    Cmd cmd;

    filename = ui->filenameText->toPlainText();
    ba = filename.toLatin1();
    cmd = CreateCmd(command, ba.data());

    if(!(commandConnection->SendCmd(cmd))) {
        QMessageBox::information(this, "Client", "GET Failed");
        return false;
    }

    return true;
}
