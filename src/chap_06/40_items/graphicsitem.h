#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsItem>

class QGraphicsSceneMouseEvent;

//  Flash Item  闪烁的圆
class FlashItem : public QGraphicsItem , QObject
{
public:
    FlashItem();
    
    
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    
    void timerEvent(QTimerEvent *);

private:
    bool flash;
    QTimer *timer;
};

//  Star Item     星星
class StarItem : public QGraphicsItem
{
public:
    StarItem();
    
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    
private:
    QPixmap pix;
};


#endif 	// GRAPHICSITEM_H
