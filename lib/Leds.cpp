
#include "Leds.h"
#include "Pendant.h"

Leds::Leds(){

}

void Leds::init(){
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);
}

void Leds::run(){
  FastLED.show();

}

