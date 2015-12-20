#include "Levels.h"

Levels::Levels(){
  this -> randomize();
}

void Levels::randomize(){
  for(uint8_t i; i< LED_COUNT; i++){
    hueSpeed[i] = random(-30, 30);
  }
}

void Levels::run(Adafruit_NeoPixel *strip, EffectData *data){

  uint8_t hue;

  for(uint8_t i = 0; i < LED_COUNT; i++){
    data->hue[i] += hueSpeed[i];
    hue = data->bandAmp[i] + (data->hue[i]>>8);

    uint32_t color = this -> wheel(hue, hue);
    strip -> setPixelColor(i, color);
  }
}

