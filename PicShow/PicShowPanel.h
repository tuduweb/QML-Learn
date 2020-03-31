#ifndef PICSHOWPAINTEDITEM_H
#define PICSHOWPAINTEDITEM_H

#include <QObject>
#include <QQuickItem>
#include <QtQuick/QQuickPaintedItem>
#include <QColor>
#include <QPainter>

#include "PixelTipsLayer.h"

#include "ImgProcess.h"


class PicShowPaintedItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)

    Q_PROPERTY(QString uri READ uri WRITE setUri NOTIFY uriChanged)

public:
    Q_INVOKABLE void updateGUI();
    PicShowPaintedItem(QQuickItem *parent=0);
    QString name() const;
    void setName(const QString &name);
    QColor color() const;
    void setColor(const QColor &color);

    //测试一下
    QString uri() const;
    void setUri(const QString &uri);

    void paint(QPainter *painter);
private:
    QColor myColor;
    QString myName;
    QString myUri;

    PixelTipsLayer* layer;
    QList<PixelTipsLayer *> layers;

    ImgProcess* imgProc;

signals:
    void colorChanged();
    void uriChanged();
};

#endif // PICSHOWPAINTEDITEM_H
