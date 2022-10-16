#ifndef SIGNALSLOTSWIDGET_H
#define SIGNALSLOTSWIDGET_H

#include <QWidget>

namespace Ui {
class SignalSlotsWidget;
}

class SignalSlotsDemo : public QWidget
{
    Q_OBJECT

public:
    explicit SignalSlotsDemo(QWidget* parent=nullptr);
    ~SignalSlotsDemo();

private slots:


    void on_btn_Min_clicked();

private:
    Ui::SignalSlotsWidget *ui;
};

#endif // SIGNALSLOTSWIDGET_H
