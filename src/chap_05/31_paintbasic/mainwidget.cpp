#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
    QFont font("ZYSong18030",12);
    setFont(font);
    
    area = new PaintArea;

    /*lable*/
    QLabel *label1 = new QLabel(tr("Shape:"));          // 形状
    QLabel *label2 = new QLabel(tr("Pen Width:"));   // 画笔线宽
    QLabel *label3 = new QLabel(tr("Pen Color:"));    // 画笔颜色
    QLabel *label4 = new QLabel(tr("Pen Style:"));     // 画笔风格
    QLabel *label5 = new QLabel(tr("Pen Cap:"));      // 画笔顶端
    QLabel *label6 = new QLabel(tr("Pen Join:"));      // 画笔连接点
    QLabel *label7 = new QLabel(tr("Brush:"));          // 画刷

    /*形状*/
    shapeComboBox = new QComboBox;
    shapeComboBox->addItem(tr("Line"), PaintArea::Line);                                  // 直线
    shapeComboBox->addItem(tr("Polygon"), PaintArea::Polygon);                     // 多边形
    shapeComboBox->addItem(tr("Rectangle"), PaintArea::Rectangle);               // 长方形
    shapeComboBox->addItem(tr("Round Rectangle"), PaintArea::RoundRect); // 圆角方形
    shapeComboBox->addItem(tr("Ellipse"), PaintArea::Ellipse);                // 椭圆形
    shapeComboBox->addItem(tr("Path"), PaintArea::Path);                       // 路径
    shapeComboBox->addItem(tr("Polyline"), PaintArea::Polyline);            // 多边线
    shapeComboBox->addItem(tr("Arc"), PaintArea::Arc);                            // 弧
    shapeComboBox->addItem(tr("Points"), PaintArea::Points);                 // 点
    shapeComboBox->addItem(tr("Text"), PaintArea::Text);                        // 文字
    shapeComboBox->addItem(tr("Pixmap"), PaintArea::Pixmap);             //  图片
    connect(shapeComboBox,SIGNAL(activated(int)),this,SLOT(slotShape(int)));

    /*画笔宽度*/
    widthSpinBox = new QSpinBox;
    widthSpinBox->setRange(0,20);
    connect(widthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(slotPenWidth(int)));

    /* 画笔颜色*/
    colorFrame = new QFrame;
    colorFrame->setAutoFillBackground(true);
    colorFrame->setPalette(QPalette(Qt::blue));
    QPushButton *colorPushButton = new QPushButton(tr("Change"));
    connect(colorPushButton,SIGNAL(clicked()),this,SLOT(slotPenColor()));

    /* 画笔风格*/
    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem(tr("Solid"), Qt::SolidLine);
    penStyleComboBox->addItem(tr("Dash"), Qt::DashLine);
    penStyleComboBox->addItem(tr("Dot"), Qt::DotLine);
    penStyleComboBox->addItem(tr("Dash Dot"), Qt::DashDotLine);
    penStyleComboBox->addItem(tr("Dash Dot Dot"), Qt::DashDotDotLine);
    penStyleComboBox->addItem(tr("None"), Qt::NoPen);
    connect(penStyleComboBox,SIGNAL(activated(int)),this,SLOT(slotPenStyle(int)));

    /* 画笔顶端*/
    penCapComboBox = new QComboBox;
    penCapComboBox->addItem(tr("Flat"), Qt::FlatCap);
    penCapComboBox->addItem(tr("Square"), Qt::SquareCap);
    penCapComboBox->addItem(tr("Round"), Qt::RoundCap);
    connect(penCapComboBox,SIGNAL(activated(int)),this,SLOT(slotPenCap(int)));

    /* 画笔连接点*/
    penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem(tr("Miter"), Qt::MiterJoin);
    penJoinComboBox->addItem(tr("Bevel"), Qt::BevelJoin);
    penJoinComboBox->addItem(tr("Round"), Qt::RoundJoin);
    connect(penJoinComboBox,SIGNAL(activated(int)),this,SLOT(slotPenJoin(int)));

    /* 画刷*/
    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("Linear Gradient"), Qt::LinearGradientPattern);
    brushStyleComboBox->addItem(tr("Radial Gradient"), Qt::RadialGradientPattern);
    brushStyleComboBox->addItem(tr("Conical Gradient"), Qt::ConicalGradientPattern);
    brushStyleComboBox->addItem(tr("Texture"), Qt::TexturePattern);
    brushStyleComboBox->addItem(tr("Solid"), Qt::SolidPattern);
    brushStyleComboBox->addItem(tr("Horizontal"), Qt::HorPattern);
    brushStyleComboBox->addItem(tr("Vertical"), Qt::VerPattern);
    brushStyleComboBox->addItem(tr("Cross"), Qt::CrossPattern);
    brushStyleComboBox->addItem(tr("Backward Diagonal"), Qt::BDiagPattern);
    brushStyleComboBox->addItem(tr("Forward Diagonal"), Qt::FDiagPattern);
    brushStyleComboBox->addItem(tr("Diagonal Cross"), Qt::DiagCrossPattern);
    brushStyleComboBox->addItem(tr("Dense 1"), Qt::Dense1Pattern);
    brushStyleComboBox->addItem(tr("Dense 2"), Qt::Dense2Pattern);
    brushStyleComboBox->addItem(tr("Dense 3"), Qt::Dense3Pattern);
    brushStyleComboBox->addItem(tr("Dense 4"), Qt::Dense4Pattern);
    brushStyleComboBox->addItem(tr("Dense 5"), Qt::Dense5Pattern);
    brushStyleComboBox->addItem(tr("Dense 6"), Qt::Dense6Pattern);
    brushStyleComboBox->addItem(tr("Dense 7"), Qt::Dense7Pattern);
    brushStyleComboBox->addItem(tr("None"), Qt::NoBrush);
    connect(brushStyleComboBox,SIGNAL(activated(int)),this,SLOT(slotBrush(int)));
    
    /*布局*/
    QGridLayout *ctrlLayout = new QGridLayout;
    int labelCol=0;
    int contentCol=1;
    ctrlLayout->addWidget(label1,0,labelCol);
    ctrlLayout->addWidget(shapeComboBox,0,contentCol);
    ctrlLayout->addWidget(label2,1,labelCol);
    ctrlLayout->addWidget(widthSpinBox,1,contentCol);
    ctrlLayout->addWidget(label3,2,labelCol);
    ctrlLayout->addWidget(colorFrame,2,contentCol);
    ctrlLayout->addWidget(colorPushButton,2,2);
    ctrlLayout->addWidget(label4,3,labelCol);
    ctrlLayout->addWidget(penStyleComboBox,3,contentCol);
    ctrlLayout->addWidget(label5,4,labelCol);
    ctrlLayout->addWidget(penCapComboBox,4,contentCol);
    ctrlLayout->addWidget(label6,5,labelCol);
    ctrlLayout->addWidget(penJoinComboBox,5,contentCol);
    ctrlLayout->addWidget(label7,6,labelCol);
    ctrlLayout->addWidget(brushStyleComboBox,6,contentCol);
    
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(area);
    mainLayout->addLayout(ctrlLayout);
    mainLayout->setMargin(10);
    mainLayout->setSpacing(10);
    setLayout(mainLayout);    
    
    setWindowTitle(tr("Basic Paint"));    
    /*init */
    slotShape(0);
    slotPenWidth(0);
    slotPenStyle(0);
    slotPenCap(0);
    slotPenJoin(0);
    slotBrush(0);
}
   
