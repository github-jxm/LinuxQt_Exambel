#ifndef  PAINTAREA_H
#define PAINTAREA_H

#include <QtGui>

class PaintArea : public QWidget
{
    Q_OBJECT
public:                    /* 线   长方形    圆角方形     椭圆形    多边形 */
    enum Shape {    Line, Rectangle, RoundRect, Ellipse, Polygon,
                                /* 多边线   点      弧　路径　文字　图片　*/
                                Polyline, Points, Arc, Path, Text, Pixmap};
    PaintArea(QWidget *parent=0);
     
    void setShape (Shape);
    void setPen (QPen);
    void setBrush (QBrush);
    
    void paintEvent(QPaintEvent *);

private:
    Shape    shape;
    QBrush brush;
    QPen     pen;
};

#endif 
