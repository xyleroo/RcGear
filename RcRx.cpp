/**
 * Simple Arduino RC Receiver for one Channel
 * Author: Heinz Bruederlin
 * Date: 01/2018
 */
#include "RcRx.h"

RcRx* RcRx::singleton = NULL;

/**
 * only port 2 or 3 support external interrupts
 * (otherwise we have to use pin change interrupt code ...)
 */
RcRx::RcRx(int _portNo) {
    portNo = _portNo;
}

void RcRx::init(void) {
    startTime = 0;
    pulseWidth = 0;
    lastInterruptTime = 0;
    if (!singleton) {
        singleton = this;
    }
    attachInterrupt(digitalPinToInterrupt(portNo), calcSignal, CHANGE);
}

unsigned int RcRx::value(void) {
    if (pulseWidth < 800 || pulseWidth > 2200) {
        return 0;
    }
    return pulseWidth;
}

void RcRx::calcSignal(void) {
    if (!singleton) return;
    singleton->lastInterruptTime = micros();
    if (digitalRead(singleton->portNo) == HIGH) {
        singleton->startTime = singleton->lastInterruptTime;
    } else if (singleton->startTime != 0) {
        singleton->pulseWidth = (singleton->lastInterruptTime -
                                 singleton->startTime);
				singleton->startTime = 0;
    }
}
