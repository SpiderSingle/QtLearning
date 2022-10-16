#include "SignalSlotsDemo.h"
#include "ui_SignalSlotDemo.h"

SignalSlotsDemo::SignalSlotsDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignalSlotsWidget)
{
    ui->setupUi(this);

    //当父窗口关闭的时候 子窗口自动销毁 进行析构函数的调用
    this->setAttribute(Qt::WA_QuitOnClose,false);


    //1:使用QT4的信号与槽函数的方式 编译时不检测函数名称的错误
    QObject::connect(ui->btn_Max,SIGNAL(clicked()),this,SLOT(showMaximized()));
    //2:使用QT5的方式,使用函数的地址的方式 编译时检测函数名称错误的问题
    QObject::connect(ui->btn_Normal,&QPushButton::clicked,this,&QWidget::showNormal);


    //5:使用了Lmdbda表达式的方式
    QObject::connect(ui->btn_changeTitle,&QPushButton::clicked,this,[this]()->void{

                         this->setWindowTitle("使用Lmabda的信号与槽");
                     });
}

SignalSlotsDemo::~SignalSlotsDemo()
{
    delete ui;
}


void SignalSlotsDemo::on_btn_Min_clicked()
{

    this->showMinimized();
}
