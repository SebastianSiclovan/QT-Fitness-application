#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Login_clicked()
{
    loginObj = new Login(this);
    hide();
    loginObj->show();

}


void MainWindow::on_pushButton_2_clicked()
{
    registerObj = new Register(this);
    hide();
    registerObj->show();

}

