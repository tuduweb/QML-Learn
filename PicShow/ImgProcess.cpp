#include "ImgProcess.h"
#include "QImage"

#include "GrayImgProc.h"

#include "QDebug"

/*
 * 输入“图像数据”
 * 输出“信息”
*/

ImgProcess::ImgProcess(QObject *parent) : QObject(parent)
{
    procList.append(new GrayImgProc(188,120,this));

    QImage image;

    //qDebug() << QString("proc--->%1").arg((char)procList.last()->Proc(image));

}

bool ImgProcess::CheckDataInfo(QImage &imageData)
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
