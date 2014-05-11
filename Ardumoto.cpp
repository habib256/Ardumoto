/*
 * Ardumoto.cpp - Improved Ardumoto library for Arduino
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

#include <Arduino.h>
#include <Wire.h>
#include "Ardumoto.h"

void Ardumoto::init()
{
    Ardumoto::val = 0;     //value for fade

    pinMode(PWM_A, OUTPUT);  //Set control pins to be outputs
    pinMode(PWM_B, OUTPUT);
    pinMode(DIR_A, OUTPUT);
    pinMode(DIR_B, OUTPUT);

    analogWrite(PWM_A, 0);  //set both motors to stop
    analogWrite(PWM_B, 0);
}


void Ardumoto::forw() // no pwm defined
{
    digitalWrite(DIR_A, HIGH);  //Reverse motor direction, 1 high, 2 low
    digitalWrite(DIR_B, HIGH);  //Reverse motor direction, 3 low, 4 high
}

void Ardumoto::back() // no pwm defined
{
    digitalWrite(DIR_A, LOW);  //Set motor direction, 1 low, 2 high
    digitalWrite(DIR_B, LOW);  //Set motor direction, 3 high, 4 low
}

void Ardumoto::forward() //full speed forward
{
    digitalWrite(DIR_A, HIGH);  //Reverse motor direction, 1 high, 2 low
    digitalWrite(DIR_B, HIGH);  //Reverse motor direction, 3 low, 4 high
    analogWrite(PWM_A, 100);    //set both motors to run at (100/255 = 31)% duty cycle
    analogWrite(PWM_B, 100);
}

void Ardumoto::backward() //full speed backward
{
    digitalWrite(DIR_A, LOW);  //Set motor direction, 1 low, 2 high
    digitalWrite(DIR_B, LOW);  //Set motor direction, 3 high, 4 low
    analogWrite(PWM_A, 100);   //set both motors to run at (100/255 = 31)% duty cycle
    analogWrite(PWM_B, 100);
}
void Ardumoto::stopped() //stop
{
    digitalWrite(DIR_A, LOW); //Set motor direction, 1 low, 2 high
    digitalWrite(DIR_B, LOW); //Set motor direction, 3 high, 4 low
    analogWrite(PWM_A, 0);    //set both motors to stop
    analogWrite(PWM_B, 0);
}

void Ardumoto::fadein()
{
    // fade in from min to max in increments of 5 points:
    for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5)
    {
        // sets the value (range from 0 to 255):
        analogWrite(PWM_A, fadeValue);
        analogWrite(PWM_B, fadeValue);
        // wait for 30 milliseconds to see the dimming effect
        delay(30);
    }
}

void Ardumoto::fadeout()
{
    // fade out from max to min in increments of 5 points:
    for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5)
    {
        // sets the value (range from 0 to 255):
        analogWrite(PWM_A, fadeValue);
        analogWrite(PWM_B, fadeValue);
        // wait for 30 milliseconds to see the dimming effect
        delay(30);
    }
}

void Ardumoto::astop()                   //stop motor A
{
    analogWrite(PWM_A, 0);    //set both motors to run at 100% duty cycle (fast)
}

void Ardumoto::bstop()                   //stop motor B
{
    analogWrite(PWM_B, 0);    //set both motors to run at 100% duty cycle (fast)
}

