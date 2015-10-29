#include "ShiftFade.h"

#define FADE_SPEED 10

ShiftFade::ShiftFade(){
  lastStep = 0;
  startIdx = 0;
  this -> randomize();
}

void ShiftFade::randomize(){
  for(uint8_t i; i< LED_COUNT; i++){
    hue[i] = random(255) << 8;
    hueSpeed[i] = random(1, 30);
  }

}

void ShiftFade::run(Adafruit_NeoPixel *strip, EffectData data){
  unsigned long currMillis = millis();
  uint16_t step = 0;
  if(currMillis - lastStep > data.tempo){
    startIdx = ++startIdx % LED_COUNT;
  }

  //uint8_t hue8;
  //uint8_t ledIdx;
  //uint32_t color;
  for(uint8_t i=0; i< LED_COUNT; i++){
    hue[i] += hueSpeed[i];
    uint8_t hue8 = hue[i] >> 8;
    uint32_t color = this -> wheel(hue8, data.bandAmp[i]);
    uint8_t ledIdx = (i + startIdx) % LED_COUNT;
    strip -> setPixelColor(ledIdx, color);
  }

}

