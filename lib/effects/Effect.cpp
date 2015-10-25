#include "Effect.h"

Effect::Effect(){
}

void Effect::run(Adafruit_NeoPixel *strip, EffectData data){
}

void Effect::randomize(){
}

void Effect::off(Adafruit_NeoPixel *strip){
  for(uint8_t i = 0; i < LED_COUNT; i++){
    strip -> setPixelColor(i, 0);
  }
}
// Input a value 0 to 255 to get a color value.
// The colors are a transition r - g - b - back to r.
uint32_t Color(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

uint32_t Effect::wheel(uint8_t WheelPos, uint8_t brightness) {
  uint16_t b = (uint16_t)brightness;
  if(WheelPos < 85) {
    return Color( WheelPos*3*b/255, (255 - WheelPos*3)*b/255, 0);
  }
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return Color((255 - WheelPos*3)*b/255, 0, WheelPos*3*b/255);
  }
  else {
    WheelPos -= 170;
    return Color(0, WheelPos*3*b/255, (255 - WheelPos*3)*b/255);
  }
}


