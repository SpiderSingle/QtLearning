#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "WidgetDemo.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_WidgetDemo(new  WidgetDemo()),
    m_SignalSlotDemo(new SignalSlotsDemo())

{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    m_WidgetDemo->close();
    m_SignalSlotDemo->close();
    delete ui;
}

void MainWindow::on_widget_btn_clicked()
{
   if(!m_WidgetDemo.isNull()){
        m_WidgetDemo->show();
   }
   else{
    QMessageBox::warning(NULL,"警告","当前m_WidgetDemo指针为空！！！");
   }
}

void MainWindow::on_signalslot_btn_clicked()
{
  if(!m_SignalSlotDemo.isNull())
      m_SignalSlotDemo->show();
  else{
   QMessageBox::warning(NULL,"警告","m_SignalSlotDemo指针为空");
  }
}
