#include "foodorganizer.h"
#include "ui_foodorganizer.h"

FoodOrganizer::FoodOrganizer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FoodOrganizer)
{
    ui->setupUi(this);
    this->setWindowTitle("Sebastian's app - Food Organizer");
    ui->label->setText("In this section of the app you can find out which foods are healthy via the video camera at your disposition. To find this out\nyou will need to press the button below, then press the open camera button and present each food in front of the camera.");

}

FoodOrganizer::~FoodOrganizer()
{
    delete ui;
}





void FoodOrganizer::on_redirect_toCamera_btn_clicked()
{
    redirect_toVideoCapture = new VideoCapture();
    redirect_toVideoCapture->show();
}

