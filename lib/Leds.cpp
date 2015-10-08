#include "Leds.h"
#include "Pendant.h"

Leds::Leds(){

}

void Leds::init(){
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);
}

void Leds::run(){
  for(uint8_t i=0; i < LED_COUNT; i++){
    leds[i] = pixels[i].getColor();
  }
  FastLED.show();

}
Pixel* Leds::pixelAtIndex(uint8_t idx){
  return &(pixels[idx]);
}
void Leds::colorAtIndex(CHSV clr, uint8_t idx){
  pixels[idx].setColor(clr);
}

CHSV Leds::colorAtIndex(uint8_t idx){
  pixels[idx].getColor();
}

void Leds::off(){ //Turn LEDs all off
  for(uint8_t i=0; i < LED_COUNT; i++){
    pixels[i].setColor( CHSV(0,0,0) );
  }

}
