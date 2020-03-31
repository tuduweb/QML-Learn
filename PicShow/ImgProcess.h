#ifndef IMGPROCESS_H
#define IMGPROCESS_H

#include <QObject>
#include "ImgProcAbstract.h"

class ImgProcess : public QObject
{
public:
    explicit ImgProcess(QObject *parent = nullptr);
    void ImageProc(QImage);
    bool CheckDataInfo(QImage&);

private:
    QList<ImgProcAbstract *> procList;

signals:

};

#endif // IMGPROCESS_H
