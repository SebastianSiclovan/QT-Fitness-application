#include "register.h"
#include "ui_register.h"

#include "Login.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowTitle("Sebastian's app - Register");
}

Register::~Register()
{
    delete ui;
    qDebug() << "Destructorul a fost apelat";
}

QString Register::get_firstName()
{
    return this->firstname;
}

/*
    password_security: function which reiceive password parameter and verify if password have at least one number and one uppercase
    -Return true if password have at least one number and one uppercase
    -Return false if password don t have ...
 */
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

/*
    get_warning: function which receive a warning parameter and verify if a warning has occured
    -Return true if is a warning
    -Return false if isn't
 */
bool Register::get_warining(bool warning)
{
    if (warning == true)
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
    this->warning_field = false;

    username = ui->lineEdit_userName->text();
    firstname = ui->lineEdit_firstName->text();
    lastname = ui->lineEdit_lastName->text();
    email = ui->lineEdit_email->text();
    password = ui->lineEdit_password->text();


    // verify if fields is empty
    if (username.isEmpty())
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
    dB_obj = new Database_application();
    dB_obj->databaseInit();

    if(check_registerFields() == false)
    {
        data_insertByUser = {username, firstname, lastname, email, password};

        QMessageBox::information(this, "Register", "Succesfully register, you will be redirected to login section");
        dB_obj->database_addUserData_atRegister(data_insertByUser);

        hide();
        redirect_toLogin->show();


    }
    else
    {
        if (get_warining(this->warning_field == false))
        {
            QMessageBox::information(this, "Register", "Something went wrong");
        }


    }

}


void Register::on_pushButton_Login_clicked()
{
    redirect_toLogin = new Login();
    hide();
    redirect_toLogin->show();


}

