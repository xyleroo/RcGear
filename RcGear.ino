/**
 * Simple RC Gear Controller.
 * Author: Heinz Bruederlin
 * Date: 01/2018
 * 
 * Arduino Pro Mini ATmega328P 3.3V 8Mhz
 * Two Channel H Bridge MX1508
 * 
 * Pin Raw 5V
 * Pin Gnd Gnd
 * Pin 2 (PD2 INT8) rx input impluse
 * 
 * Pin 3 (PD3)      left gear limit switch (white)    
 * Pin 4 (PD4)      left gear limit switch (black) 
 * Pin 5 (PD5)      right gear limit switch (white)
 * Pin 6 (PD6)      right gear limit switch (black)
 * 
 * Pin 8 (PB0)      left motor ina2
 * Pin 9 (PB1)      left motor ina1
 * 
 * Pin 10 (PB2)      right motor inb2
 * Pin 11 (PB3)      right motor inb1
 */
 #include <Arduino.h>
 #include "Led.h"
 #include "RcRx.h"
 #include "Ctrl.h"

#define LED_PIN         13 /* Pin PB5 */
#define RX_PIN           2 /* Pin PD2 */

#define LEFT_LIMIT_OUT   3 /* Pin PD3 */
#define LEFT_LIMIT_IN    4 /* Pin PD4 */
#define RIGHT_LIMIT_OUT  5 /* Pin PD5 */
#define RIGHT_LIMIT_IN   6 /* Pin PD6 */

#define LEFT_MOTOR_1     9 /* Pin PB1*/
#define LEFT_MOTOR_2     8 /* Pin PB0*/
#define RIGHT_MOTOR_1   11 /* Pin PB3*/
#define RIGHT_MOTOR_2   10 /* Pin PB2*/

#define RX_CENTER 1500
#define RX_RANGE   200

//#define DEBUG

static Led  led(LED_PIN);
static RcRx rx(RX_PIN);
static Ctrl left( LEFT_LIMIT_IN,  LEFT_LIMIT_OUT,
                  LEFT_MOTOR_1,   LEFT_MOTOR_2, false);
static Ctrl right(RIGHT_LIMIT_IN, RIGHT_LIMIT_OUT,
                  RIGHT_MOTOR_1,  RIGHT_MOTOR_2, true);

void setup() {
    led.init();
    rx.init();
    left.init();
    right.init();
#ifdef DEBUG
    Serial.begin(19200);
#endif
}

void loop () {
    unsigned int v = rx.value();
    enum Dir {Up, Stop, Down} dir;
    if (v  > RX_CENTER+RX_RANGE) {
        dir = Up;
    } else if (v < RX_CENTER-RX_RANGE) {
        dir = Down;
    } else {
        dir = Stop;
    }
#ifdef DEBUG
    Serial.print(v); Serial.print(" "); Serial.println(dir);
#endif
    switch (dir) {
        case Up:
            left.up();
            right.up();
            led.update(Led::Middle);
            break;
        case Down:
            left.down();
            right.down();
            led.update(Led::Fast);
            break;
        case Stop:
            left.stop();
            right.stop();
            led.update(Led::Slow);
            break;
    }
    delay(100);
}
