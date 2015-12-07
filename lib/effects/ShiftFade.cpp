#include "ShiftFade.h"

ShiftFade::ShiftFade(){
  this -> randomize();
}

void ShiftFade::randomize(){
  for(uint8_t i; i< LED_COUNT; i++){
    hueSpeed[i] = random(-30, 30);
  }
}

void ShiftFade::run(Adafruit_NeoPixel *strip, EffectData *data){

  uint8_t hue8;
  uint8_t ledIdx;
  uint32_t color;
  uint8_t brightness;
  for(uint8_t i=0; i< LED_COUNT; i++){
    data->hue[i] += hueSpeed[i];
    hue8 = data->hue[i] >> 8;
    brightness = data->bandAmp[i];
    color = this -> wheel(hue8, brightness);
    ledIdx = (i + data->startIdx) % LED_COUNT;
    strip -> setPixelColor(ledIdx, color);
  }

}

