
#define DEBUG
#include <Bounce2.h>
#include <Pendant.h>
#include <FastLED.h>


Pendant pendant;

void setup(){
  #ifdef DEBUG
  Serial.begin(9600);
  #endif
  pendant.init();
}

void loop(){
  pendant.run();
}
