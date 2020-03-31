#include "GrayImgProc.h"

#include "QDebug"

#include "ImgProc/imgproc.h"

GrayImgProc::GrayImgProc(quint16 w,quint16 h,QObject *parent,QImage::Format f) : ImgProcAbstract(w,h,f,parent)
{
    qDebug() << "GrayImgProc";

    //ImgProc((unsigned char *)&w);
}

uint8_t GrayImgProc::Proc(QImage &imageData)
{
    uchar* data = imageData.bits();

    ImgProc((unsigned char *)data);

    return 'T';
}
