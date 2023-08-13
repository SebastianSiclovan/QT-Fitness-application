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

private:
    Ui::BMI_calculator *ui;

    bool warning_field;
    QString weight;
    QString height;

    BMI_calculator * single_obj;

    template <typename T>
    T calculate_BMI(T height, T weight);

    template <typename T>
    QString set_weightCategory(T BMI);

    bool check_BMIcalculator_Fields();


};

#endif // BMI_CALCULATOR_H
