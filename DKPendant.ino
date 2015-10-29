#include <Bounce2.h>
#include <Pendant.h>
#include <Adafruit_NeoPixel.h>

#ifdef __AVR__
  #include <avr/power.h>
#endif

#ifndef __AVR_ATtiny85__
  #define DEBUG
#endif

Pendant pendant;

void setup(){
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 8000000) clock_prescale_set(clock_div_1);
  #endif

  #ifdef DEBUG
  Serial.begin(9600);
  #endif

  pendant.init();
}

void loop(){
  pendant.run();
}
