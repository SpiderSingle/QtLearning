#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include "WidgetDemo.h"
#include "SignalSlotsDemo.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_widget_btn_clicked();

    void on_signalslot_btn_clicked();

private:
    Ui::MainWindow *ui;

private:
    QPointer<WidgetDemo>         m_WidgetDemo;
    QPointer<SignalSlotsDemo> m_SignalSlotDemo;
};

#endif // MAINWINDOW_H
