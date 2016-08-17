#include <QApplication>
#include <QTranslator>
#include <QTextEdit>
#include <QListWidget>
#include <QSplitter>
#include <QTextCodec>
#include <QStackedWidget>

#include "content.h"

int main( int argc, char * argv[] )
{
    QApplication app(argc, argv);
    QFont font("AR PL KaitiM GB",12);
    app.setFont(font);
    
    QTranslator translator;
    translator.load("combine_zh");
    app.installTranslator(&translator);    
 
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal,0);
    splitterMain->setOpaqueResize(true);  // 拖动分隔条,是否是 更新显示
    QListWidget *list = new QListWidget(splitterMain);
    list->insertItem(0,QObject::tr("Base Info"));  // 基本信息
    list->insertItem(1,QObject::tr("Contact"));     // 联系方式
    list->insertItem(2,QObject::tr("Detail"));        // 详细信息
    
    Content *content = new Content(splitterMain);
    
    QObject::connect(list,SIGNAL(currentRowChanged(int)),content->stack,SLOT(setCurrentIndex(int)));
    
    splitterMain->setWindowTitle(QObject::tr("Change User Info"));   // 修改用户信息
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    splitterMain->setMaximumSize(splitterMain->minimumSize());
    splitterMain->show();
    return app.exec();
}
