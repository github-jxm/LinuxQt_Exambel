#include "graphicsitem.h"
#include <QtGui>

/*  闪烁的圆  */
//   Flash Item
FlashItem::FlashItem()
{   
    flash = true;
    setFlag(ItemIsMovable);
    
    startTimer(50);
}

QRectF FlashItem::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-10 - adjust, -10 - adjust,    43 + adjust, 43 + adjust);
}

void FlashItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7,-7,40,40);  /* 绘制阴影区域*/
    
    painter->setPen(QPen(Qt::black,0));
    painter->setBrush(flash ? (Qt::red):(Qt::yellow));
    painter->drawEllipse(-10,-10,40,40);

}

void FlashItem::timerEvent(QTimerEvent * )
{
    flash = !flash;
    update();
}

/*     星星    */
//  Star Item
StarItem::StarItem()
{
    pix.load(":/images/image.png");
}

QRectF StarItem::boundingRect() const
{
    return QRectF(-pix.width()/2,-pix.height()/2,pix.width(),pix.height());
}

void StarItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect().topLeft(),pix);
}




