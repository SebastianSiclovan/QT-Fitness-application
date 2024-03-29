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

    ui->lineEdit_numberOfPounds->setEnabled(false);
    ui->label_setCalories->setVisible(false);

}

BMR_calculator::~BMR_calculator()
{
    delete ui;
}

template <typename T>
T BMR_calculator::calculate_BMR(QString Gender, int age, T height, T weight)
{
    T c; // common baseline value used in estimating female/male BMR
    T hm; // height multiplication (expressed in meters); 1 inch = 0.0254 metri.
    T vm; // weight multiplication (expressed in kilograms)
    T am; // age multiplication

    T BMR;

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

template <typename T>
T BMR_calculator::calculate_activity(QString activity_level, T BMR)
{
    T activity_result;
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

template <typename T>
T BMR_calculator::gain_or_lose(QString goal, int number_poundPerWeek, T activity_level)
{
    T calories;
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

    return calories;
}

bool BMR_calculator::checkVariants_activityLevels(QString current_activityLevel)
{
    std::list<QString> available_activityLevels = {"none", "light", "moderate", "heavy", "extreme"};
    bool warning = true;

    for(auto & element : available_activityLevels)
    {
        if (std::equal_to<QString> () (current_activityLevel, element))
        {
            warning = false;
        }
    }

    return warning;
}



bool BMR_calculator::check_BMRcalculator_fields()
{

    this->age = ui->lineEdit_age->text();
    this->gender = ui->lineEdit_gender->text();
    this->weight = ui->lineEdit_weight->text();
    this->height = ui->lineEdit_height->text();
    this->goal = ui->lineEdit_goal->text();
    this->activity_level = ui->lineEdit_activityLevel->text();
    this->numberOfPounds = ui->lineEdit_numberOfPounds->text();

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

    if (std::not_equal_to<QString> () (gender, "male") && std::not_equal_to<QString> () (gender, "female"))
    {
        QMessageBox::warning(this, "", "In the gender field you can enter only the gender 'male' or 'female'.");
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

    if(activity_level.isEmpty())
    {
        QMessageBox::warning(this, "BMR_calculator", "Please fill in the activity level");
        warning_field = true;
    }

    if (std::equal_to<bool> () (checkVariants_activityLevels(activity_level), true))
    {
        QMessageBox::warning(this, "", "In the activity level field you can enter only 'none', 'light', 'moderate', 'heavy', 'extreme' activity.");
    }

    if(goal.isEmpty())
    {
        QMessageBox::warning(this, "BMR_calculator", "Please fill in the goal");
        warning_field = true;
    }

    if (std::not_equal_to<QString>() (goal, "lose") && std::not_equal_to<QString>() (goal, "gain"))
    {
        QMessageBox::warning(this, "", "In the goal field you can enter only the goal type 'lose' or 'gain'.");
        warning_field = true;
    }

    if (std::equal_to<QString>() (goal, "gain"))
    {
        ui->lineEdit_numberOfPounds->setEnabled(true);

        if (numberOfPounds.isEmpty())
        {
            QMessageBox::information(this, "", "Because your goal is to gain please fill in the value 1 or 2 in the field under 'goal' to specify how many pounds you want to put on per week.");
        }
        else
        {
            // numberOfPounds != "1" && numberOfPounds != "2"
            if ([](QString numberOfPounds)->bool{if (numberOfPounds != "1" && numberOfPounds != "2"){return true;}else{return false;}}(numberOfPounds))
            {
                QMessageBox::warning(this, "", "The number of pounds can be only 1 or 2");

                warning_field = true;
            }

        }
    }
    else
    {
        ui->lineEdit_numberOfPounds->setEnabled(false);
    }



    return warning_field;

}


void BMR_calculator::on_checkCalories_btn_clicked()
{

    if (check_BMRcalculator_fields() == false)
    {
        float obtained_bmr = calculate_BMR<float>(this->gender, this->age.toFloat(), this->height.toFloat(), this->weight.toFloat());
        float obtained_activity = calculate_activity<float>(this->activity_level, obtained_bmr);
        float obtained_calories = gain_or_lose<float>(this->goal, this->numberOfPounds.toInt(), obtained_activity);

        if (!numberOfPounds.isEmpty())
        {
            ui->label_setCalories->setVisible(true);
            ui->label_setCalories->setText("Your daily caloric goals should be " + QString::number(obtained_calories));
        }
    }


}

