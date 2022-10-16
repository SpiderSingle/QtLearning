#include "framelesswidgetdemo.h"
#include "ui_framelesswidgetdemo.h"

#include <QMouseEvent>
#include <QMenu>
#include <QPoint>
#include <QGraphicsDropShadowEffect>

FramelessWidgetDemo::FramelessWidgetDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FramelessWidgetDemo)
{
    ui->setupUi(this);
    //设置无边框
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_QuitOnClose,false);
    this->setAttribute(Qt::WA_TranslucentBackground,true);
    this->resize(800,600);
    QGraphicsDropShadowEffect*  shadow=new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(5);
    shadow->setColor(QColor(255,10,200));
    shadow->setXOffset(-1);//设置向右下方偏移
    shadow->setYOffset(-1);//设置向右下方偏移
    ui->shadowWidget->setGraphicsEffect(shadow);

}

FramelessWidgetDemo::~FramelessWidgetDemo()
{
    delete ui;
}

void FramelessWidgetDemo::contextMenuEvent(QContextMenuEvent *menuEvent)
{
    QMenu menu(this);
    menu.setStyleSheet("QMenu{color:red}");
    QAction exitAction("&退出");
    menu.addAction(&exitAction);
    menu.addSeparator();
    QObject::connect(&exitAction,&QAction::triggered,this,[this](){
        this->close();
    });
    menu.exec(QCursor::pos());
}

void FramelessWidgetDemo::mouseMoveEvent(QMouseEvent *event)
{
    //不断的更新左上角窗口的坐标的位置
    QPoint MousePos=event->globalPos();
    QPoint WidgetTopLeftPos=MousePos-m_Mouse2WidgetFixPos;
    this->move(WidgetTopLeftPos);
    QWidget::mouseMoveEvent(event);
}

void FramelessWidgetDemo::mousePressEvent(QMouseEvent *event)
{
    /*
      主要计算当前的鼠标的位置与窗口的坐上角的位置差值
    */
    //QPoint MousePos=event->globalPos();
    //QPoint WidgetTopLeftPos=this->geometry().topLeft();
    //m_Mouse2WidgetFixPos=MousePos-WidgetTopLeftPos;
    m_Mouse2WidgetFixPos=event->pos();  //得到鼠标相当于窗口的位置
    QWidget::mousePressEvent(event);
}
void FramelessWidgetDemo::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    m_Mouse2WidgetFixPos=QPoint();
}

void FramelessWidgetDemo::on_btn_close_clicked()
{
    this->close();
}

void FramelessWidgetDemo::on_btn_Max_clicked()
{
    this->showMaximized();
}

void FramelessWidgetDemo::on_btn_Min_clicked()
{
    this->showNormal();
}
