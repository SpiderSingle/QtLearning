#include "WidgetDemo.h"
#include "ui_WidgetDemo.h"

#include <QMessageBox>

WidgetDemo::WidgetDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_ui),
    m_pFrameLessWidgetDemo(new FramelessWidgetDemo)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose,false);
}

WidgetDemo::~WidgetDemo()
{
    delete ui;
}

void WidgetDemo::on_btn_getSize_clicked()
{
    QRect rect=this->geometry();
    QString strDesc;
    strDesc.sprintf("x:%d,y:%d,width:%d,height:%d",
                    rect.x(),rect.y(),rect.width(),rect.height());
    setTextEdit(strDesc);
}
void WidgetDemo::setTextEdit(const QString& str)
{
    ui->showTextEdit->setText(str);
}

void WidgetDemo::on_btn_setSize_clicked()
{
    this->resize(800,600);
    on_btn_getSize_clicked();
}

void WidgetDemo::on_btn_setFixSize_clicked()
{
    this->setFixedSize(500,500);
    on_btn_getSize_clicked();
}

void WidgetDemo::on_btn_setMinSize_clicked()
{
    this->setMinimumSize(500,300);
    on_btn_getSize_clicked();
}

void WidgetDemo::on_btn_setMaxSize_clicked()
{
    this->setMaximumSize(1000,800);
    on_btn_getSize_clicked();
}

void WidgetDemo::on_btn_moveWindow_clicked()
{
    //move函数会存在便宜,不能到达指定的位置,setGeometry是可以的
    //move(0,0)实际是(10,45)
    this->move(0,0);
    on_btn_getSize_clicked();
}

void WidgetDemo::on_btn_setGeometry_clicked()
{
    this->setGeometry(QRect(0,0,this->width(),this->height()));
    on_btn_getSize_clicked();
}

void WidgetDemo::on_pushButton_clicked()
{
    if(!m_pFrameLessWidgetDemo.isNull()){
        m_pFrameLessWidgetDemo->show();
    }
    else{
       QMessageBox::warning(NULL,"警告","m_pFrameLessWidgetDemo为空");
    }
}
