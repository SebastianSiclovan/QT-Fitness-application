#ifndef BMI_CALCULATOR_H
#define BMI_CALCULATOR_H

#include <QDialog>

namespace Ui {
class BMI_calculator;
}

class BMI_calculator : public QDialog
{
    Q_OBJECT

public:
    explicit BMI_calculator(QWidget *parent = nullptr);
    ~BMI_calculator();

private:
    Ui::BMI_calculator *ui;
};

#endif // BMI_CALCULATOR_H
