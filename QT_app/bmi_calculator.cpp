#include "bmi_calculator.h"
#include "ui_bmi_calculator.h"

BMI_calculator::BMI_calculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BMI_calculator)
{
    ui->setupUi(this);
    this->setWindowTitle("Sebastian's app - BMI calculator");
}

BMI_calculator::~BMI_calculator()
{
    delete ui;
}
