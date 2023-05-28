#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowTitle("Register");
}

Register::~Register()
{
    delete ui;
}

bool Register::password_security(QString &password)
{
    int cnt_digits = 0;
    int cnt_upperCase = 0;

    for (QChar c : password)
    {
        if (std::isdigit(c.toLatin1()))
        {
            cnt_digits++;
            break;
        }
    }

    for (QChar c : password)
    {
        if (c.isUpper())
        {
            cnt_upperCase++;
            break;

        }
    }

    if (cnt_digits != 0 && cnt_upperCase != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Register::check_registerFields()
{
    bool warning_field = false;

    QString username = ui->lineEdit_userName->text();
    QString firstname = ui->lineEdit_firstName->text();
    QString lastname = ui->lineEdit_lastName->text();
    QString email = ui->lineEdit_email->text();
    QString password = ui->lineEdit_password->text();

    // verify if fields is empty
    if (username.isEmpty() )
    {
        QMessageBox::warning(this, "Register", "Please complete the username field");
        warning_field = true;
    }
    else if (firstname.isEmpty())
    {
        QMessageBox::warning(this, "First Name", "Please complete de first name field");
        warning_field = true;
    }
    else if (lastname.isEmpty())
    {
        QMessageBox::warning(this, "Register", "Please complete de last name field");
        warning_field = true;
    }
    else if (email.isEmpty())
    {
        QMessageBox::warning(this, "Register", "Please complete de email field");
        warning_field = true;
    }
    else if (password.isEmpty())
    {
        QMessageBox::warning(this, "Register", "Please complete de password field");
        warning_field = true;
    }
    else if (!password_security(password))
    {
        QMessageBox::warning(this, "Register", "Please respect the security of password, this must to contain at least one digit and at least one upper case");
        warning_field = true;

    }
    else
    {
        // do nothing
    }


    return warning_field;

}






void Register::on_pushButton_registerBtn_clicked()
{
    if(check_registerFields() == false)
    {
        QMessageBox::information(this, "Register", "Succesfully register, you will be redirected to login section");
    }

}

