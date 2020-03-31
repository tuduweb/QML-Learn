#include "PixelTipsLayer.h"
#include "QDebug"

#include "QTime"

#define PIXEL_LAYER_W   188
#define PIXEL_LAYER_H   120

PixelTipsLayer::PixelTipsLayer(QObject *parent) : QObject(parent)
{
    qDebug() << "hello world!" << this;


    image = QImage(PIXEL_LAYER_W, PIXEL_LAYER_H, QImage::Format_ARGB32);

    image.fill(Qt::transparent);

    //qDebug() << image;

    painter.begin(&image);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    color = QColor(qrand() % 255,qrand() % 255,qrand() % 255);

    painter.setPen(QPen(color, 1, Qt::SolidLine));

    painter.drawLine(0, 0, PIXEL_LAYER_W - 1, PIXEL_LAYER_H - 1);

    painter.end();
}
