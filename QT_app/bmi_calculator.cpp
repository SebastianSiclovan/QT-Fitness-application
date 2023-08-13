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

template<typename T>
T BMI_calculator::calculate_BMI(T height, T weight)
{
    T result_BMI = weight / (height*height);
    return result_BMI;
}

template <typename T>
QString BMI_calculator::set_weightCategory(T BMI)
{
    QString category;

    if (BMI < 18.5)
    {
        category = "Underweight";
    }
    else
    {
        if (BMI > 25)
        {
            category = "Overweight";
        }
        else
        {
            category = "Normal weight";
        }
    }

    return category;

}




bool BMI_calculator::check_BMIcalculator_Fields()
{
    this->warning_field = false;

    this->weight = ui->lineEdit_weight->text();
    this->height = ui->lineEdit_height->text();

    if(weight.isEmpty())
    {
        QMessageBox::warning(this, "BMI_calculator", "Please fill in the weight");
        warning_field = true;

    }
    else
    {
        ui->lineEdit_weight->setEnabled(false);
    }

    if (height.isEmpty())
    {
        QMessageBox::warning(this, "BMI_calculator", "Please fill in the height");
        warning_field = true;
    }
    else
    {
        ui->lineEdit_height->setEnabled(false);
    }

    return warning_field;

}


void BMI_calculator::on_checkCategory_btn_clicked()
{
    single_obj = new BMI_calculator();



    if(check_BMIcalculator_Fields() == false)
    {
        QMessageBox::information(this, "BMI_calculator", "Your category and BMI are now available!");
        float BMI = single_obj->calculate_BMI<float>(this->height.toFloat(), this->weight.toFloat());
        QString weightCategory = single_obj->set_weightCategory<float>(BMI);
        ui->label_setBMI->setText(QString::number(BMI));
        ui->label_setCategory->setText(weightCategory);

    }

}

