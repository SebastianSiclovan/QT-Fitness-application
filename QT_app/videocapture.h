#ifndef VIDEOCAPTURE_H
#define VIDEOCAPTURE_H

#include <QDialog>


namespace Ui {
class VideoCapture;
}

class CameraCapture;

class VideoCapture : public QDialog
{
    Q_OBJECT

public:
    explicit VideoCapture(QWidget *parent = nullptr);
    ~VideoCapture();


private slots:
    void on_openCamera_btn_clicked();

private:
    Ui::VideoCapture *ui;
    CameraCapture * openCV_videoCapture;
};

#endif // VIDEOCAPTURE_H
