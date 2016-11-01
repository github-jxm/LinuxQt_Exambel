#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtGui>
#include "paintarea.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent=0);
    
public slots:
    void slotShape(int);    // 形状
    void slotPenWidth(int); // 画笔线宽
    void slotPenColor();    // 画笔颜色
    void slotPenStyle(int); // 画笔风格
    void slotPenCap(int);   // 画笔顶点
    void slotPenJoin(int);  // 画笔接点
    void slotBrush(int);    // 画刷
    
private:
    PaintArea *area;

    QComboBox *shapeComboBox;
    QSpinBox  *widthSpinBox;
    QComboBox *penStyleComboBox;
    QComboBox *penCapComboBox;
    QComboBox *penJoinComboBox;
    QComboBox *brushStyleComboBox;
    QFrame    *colorFrame;
};

#endif 	// MAINWIDGET_H
