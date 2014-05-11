/*
 * Ardumoto.cpp - Improved Ardumoto library for Arduino
 *
 * Copyright 2008-2014
 * David A. Mellis
 * Pete Dokter
 * Arnaud Verhille
 */
 
 #include <Ardumoto.h>

Ardumoto moteurs = Ardumoto();
void setup()
{
  moteurs.init();
}

void loop()
{ 
   
  moteurs.forw();         //Set Motors to go forward Note : No pwm is defined with the for function, so that fade in and out works
  //moteurs.fadein();       //fade in from 0-255
  //delay(1000);    
  moteurs.forward();      //continue full speed forward
  delay(200);    
 // moteurs.fadeout();      //Fade out from 255-0
  //delay(1000);    //Wait one second
 
  moteurs.stopped();      // stop for 2 seconds
  delay(2000);    

 
  moteurs.back();         //Set motors to revers. Note : No pwm is defined with the back function, so that fade in and out works
 // moteurs.fadein();       //fade in from 0-255 
  //delay(1000);
  moteurs.backward();     //full speed backward
  delay(200);
 // moteurs.fadeout();      //Fade out from 255-0
  //delay(1000);
  
    moteurs.stopped();      // stop for 2 seconds
  delay(2000); 
}

