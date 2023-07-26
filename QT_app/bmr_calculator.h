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

    bool check_BMRcalculator_fields();

    void on_checkCalories_btn_clicked();

    float calculate_BMR(QString Gender, int age, float height, float weight);

    float calculate_activity(QString activity_level, float BMR);

    float gain_or_lose(QString goal, int number_poundPerWeek, float activity_level);

    bool checkVariants_activityLevels(QString current_activityLevel);




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
