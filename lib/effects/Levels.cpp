#include "Levels.h"

Levels::Levels(){
}

void Levels::run(Adafruit_NeoPixel *strip, EffectData data){
  uint8_t green = 0;
  int8_t red = 128;

  uint16_t x;
  uint8_t hue;

  for(uint8_t i = 0; i < LED_COUNT; i++){
    x = (255*data.bandAmp[i])/data.maxBandAmp[i];
    //hue = green - (green - red)*x/225 - 10;
    hue = x;
    uint32_t color = this -> wheel(hue);
    strip -> setPixelColor(i, color);
  }
}

