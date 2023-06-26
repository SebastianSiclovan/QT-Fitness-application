#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    this->setWindowTitle("Sebastian's app - Home");
}

Home::~Home()
{
    delete ui;
}
