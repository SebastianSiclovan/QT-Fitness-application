#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Sebastian's app - First interaction");

}

MainWindow::~MainWindow()
{
    delete ui;
}
MainWindow & MainWindow::get_instance()
{
    static MainWindow instance;
    return instance;
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

