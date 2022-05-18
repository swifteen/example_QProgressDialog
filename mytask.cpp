#include "mytask.h"

#include <QDebug>
MyTask::MyTask(QObject *parent) :
    QObject(parent), steps(0)
{
    qDebug()<<__FUNCTION__<<__LINE__<<__TIME__<<__TIMESTAMP__;
    pd = new QProgressDialog("1Task in progress",
                             "Cancel",
                             0, 0,nullptr,Qt::WindowFlags()|Qt::FramelessWindowHint);
    pd->setMinimumDuration(0);
    connect(pd, SIGNAL(canceled()), this, SLOT(cancel()));
    t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(perform()));
    t->start(1000);
    pd->setStyleSheet("QProgressBar {\
                      border: 1px solid black;\
                      text-align: top;\
                      padding: 1px;\
                      border-radius: 7px;\
                      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1,\
                      stop: 0 #fff,\
                      stop: 0.4999 #eee,\
                      stop: 0.5 #ddd,\
                      stop: 1 #eee );\
                      width: 15px;\
                      }\
                      QProgressBar::chunk {\
                      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,\
                      stop: 0 #0000ff,\
                      stop: 1 #ff0000 );\
                      border-radius: 7px;\
                      border: 1px solid black;\
                      }");
                      qDebug()<<__FUNCTION__<<__LINE__<<__TIME__<<__TIMESTAMP__;
                      pd->show();
}

void MyTask::perform()
{
//    pd->setValue(steps);
    QString lab = QString("1Task in progress   %1/%2").arg(steps).arg(20);
    pd->setLabelText(lab);
    //... perform one percent of the operation
     qDebug()<<__FUNCTION__<<__LINE__<<steps;
     qDebug()<<__FUNCTION__<<__LINE__<<__TIME__<<__TIMESTAMP__;
    steps++;
    if (steps > pd->maximum())
        t->stop();
}

void MyTask::cancel()
{
    t->stop();
    //... cleanup
}
