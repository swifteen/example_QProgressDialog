#include "widget.h"
#include "ui_widget.h"
#include <QProgressDialog>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::on_modalButton_clicked()
{
    int numTasks = 100000;
    QProgressDialog progress("2Task in progress...", "Cancel", 0, numTasks, this);
    progress.setWindowModality(Qt::WindowModal);
    progress.setMinimumDuration(0);
    qDebug()<<__FUNCTION__<<__LINE__;
    for (int i = 0; i < numTasks; i++) {
        progress.setValue(i);
qDebug()<<__FUNCTION__<<__LINE__;
        if (progress.wasCanceled())
            break;
    }
    progress.setValue(numTasks);
    qDebug()<<__FUNCTION__<<__LINE__;
}

void Widget::on_modelessButton_clicked()
{
    qDebug()<<__FUNCTION__<<__LINE__<<__TIME__<<__TIMESTAMP__;
    myTask = new MyTask;
    qDebug()<<__FUNCTION__<<__LINE__<<__TIME__<<__TIMESTAMP__;
}

