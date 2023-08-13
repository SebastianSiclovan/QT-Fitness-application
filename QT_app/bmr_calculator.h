#ifndef BMR_CALCULATOR_H
#define BMR_CALCULATOR_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <algorithm>
#include <vector>
#include <list>

struct male_coefs;
struct female_coefs;



namespace Ui {
class BMR_calculator;
}

class BMR_calculator : public QDialog
{
    Q_OBJECT

public:
    explicit BMR_calculator(QWidget *parent = nullptr);
    ~BMR_calculator();


private slots:
    void on_checkCalories_btn_clicked();

private:

    template <typename T>
    T calculate_BMR(QString Gender, int age, T height, T weight);

    template <typename T>
    T calculate_activity(QString activity_level, T BMR);

    template <typename T>
    T gain_or_lose(QString goal, int number_poundPerWeek, T activity_level);

    bool checkVariants_activityLevels(QString current_activityLevel);

    bool check_BMRcalculator_fields();




private:
    Ui::BMR_calculator *ui;

    QString age;
    QString gender;
    QString weight;
    QString height;
    QString activity_level;
    QString goal;
    QString numberOfPounds;

    bool warning_field;

    std::vector<float> caloricRequirement_coef = {1.55, 1.725, 1.9, 1.375, 1.2};

    BMR_calculator * bmr_calculator;

};

#endif // BMR_CALCULATOR_H
