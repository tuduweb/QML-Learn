#ifndef IMGPROCESS_H
#define IMGPROCESS_H

#include <QObject>

class ImgProcess : public QObject
{
    Q_OBJECT
public:
    explicit ImgProcess(QObject *parent = nullptr);

signals:

};

#endif // IMGPROCESS_H
