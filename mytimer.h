#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    explicit MyTimer();
    QTimer *timer;

public slots:
    void MyTimerSlot();
};

#endif // MYTIMER_H
