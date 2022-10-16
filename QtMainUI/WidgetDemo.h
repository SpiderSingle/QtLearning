#ifndef WIDGET_UI_H
#define WIDGET_UI_H

#include <QWidget>
#include <QPointer>
#include "WidgetDemo/framelesswidgetdemo.h"

namespace Ui {
class widget_ui;
}

class WidgetDemo : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetDemo(QWidget *parent = 0);
    ~WidgetDemo();

private slots:
    void on_btn_getSize_clicked();

    void on_btn_setSize_clicked();

    void on_btn_setFixSize_clicked();

    void on_btn_setMinSize_clicked();

    void on_btn_setMaxSize_clicked();

    void on_btn_moveWindow_clicked();

    void on_btn_setGeometry_clicked();

    void on_pushButton_clicked();

private:
    Ui::widget_ui *ui;
    QPointer<FramelessWidgetDemo>  m_pFrameLessWidgetDemo;
private:
    void    setTextEdit(const QString& str);
};

#endif // WIDGET_UI_H
