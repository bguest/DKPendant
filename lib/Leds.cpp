#include "Leds.h"

Leds::Leds(){
  strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
}

void Leds::init(){
  strip.begin();
  strip.show();
}

void Leds::run(){
  for(uint8_t i=0; i < LED_COUNT; i++){
    strip.setPixelColor(i, pixels[i].getColor());
  }
  strip.show();
}
Pixel* Leds::pixelAtIndex(uint8_t idx){
  return &(pixels[idx]);
}
void Leds::colorAtIndex(uint32_t clr, uint8_t idx){
  pixels[idx].setColor(clr);
}

uint32_t Leds::colorAtIndex(uint8_t idx){
  pixels[idx].getColor();
}

void Leds::off(){ //Turn LEDs all off
  for(uint8_t i=0; i < LED_COUNT; i++){
    pixels[i].setColor( 0x0 );
  }

}
