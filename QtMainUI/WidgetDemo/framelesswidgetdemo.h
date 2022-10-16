#ifndef FRAMELESSWIDGETDEMO_H
#define FRAMELESSWIDGETDEMO_H
/*
无边框的窗口 可以使用鼠标拖拽
*/
#include <QWidget>
#include <QPoint>

namespace Ui {
class FramelessWidgetDemo;
}

class FramelessWidgetDemo : public QWidget
{
    Q_OBJECT

public:
    explicit FramelessWidgetDemo(QWidget *parent = 0);
    ~FramelessWidgetDemo();

    /*
     * 重写鼠标移动事件
    */
    void  mouseMoveEvent(QMouseEvent* event);
    /*
     * 重写鼠标按下事件
    */
    void  mousePressEvent(QMouseEvent* event);
    /*
    * 重写鼠标抬起事件
    */
    void  mouseReleaseEvent(QMouseEvent* event);

    //重写右击菜单事件
    void  contextMenuEvent(QContextMenuEvent* menuEvent);

private slots:
    void on_btn_close_clicked();

    void on_btn_Max_clicked();

    void on_btn_Min_clicked();

private:
    Ui::FramelessWidgetDemo *ui;
    //移动到的窗口的坐上角位置
    QPoint                   m_Mouse2WidgetFixPos;
};









#endif // FRAMELESSWIDGETDEMO_H