void MainWidget::slotShape(int value)
{
    PaintArea::Shape shape = PaintArea::Shape(shapeComboBox->itemData(value,  Qt::UserRole).toInt());
    area->setShape(shape);
}

void MainWidget::slotPenWidth(int value)   // 画笔宽度
{

     QColor color = colorFrame->palette().color(QPalette::Window);  // 读取画笔颜色

     Qt::PenStyle style = Qt::PenStyle(      // 读取画笔风格
             penStyleComboBox->itemData( penStyleComboBox->currentIndex(), Qt::UserRole ).toInt()
                  );

     Qt::PenCapStyle cap = Qt::PenCapStyle(   // 读取画笔顶端
            penCapComboBox->itemData( penCapComboBox->currentIndex(), Qt::UserRole ).toInt()
                                                                   );
     Qt::PenJoinStyle join = Qt::PenJoinStyle(  // 读取画笔连接点
           penJoinComboBox->itemData( penJoinComboBox->currentIndex(), Qt::UserRole ).toInt()
                                                                     );
     area->setPen(QPen(color, value, style, cap, join));
}

void MainWidget::slotPenColor() // 设置画笔颜色
{
    QColor color = QColorDialog::getColor(Qt::blue);
    colorFrame->setPalette(QPalette(color));
    
    int width = widthSpinBox->value();   // 读取画笔宽度

    Qt::PenStyle style = Qt::PenStyle(       // 读取画笔风格
            penStyleComboBox->itemData( penStyleComboBox->currentIndex(), Qt::UserRole ).toInt()
                                                            );

    Qt::PenCapStyle cap = Qt::PenCapStyle(  // 读取画笔顶端
            penCapComboBox->itemData( penCapComboBox->currentIndex(),  Qt::UserRole).toInt()
                                                                    );

    Qt::PenJoinStyle join = Qt::PenJoinStyle(  // 读取画笔连接点
            penJoinComboBox->itemData( penJoinComboBox->currentIndex(),  Qt::UserRole).toInt()
                                                                        );

    area->setPen(QPen(color, width, style, cap, join));    
}

