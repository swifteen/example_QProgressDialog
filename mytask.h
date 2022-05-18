#ifndef MYTASK_H
#define MYTASK_H


#include <QObject>
#include <QProgressDialog>
#include <QTimer>

class MyTask : public QObject
{
    Q_OBJECT
public:
    explicit MyTask(QObject *parent = 0);

signals:

public slots:
    void perform();
    void cancel();
private:
    int steps;
    QProgressDialog *pd;
    QTimer *t;

};
#endif // MYTASK_H
