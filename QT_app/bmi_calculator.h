#ifndef BMI_CALCULATOR_H
#define BMI_CALCULATOR_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class BMI_calculator;
}

class BMI_calculator : public QDialog
{
    Q_OBJECT

public:
    explicit BMI_calculator(QWidget *parent = nullptr);
    ~BMI_calculator();

private slots:
    void on_checkCategory_btn_clicked();

    bool check_BMIcalculator_Fields();

    float calculate_BMI(float height, float weight);

    QString set_weightCategory(float BMI);



private:
    Ui::BMI_calculator *ui;

    bool warning_field;
    QString weight;
    QString height;

    BMI_calculator * single_obj;
};

#endif // BMI_CALCULATOR_H
