#include "Levels.h"

Levels::Levels(){
}

void Levels::run(Adafruit_NeoPixel *strip, EffectData data){

  uint8_t hue;

  for(uint8_t i = 0; i < LED_COUNT; i++){
    hue = data.bandAmp[i];
    uint32_t color = this -> wheel(hue, UINT8_MAX);
    strip -> setPixelColor(i, color);
  }
}

