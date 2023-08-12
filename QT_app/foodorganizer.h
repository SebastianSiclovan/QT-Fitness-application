#ifndef FOODORGANIZER_H
#define FOODORGANIZER_H

#include "videocapture.h"

#include <QDialog>

#include <QPixmap>
#include <QImage>
#include <QThread>
#include <opencv2/opencv.hpp>


namespace Ui {
class FoodOrganizer;
}

class FoodOrganizer : public QDialog
{
    Q_OBJECT

public:
    explicit FoodOrganizer(QWidget *parent = nullptr);
    ~FoodOrganizer();



private slots:

    void on_redirect_toCamera_btn_clicked();

private:
    Ui::FoodOrganizer *ui;

    VideoCapture * redirect_toVideoCapture;
};

#endif // FOODORGANIZER_H
