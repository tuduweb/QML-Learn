#ifndef IMGPROCABSTRACT_H
#define IMGPROCABSTRACT_H

#include <QObject>
#include <QImage>


class ImgProcAbstract : public QObject
{
    Q_OBJECT
public:
    explicit ImgProcAbstract(quint16,quint16,QImage::Format = QImage::Format_Indexed8, QObject *parent = nullptr);
    quint16 height() const;
    quint16 width() const;

    virtual uint8_t Proc(QImage& imageData) = 0;

protected:
    quint16 m_height;
    quint16 m_width;
    QImage::Format m_format;
};

#endif // IMGPROCABSTRACT_H
