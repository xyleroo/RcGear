/**
 * Simple Arduino Led Controller
 * Author: Heinz Bruederlin
 * Date: 01/2018
 */

#ifndef CTRL_H
#define CTRL_H

#include <Arduino.h>

class Ctrl {
  public:
    Ctrl(int limit_in,  int limit_out, int motor_1, int motor_2,
         bool invert);
    void init(void);
    void up(void);
    void down(void);
    void stop(void);
    int getState(void) {return state;}
  private:
    void motorStop(void);
    void motorIn(void);
    void motorOut(void);

    enum State {In=-2, Up=-1, Stop=0, Down=1, Out=2} state;
    int limit_in;
    int limit_out;
    int motor_1;
    int motor_2;
};
 
#endif
