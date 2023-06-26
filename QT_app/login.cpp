#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("Sebastian's app - Login");
}

Login::~Login()
{
    delete ui;
}

bool Login::check_loginFields()
{
    this->warning_field = false;

    email = ui->lineEdit_email->text();
    password = ui->lineEdit_password->text();

    if (email.isEmpty())
    {
        QMessageBox::warning(this, "Login", "Attention! you have not entered any email");
        warning_field = true;
    }

    if (password.isEmpty())
    {
        QMessageBox::warning(this, "Login", "Attention! you have not entered any password");
        warning_field = true;
    }

    return warning_field;

}


void Login::on_pushButton_loginBtn_clicked()
{
    dataBase = new Database_application();

    dataBase->databaseInit();

    if(check_loginFields() == false)
    {

        if ((this->dataBase->verify_userData_atLogin(email, password)) == true)
        {
            QMessageBox::information(this, "Login", "Successful login");
            hide();
            redirect_toHome->show();





        }
        else
        {
            QMessageBox::warning(this, "Login", "Incorrect password or email address entered");
        }

    }




}


void Login::on_pushButton_Register_clicked()
{

}

