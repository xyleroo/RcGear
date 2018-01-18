/**
 * Simple Arduino Led Controller
 * Author: Heinz Bruederlin
 * Date: 01/2018
 */
#include "Led.h"

Led::Led(int _portNo) {
    portNo = _portNo;
}

void Led::init(void) {
    nextTime = 0;
    state = LOW;
    pinMode(portNo, OUTPUT);
    digitalWrite(portNo, state);
}

void Led::update(enum Mode mode) {
    unsigned long t = micros();
    if (t > nextTime) {
        nextTime = t + 500000 * mode;	
        state = !state;
        digitalWrite(portNo, state);
    }
}
