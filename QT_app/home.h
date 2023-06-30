#ifndef HOME_H
#define HOME_H

#include <QDialog>
#include <QDebug>

#include "Login.h"
#include "database_application.h"

class Login;

namespace Ui {
class Home;
}

class Home : public QDialog
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();

    void display_email(QString from_login);

private:
    Ui::Home *ui;


    Database_application * dB;


    //QString set_welcome;
};

#endif // HOME_H
