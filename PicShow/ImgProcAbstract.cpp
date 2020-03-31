#include "ImgProcAbstract.h"

ImgProcAbstract::ImgProcAbstract(quint16 w,quint16 h,QImage::Format f,QObject *parent)
    : QObject(parent) , m_height(h), m_width(w) , m_format(f)
{

}

quint16 ImgProcAbstract::height() const
{
    return m_height;
}

quint16 ImgProcAbstract::width() const
{
    return m_width;
}

//uint8_t ImgProcAbstract::Proc(QImage &imageData)
//{
//    return 'F';
//}
