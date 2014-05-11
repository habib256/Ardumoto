/*
 * Ardumoto.h - Improved Ardumoto library for Arduino
 *
 * Copyright 2008-2014
 * David A. Mellis
 * Pete Dokter
 * Timothy Holmberg
 * Tom Igoe
 * Arnaud Verhille from http://www.gistlabs.net
 * for this simple to use library for Ardumoto
 *
 * Based on the following resources:
 *   https://www.sparkfun.com/products/9815
 *  Pete Dokter's code for Arduino shows very basically how to control an Ardumoto motor driver shield with a 5V Arduino controller board.
 *   http://www.sparkfun.com/datasheets/DevTools/Arduino/Ardumoto_test_3.pde
 *  Timothy Holmberg from SparkFun Electronics code
 *   http://dlnmh9ip6v2uc.cloudfront.net/downloads/Ardumoto/ardumoto_example.ino
 *  This also includes parts of the Fading Example,  Created 1 Nov 2008 By David A. Mellis, modified 30 Aug 2011 By Tom Igoe
 *   http://arduino.cc/en/Tutorial/Fading
 */

#ifndef Ardumoto_H
#define Ardumoto_H

#include <Arduino.h>

#define PWM_A 3  //PWM control for motor outputs 1 and 2 is on digital pin 3
#define PWM_B 11  //PWM control for motor outputs 3 and 4 is on digital pin 11
#define DIR_A 12  //direction control for motor outputs 1 and 2 is on digital pin 12
#define DIR_B 13  //direction control for motor outputs 3 and 4 is on digital pin 13

class Ardumoto
{
  public:
    void init();
    /* Let's take a moment to talk about these functions. The forw and back functions are simply designating the direction the motors will turn once they are fed a PWM signal.
    If you only call the forw, or back functions, you will not see the motors turn. On a similar note the fade in and out functions will only change PWM, so you need to consider
    the direction you were last set to. In the code above, you might have noticed that I called forw and fade in the same grouping. You will want to call a new direction, and then
    declare your pwm fade. There is also a stop function.
    */
    void forw();    // no pwm defined
    void back();    // no pwm defined
    void forward(); //full speed forward
    void backward();//full speed backward
    void stopped(); //stop
    void astop();   //stop motor A
    void bstop();   //stop motor B
    void fadein();
    void fadeout();


  private:
    int val;     //value for fade
};

#endif
