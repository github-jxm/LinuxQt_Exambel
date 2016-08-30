#include "layoutdlg.h"

LayoutDlg::LayoutDlg(QWidget *parent, Qt::WindowFlags f)
        : QDialog(parent,f)
{
    setWindowTitle(tr("User Infomation"));  // 用户基本资料
    
    // create 
    label1 = new QLabel(tr("User Name:"));  // 用户名
    label2 = new QLabel(tr("Name:"));           // 姓名
    label3 = new QLabel(tr("Sex"));                 // 性别
    label4 = new QLabel(tr("Department:"));  // 部门
    label5 = new QLabel(tr("Age:"));                // 年龄
    labelOther = new QLabel(tr("Remark"));  // 备注
    labelOther->setFrameStyle(QFrame::Panel|QFrame::Sunken);  
    lineEditUser = new QLineEdit();
    lineEditName = new QLineEdit();
    comboBoxSex = new QComboBox();
    comboBoxSex->insertItem(0,tr("Female")); // 女
    comboBoxSex->insertItem(1,tr("Male"));     // 男
    textEditDepartment = new QTextEdit();
    lineEditAge = new QLineEdit();

    label7 = new QLabel(tr("Head"));                // 头像
    labelIcon = new QLabel();
    QPixmap icon(":/images/icon.png");
    labelIcon->resize(icon.width(),icon.height());
    labelIcon->setPixmap(icon);
    pushButtonIcon = new QPushButton();
    pushButtonIcon->setText(tr("Change"));   // 更新
    QHBoxLayout *hLayout = new QHBoxLayout;  /** 水平布局 **/
    hLayout->setSpacing(20);         // 设定控件之间的间距
    hLayout->addWidget(label7);   // 头像
    hLayout->addWidget(labelIcon);
    hLayout->addWidget(pushButtonIcon);
    
    label6 = new QLabel(tr("Individual:"));   // 个人说明
    textEditDisc = new QTextEdit();
    
    pushButtonOK = new QPushButton(tr("OK"));   // 确定
    pushButtonExit = new QPushButton(tr("Cancel"));  // 取消
    
    //  Lay out
    /**     left layout -- is a grid layout **/
    QGridLayout * leftLayout = new QGridLayout();

    int labelCol = 0;
    int contentCol = 1;

    leftLayout->addWidget(label1,0,labelCol);		// user name row  用户名行
    leftLayout->addWidget(lineEditUser,0,contentCol);
    
    leftLayout->addWidget(label2,1,labelCol);		// name row    姓名行
    leftLayout->addWidget(lineEditName,1,contentCol);
    
    leftLayout->addWidget(label3,2,labelCol);		// sex row  性别行
    leftLayout->addWidget(comboBoxSex,2,contentCol);
    
    leftLayout->addWidget(label4,3,labelCol,Qt::AlignTop);  // department row  部门行
    leftLayout->addWidget(textEditDepartment,3,contentCol);

    leftLayout->addWidget(label5,4,labelCol);		// age row  年龄行
    leftLayout->addWidget(lineEditAge,4,contentCol);
    
    leftLayout->addWidget(labelOther,5,labelCol,1,2);		// other  备注行

    leftLayout->setColumnStretch(0,1);  // 设置两列的占空比
    leftLayout->setColumnStretch(1,3);
  
    /** right layout -- is a vBoxLayout    **/
    QVBoxLayout *rightLayout = new QVBoxLayout();  // 垂直布局
    rightLayout->setMargin(10);
    rightLayout->addLayout(hLayout);
    rightLayout->addWidget(label6);
    rightLayout->addWidget(textEditDisc);
    
    /**  buttom layout -- is a hBoxLayout **/
    QHBoxLayout * bottomLayout = new QHBoxLayout();
    bottomLayout->addStretch();
    bottomLayout->addWidget(pushButtonOK); 
    bottomLayout->addWidget(pushButtonExit);

    /**   main layout -- is a GridLayout **/
    QGridLayout * mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);  // 对话框边距 15
    mainLayout->setSpacing(10);  // 控件之间间距10
    mainLayout->addLayout(leftLayout,0,0);
    mainLayout->addLayout(rightLayout,0,1);
    mainLayout->addLayout(bottomLayout,1,0,1,2);  // 占用 1 行 2列
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);  // 控件按照 sizeHint()大小显示
    
    connect(pushButtonExit,SIGNAL(clicked()),this,SLOT(reject()));
}

