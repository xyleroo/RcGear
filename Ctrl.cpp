/**
 * Simple Arduino Led Controller
 * Author: Heinz Bruederlin
 * Date: 01/2018
 */
#include "Ctrl.h"

Ctrl::Ctrl(int _limit_in,  int _limit_out, int _motor_1, int _motor_2,
           bool invert) {
    limit_in   = _limit_in;
    limit_out  = _limit_out;
    if (invert) {
        motor_1 = _motor_2;
        motor_2 = _motor_1;
    } else {
        motor_1 = _motor_1;
        motor_2 = _motor_2;
    }
}

void Ctrl::init(void) {
    pinMode(limit_in,   INPUT_PULLUP);
    pinMode(limit_out,  INPUT_PULLUP);
    pinMode(motor_1, OUTPUT);
    pinMode(motor_2, OUTPUT);
    motorStop();
    state = Stop;
}

void Ctrl::motorStop() {
    digitalWrite(motor_1, LOW);    
    digitalWrite(motor_2, LOW);    
}

void Ctrl::motorIn() {
    digitalWrite(motor_1, HIGH);    
    digitalWrite(motor_2, LOW);    
}

void Ctrl::motorOut() {
    digitalWrite(motor_1, LOW);    
    digitalWrite(motor_2, HIGH);    
}

void Ctrl::up(void) {
    if (digitalRead(limit_in)) {
        if (state != Stop) {
            motorStop();
            state = Stop;
        }
    } else if (state != Up) {
        motorIn();
        state = Up;
    }
}

void Ctrl::down(void) {
    if (digitalRead(limit_out)) {
        if (state != Stop) {
            motorStop();
            state = Stop;
        }
    } else if (state != Down) {
        motorOut();
        state = Down;
    }
}

void Ctrl::stop(void) {
    motorStop();
    state = Stop;
}

