#include "PicShowPanel.h"
#include <QPainter>


PicShowPaintedItem::PicShowPaintedItem(QQuickItem *parent)
    :QQuickPaintedItem(parent)
{
    //PixelTips,TextTips是跟PicShow绑定的..
    //一个PicShow一般是对应一套Pixel,Text的才行!?
    layer = new PixelTipsLayer(this);
    layers.append(layer);

    //这里是一个处理类..里面实现了具体的处理方法..
    //比如一个处理类放在一个线程里
    imgProc = new ImgProcess(this);

}


void PicShowPaintedItem::updateGUI()
{
    //setColor(QColor(Qt::transparent));
    update();
}

QString PicShowPaintedItem::name() const
{
    return myName;
}
void PicShowPaintedItem::setName(const QString &name)
{
    myName = name;
}
QColor PicShowPaintedItem::color() const
{
    return myColor;
}
void PicShowPaintedItem::setColor(const QColor &color)
{
    if (color != myColor)
    {
       myColor = color;
       update();   // repaint with the new color
       emit colorChanged();
    }
}

QString PicShowPaintedItem::uri() const
{
    return myUri;
}

//#include "QByteArray"

void PicShowPaintedItem::setUri(const QString &uri)
{
    if(myUri.compare(uri) != 0)
    {
        qDebug() << "changed uri : " << uri;
        myUri = uri;
        update();
        emit uriChanged();
    }
    //qDebug() << "changed uri : " << uri;
//    if(uri != myUri)
//    {
//        //myUri = uri;
//        //渲染...?
//        qDebug() << "changed uri : " << uri;
//        //emit uriChanged();
//    }
}

#include "QFileInfo"

void PicShowPaintedItem::paint(QPainter *painter)
{
    QPen pen(myColor,2);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);

    //painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 90 * 16, 290 * 16);

    QRect pixmapRect   =   QRect(0,0,this->width(),this->height());//渲染窗(等于截取)

    QFileInfo fileInfo(myUri.replace("file:///",""));

    QImage img = QImage(myUri);

    painter->scale(width() / img.width(), height() / img.height());


    qDebug() << width() << height() << img.width() << img.height();

    //img.scaled(this->width(), this->height());

    imgProc->CheckDataInfo(img);

    if(fileInfo.isFile())
    {
        //painter->drawPixmap(0,0,this->width(),this->height(),QPixmap(myUri));
        painter->drawImage(pixmapRect, img, pixmapRect);
        // qDebug() << img;
        //painter->drawImage(0,0,layer->image,200,200);
        painter->drawImage(pixmapRect, layer->image, pixmapRect);

    }
}
