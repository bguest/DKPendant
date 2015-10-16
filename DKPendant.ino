#include <Bounce2.h>
#include <Pendant.h>
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define __AVR_ATtiny85__
#ifndef __AVR_ATtiny85__
  #define DEBUG
#endif

Pendant pendant;
/*Adafruit_NeoPixel striper = Adafruit_NeoPixel(4, 3, NEO_GRB + NEO_KHZ800);*/

void setup(){
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 8000000) clock_prescale_set(clock_div_1);
  #endif

  #ifdef DEBUG
  Serial.begin(9600);
  #endif

  pendant.init();

  /*striper.begin();*/
  /*striper.show();*/
}

void loop(){
  pendant.run();
  /*striper.setPixelColor(1, striper.Color(255, 0, 255));*/
  /*striper.show();*/
}