void MainWidget::slotPenStyle(int value) // 画笔风格
{
    int width = widthSpinBox->value();
    QColor color = colorFrame->palette().color(QPalette::Window);
    Qt::PenStyle style = Qt::PenStyle(
            penStyleComboBox->itemData(value,  Qt::UserRole).toInt()
                                                        );
    Qt::PenCapStyle cap = Qt::PenCapStyle(
             penCapComboBox->itemData( penCapComboBox->currentIndex(),  Qt::UserRole).toInt()
                                                                    );
    Qt::PenJoinStyle join = Qt::PenJoinStyle(
            penJoinComboBox->itemData( penJoinComboBox->currentIndex(),  Qt::UserRole).toInt()
                                                                       );

    area->setPen(QPen(color, width, style, cap, join));  
}

void MainWidget::slotPenCap(int value)
{
    int width = widthSpinBox->value();
    QColor color = colorFrame->palette().color(QPalette::Window);
    Qt::PenStyle style = Qt::PenStyle(
            penStyleComboBox->itemData( penStyleComboBox->currentIndex(),  Qt::UserRole).toInt()
                                                        );

    Qt::PenCapStyle cap = Qt::PenCapStyle(
            penCapComboBox->itemData(value,  Qt::UserRole).toInt()
                                                                       );

    Qt::PenJoinStyle join = Qt::PenJoinStyle(
            penJoinComboBox->itemData( penJoinComboBox->currentIndex(),  Qt::UserRole).toInt()
                                                                       );

    area->setPen(QPen(color, width, style, cap, join)); 
}

void MainWidget::slotPenJoin(int value)
{
    int width = widthSpinBox->value();
    QColor color = colorFrame->palette().color(QPalette::Window);
    Qt::PenStyle style = Qt::PenStyle(
            penStyleComboBox->itemData( penStyleComboBox->currentIndex(),  Qt::UserRole).toInt()
                                                        );

    Qt::PenCapStyle cap = Qt::PenCapStyle(
            penCapComboBox->itemData( penCapComboBox->currentIndex(),  Qt::UserRole).toInt()
                                                                       );

    Qt::PenJoinStyle join = Qt::PenJoinStyle(
           penJoinComboBox->itemData(value,  Qt::UserRole).toInt()
                                                                        );

    area->setPen(QPen(color, width, style, cap, join)); 
}

void MainWidget::slotBrush(int value)  // 设置画刷
{
     Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(value, Qt::UserRole).toInt());

     if (style == Qt::LinearGradientPattern) {
             QLinearGradient linearGradient(0, 0, 400, 400);
             linearGradient.setColorAt(0.0, Qt::white);
             linearGradient.setColorAt(0.2, Qt::green);
             linearGradient.setColorAt(1.0, Qt::black);
             area->setBrush(linearGradient);
     } else if (style == Qt::RadialGradientPattern) {
             QRadialGradient radialGradient(200, 200, 150, 150, 100);
             radialGradient.setColorAt(0.0, Qt::white);
             radialGradient.setColorAt(0.2, Qt::green);
             radialGradient.setColorAt(1.0, Qt::black);
             area->setBrush(radialGradient);
     } else if (style == Qt::ConicalGradientPattern) {
             QConicalGradient conicalGradient(200, 200, 30);
             conicalGradient.setColorAt(0.0, Qt::white);
             conicalGradient.setColorAt(0.2, Qt::green);
             conicalGradient.setColorAt(1.0, Qt::black);
             area->setBrush(conicalGradient);
     } else if (style == Qt::TexturePattern) {
             area->setBrush(QBrush(QPixmap(":/images/cheese.jpg")));
     } else {
             area->setBrush(QBrush(Qt::green, style));
     }	
}

