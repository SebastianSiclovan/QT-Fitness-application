#include "bmr_calculator.h"
#include "ui_bmr_calculator.h"


struct male_coefs
{
    float m_InfluenceHeight = 6.2;
    float m_InfluenceWeight = 12.7;
    float m_influenceAge = 6.76;
    float m_commonBaselineBMR = 66;

};

struct female_coefs
{
    float f_InfluenceHeight = 4.35;
    float f_InfluenceWeight = 4.7;
    float f_influenceAge = 4.7;
    float f_commonBaselineBMR = 655.1;

};

BMR_calculator::BMR_calculator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BMR_calculator)
{
    ui->setupUi(this);
    this->setWindowTitle("Sebastian's app - BMR calculator");



}

BMR_calculator::~BMR_calculator()
{
    delete ui;
}

float BMR_calculator::calculate_BMR(QString Gender, int age, float height, float weight)
{
    float c; // common baseline value used in estimating female/male BMR
    float hm; // height multiplication (expressed in meters); 1 inch = 0.0254 metri.
    float vm; // weight multiplication (expressed in kilograms)
    float am; // age multiplication

    float BMR;

    male_coefs * m_coef = new male_coefs;
    female_coefs * f_coef = new female_coefs;


    if (gender == "male")
    {
        c = m_coef->m_commonBaselineBMR;
        hm = m_coef->m_InfluenceHeight * height;
        vm = m_coef->m_InfluenceWeight * weight;
        am = m_coef->m_influenceAge * age;
    }

    if (gender == "female")
    {
        c = f_coef->f_commonBaselineBMR;
        hm = f_coef->f_InfluenceHeight * height;
        vm = f_coef->f_InfluenceWeight * weight;
        am = f_coef->f_influenceAge * age;
    }

    BMR = c + hm + vm - am;

    delete m_coef;
    delete f_coef;

    return BMR;
}

float BMR_calculator::calculate_activity(QString activity_level, float BMR)
{
    float activity_result;
    std::vector<float>::iterator itr_begin = caloricRequirement_coef.begin();
    std::vector<float>::iterator itr_end = caloricRequirement_coef.end();

    // after sort, values in vector will be 1.2, 1.375, 1.55, 1.725, 1.9
    std::sort(itr_begin, itr_end);

    if (activity_level == "none")
    {
        activity_result = caloricRequirement_coef[0] * BMR;
    }
    else if (activity_level == "light")
    {
        activity_result = caloricRequirement_coef[1] * BMR;
    }
    else if (activity_level == "moderate")
    {
        activity_result = caloricRequirement_coef[2] * BMR;
    }
    else if (activity_level == "heavy")
    {
        activity_result = caloricRequirement_coef[3] * BMR;
    }
    else if (activity_level == "extreme")
    {
        activity_result = caloricRequirement_coef[4] * BMR;
    }
    else
    {
        // do nothing
    }

    return activity_result;

}
/*
float BMR_calculator::gain_or_lose(QString goal, QString number_poundPerWeek, float activity_level)
{
    float calories;
    if (goal == "lose")
    {
        calories = activity_level - 500;
    }
    else if (goal == "maintain")
    {
        calories = activity_level;
    }
    else if (goal == "gain")
    {

        if (number_poundPerWeek == 1)
        {
            calories = activity_level + 500;
        }

        if (number_poundPerWeek == 2)
        {
            calories = activity_level + 1000;
        }

    }
    else
    {
        // do nothing
    }
}
*/



bool BMR_calculator::check_BMRcalculator_fields()
{
    this->age = ui->lineEdit_age->text();
    this->gender = ui->lineEdit_gender->text();
    this->weight = ui->lineEdit_weight->text();
    this->height = ui->lineEdit_height->text();
    this->goal = ui->lineEdit_goal->text();
    this->activity_level = ui->lineEdit_activityLevel->text();

    this->warning_field = false;

    if(age.isEmpty())
    {
        QMessageBox::warning(this, "BMR_calculator", "Please fill in the age");
        warning_field = true;
    }

    if(gender.isEmpty())
    {
        QMessageBox::warning(this, "BMR_calculator", "Please fill in the gender");
        warning_field = true;
    }

    if(weight.isEmpty())
    {
        QMessageBox::warning(this, "BMR_calculator", "Please fill in the weight");
        warning_field = true;
    }

    if(height.isEmpty())
    {
        QMessageBox::warning(this, "BMR_calculator", "Please fill in the height");
        warning_field = true;
    }

    if(goal.isEmpty())
    {
        QMessageBox::warning(this, "BMR_calculator", "Please fill in the goal");
        warning_field = true;
    }

    if(activity_level.isEmpty())
    {
        QMessageBox::warning(this, "BMR_calculator", "Please fill in the activity level");
        warning_field = true;
    }

    return warning_field;

}


void BMR_calculator::on_checkCalories_btn_clicked()
{


    if (check_BMRcalculator_fields() == false)
    {
        float obtained_bmr = calculate_BMR(this->gender, this->age.toFloat(), this->height.toFloat(), this->weight.toFloat());
        qDebug() << calculate_activity(this->activity_level, obtained_bmr);
    }


}

