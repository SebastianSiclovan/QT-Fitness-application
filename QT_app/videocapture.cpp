#include "videocapture.h"
#include "ui_videocapture.h"
#include "cameracapture.h"

VideoCapture::VideoCapture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoCapture)
{

    ui->setupUi(this);
    this->setWindowTitle("Sebastian's app - Video Capture");

    openCV_videoCapture = new CameraCapture();

    connect(openCV_videoCapture, &CameraCapture::newPixmapCaptured, this, [&]()
    {
        ui->FrameOpenCV_label->setPixmap(openCV_videoCapture->pixmap().scaled(500, 500));

    });
}

VideoCapture::~VideoCapture()
{
    delete ui;
    openCV_videoCapture->terminate();
}



void VideoCapture::on_openCamera_btn_clicked()
{
    openCV_videoCapture->start(QThread::HighestPriority);

}

