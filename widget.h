#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mytask.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_modalButton_clicked();

    void on_modelessButton_clicked();
private:
    Ui::Widget *ui;
    MyTask *myTask;
};
#endif // WIDGET_H
