#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QDebug>

#include <QMessageBox>

#include <list>

#include "database_application.h"
#include "home.h"

class Register;

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT


public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_loginBtn_clicked();

    void on_pushButton_Register_clicked();

private:
    bool check_loginFields();


private:
    Ui::Login *ui;

    QString email;
    QString password;

    Database_application * dataBase;

    Home * redirect_toHome = new Home();

    Register * redirect_toRegister;



    bool warning_field;

    std::list<QString> data_insertByUser;




};

#endif // LOGIN_H
