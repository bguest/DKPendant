#include "ShiftFade.h"

#define FADE_SPEED 10

ShiftFade::ShiftFade(){
  lastStep = 0;
  startIdx = 0;
  this -> randomize();
}

void ShiftFade::randomize(){
  for(uint8_t i; i< LED_COUNT; i++){
    hueSpeed[i] = random(1, 30);
  }

}

void ShiftFade::run(Adafruit_NeoPixel *strip, EffectData *data){
  unsigned long currMillis = millis();
  uint16_t step = 0;
  if(currMillis - lastStep > data -> tempo){
    startIdx = ++startIdx % LED_COUNT;
    lastStep = currMillis;
  }

  uint8_t hue8;
  uint8_t ledIdx;
  uint32_t color;
  uint8_t brightness;
  for(uint8_t i=0; i< LED_COUNT; i++){
    data -> hue[i] += hueSpeed[i];
    hue8 = data -> hue[i] >> 8;
    brightness = data -> bandAmp[i];
    color = this -> wheel(hue8, brightness);
    ledIdx = (i + startIdx) % LED_COUNT;
    strip -> setPixelColor(ledIdx, color);
  }

}

