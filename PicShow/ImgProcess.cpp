#include "ImgProcess.h"
#include "QImage"

#include "GrayImgProc.h"

#include "QDebug"

#define IMGPROC_PREFIX ImgProcess::


IMGPROC_PREFIX ImgProcess(QObject *parent) : QObject(parent)
{
    //这里是申明具体处理的实现
    procList.append(new GrayImgProc(188,120,this));


    //具体的实现需要有调用PixelTips,TextTips的方法.

    QImage image;

    //qDebug() << QString("proc--->%1").arg((char)procList.last()->Proc(image));

}

bool IMGPROC_PREFIX CheckDataInfo(QImage &imageData)
{
    for(auto proc : procList)
    {
        qDebug() << proc->width() << " --- " << proc->height() << imageData;
        if(proc->width() == imageData.width() && proc->height() == imageData.height())
        {
            //qDebug() << imageData << "okk";
            procList.last()->Proc(imageData);
        }
    }

    return true;

}
