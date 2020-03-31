#ifndef PIXELTIPSLAYER_H
#define PIXELTIPSLAYER_H

#include <QObject>
#include <QtGui>


class PixelTipsLayer : public QObject
{
    Q_OBJECT
public:
    QImage  image;//底层
    QPainter painter;//画板
    QColor color;

    explicit PixelTipsLayer(QObject *parent = nullptr);

signals:

};

#endif // PIXELTIPSLAYER_H
