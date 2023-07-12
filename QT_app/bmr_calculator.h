#ifndef BMR_CALCULATOR_H
#define BMR_CALCULATOR_H

#include <QDialog>

namespace Ui {
class BMR_calculator;
}

class BMR_calculator : public QDialog
{
    Q_OBJECT

public:
    explicit BMR_calculator(QWidget *parent = nullptr);
    ~BMR_calculator();

private:
    Ui::BMR_calculator *ui;
};

#endif // BMR_CALCULATOR_H
