/**
 * Simple Arduino RC Receiver for one Channel
 * Author: Heinz Bruederlin
 * Date: 01/2018
 */

#ifndef RCRX_H
#define RCRX_H

#include <Arduino.h>

class RcRx {
  public:
    RcRx(int portNo);
    void init(void);
    unsigned int value(void);
  private:
    int portNo;
    unsigned int pulseWidth;
    volatile unsigned long startTime;
    volatile unsigned long lastInterruptTime;
    static RcRx* singleton;
    static void calcSignal(void);
};
 
#endif
