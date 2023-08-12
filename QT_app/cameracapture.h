#ifndef CAMERACAPTURE_H
#define CAMERACAPTURE_H

#include <QDebug>

#include <QPixmap>
#include <QImage>
#include <QThread>
#include <opencv2/opencv.hpp>

#define ID_CAMERA 0

class CameraCapture : public QThread
{
    Q_OBJECT
public:
    CameraCapture(QObject * parent = nullptr);
    QPixmap pixmap () const
    {
        return Pixmap;
    }
signals:
    void newPixmapCaptured();

private:
    QImage cvMatToQImage(const cv::Mat & inMat);
    QPixmap cvMatToQPixmap(const cv::Mat &inMat);

protected:
    void run() override;

private:
    QPixmap Pixmap;

    cv::Mat Frame;
    cv::VideoCapture videoCapture;


};

#endif // CAMERACAPTURE_H
