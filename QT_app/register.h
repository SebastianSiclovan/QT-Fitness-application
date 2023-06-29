#ifndef REGISTER_H
#define REGISTER_H

#include "database_application.h"

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>


#include "Interfaces/Register_interface.h"

#include <list>

class Login;

namespace Ui {
class Register;
}

class Register : public QDialog, public Register_interface
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

    void set_firstName(QString fName);
    void set_lastName(QString lName);

    QString get_firstName();
    QString get_lastName();


private slots:

    void on_pushButton_registerBtn_clicked();
    void on_pushButton_Login_clicked();

private:
    bool get_warining(bool warning);
    bool check_registerFields() override;
    bool password_security(QString & obj) override;
private:
    Ui::Register *ui;

    Login * redirect_toLogin;

    bool warning_field;




    // database variables
    QSqlQuery query;
    QSqlDatabase db;
    Database_application * dB_obj;

    // atributes for register fields
    QString username;
    QString firstname;
    QString lastname;
    QString email;
    QString password;

    // store data insert by user
    std::list <QString> data_insertByUser;



};

#endif // REGISTER_H
