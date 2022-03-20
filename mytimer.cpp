#include "mytimer.h"
#include "globals.h"

MyTimer::MyTimer()
{
    //create a timer
    timer = new QTimer(this);

    //setup signal and slot
    connect(timer, SIGNAL(timeout()), this, SLOT(MyTimerSlot()));
}

void MyTimer::MyTimerSlot() {

}
