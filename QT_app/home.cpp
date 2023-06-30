#include "home.h"
#include "ui_home.h"



Home::Home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    this->setWindowTitle("Sebastian's app - Home");

    //ui->label_homeWelcome->setText(Login::email);
    QString email_fromLogin = Login::email;
    QString fName, lName;



    dB = new Database_application();
    dB->databaseInit();

    std::vector<QString> temporary_data;
    temporary_data = dB->get_firstName_and_lastName(email_fromLogin);
    fName = temporary_data[0];
    lName = temporary_data[1];

    QString concat   = "Welcome, " + fName + " " + lName + " !";
    ui->label_homeWelcome->setText(concat);

}


Home::~Home()
{
    delete ui;
}
