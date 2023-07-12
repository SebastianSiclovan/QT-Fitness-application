#ifndef HOME_H
#define HOME_H

#include <QDialog>
#include <QDebug>

#include "Login.h"
#include "bmi_calculator.h"
#include "bmr_calculator.h"
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

private slots:

    void on_FoodOrganizer_btn_clicked();

    void on_BMIcalculator_btn_clicked();

    void on_BMRcalculator_btn_clicked();

private:
    Ui::Home *ui;

    BMI_calculator * redirect_toBMIcalc;
    BMR_calculator * redirect_toBMRcalc;


    Database_application * dB;


    //QString set_welcome;
};

#endif // HOME_H
