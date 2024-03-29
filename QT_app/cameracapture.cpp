#include "cameracapture.h"

CameraCapture::CameraCapture(QObject *parent)
    : QThread {parent}
    , videoCapture {ID_CAMERA}
{

}

QImage CameraCapture::cvMatToQImage(const cv::Mat & inMat)
{
    switch(inMat.type())
    {
    // 8-bit, 4 channel
    case CV_8UC4:
    {
        QImage image(inMat.data,
                     inMat.cols, inMat.rows,
                     static_cast<int>(inMat.step),
                     QImage::Format_ARGB32);

        return image;
    }

        // 8-bit, 3 channel
    case CV_8UC3:
    {
        QImage image(inMat.data,
                     inMat.cols, inMat.rows,
                     static_cast<int>(inMat.step),
                     QImage::Format_RGB888);

        return image.rgbSwapped();
    }

        // 8-bit, 1 channel
    case CV_8UC1:
    {
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
        QImage image(inMat.data,
                     inMat.cols, inMat.rows,
                     static_cast<int>(inMat.step),
                     QImage::Format_Grayscale8);
#else
        static QVector<QRgb> sColorTable;

        if (sColorTable.isEmpty())
        {
            sColorTable.resize(256);

            for (int i = 0; i < 256; ++i)
            {
                sColorTable[i] = qRgb(i, i, i);
            }
        }
        QImage image(inMat.data,
                     inMat.cols, inMat.rows,
                     static_cast<int>(inMat.step),
                     QImage::Format_Indexed8);

        QImage.setColorTable(sColorTable);
#endif
        return image;
    }
    default:
        qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
        break;
    }

    return QImage();
}

QPixmap CameraCapture::cvMatToQPixmap(const cv::Mat &inMat)
{
    return QPixmap::fromImage(cvMatToQImage(inMat));
}

void CameraCapture::run()
{

    if (videoCapture.isOpened())
    {
        while(true)
        {
            videoCapture >> Frame;
            if(!Frame.empty())
            {
                Pixmap = cvMatToQPixmap(Frame);
                emit newPixmapCaptured();
            }
        }
    }


}
