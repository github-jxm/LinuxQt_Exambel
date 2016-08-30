#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QtGui>

class Geometry : public QDialog
{
    Q_OBJECT
public:
    Geometry();
    
    QLabel *label1; // x():
    QLabel *label2; // y():
    QLabel *label3; // framGeometry():
    QLabel *label4; // pos()
    QLabel *label5;// geometry():
    QLabel *label6; // width():
    QLabel *label7; // height():
    QLabel *label8; // rect():
    QLabel *label9; //size():

    QLabel *xLabel;
    QLabel *yLabel;
    QLabel *frameGeoLabel;
    QLabel *posLabel;
    QLabel *geoLabel;
    QLabel *widthLabel;
    QLabel *heightLabel;
    QLabel *rectLabel;
    QLabel *sizeLabel;
    
    void updateLabel();

protected:
    void moveEvent(QMoveEvent *);
    void resizeEvent(QResizeEvent *);

};

#endif // GEOMETRY_H
