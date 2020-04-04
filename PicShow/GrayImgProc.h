#ifndef GRAYIMGPROC_H
#define GRAYIMGPROC_H

#include "ImgProcAbstract.h"
#include "QImage"


class GrayImgProc : public ImgProcAbstract
{
    Q_OBJECT
public:
    GrayImgProc(quint16 w,quint16 h, QObject *parent = nullptr, QImage::Format f = QImage::Format_Indexed8);
    uint8_t Proc(QImage& imageData);

private:
    void ImgProc(uint8_t* data);

};

#endif // GRAYIMGPROC_H
