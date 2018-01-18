/**
 * Simple Arduino Led Controller
 * Author: Heinz Bruederlin
 * Date: 01/2018
 */

#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
  public:
    enum Mode {Slow=3, Middle=2, Fast=1};
    Led(int portNo);
    void init(void);
    void update(enum Mode mode);
  private:
    int portNo;
    int state;
    unsigned long nextTime;
};
 
#endif
