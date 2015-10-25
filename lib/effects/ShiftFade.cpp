#include "ShiftFade.h"

#define FADE_SPEED 10
const uint8_t STEP_SIZE = UINT8_MAX/4;

ShiftFade::ShiftFade(){
  lastStep = 0;
  startIdx = 0;
  for(uint8_t i; i < LED_COUNT; i++){
    hue[i] = (0 + STEP_SIZE*i) << 8;
  }
}

void ShiftFade::run(Adafruit_NeoPixel *strip, EffectData data){
  unsigned long currMillis = millis();
  uint16_t step = 0;
  if(currMillis - lastStep > data.tempo){
    startIdx = ++startIdx % LED_COUNT;
    step = STEP_SIZE << 8;
    lastStep = currMillis;
  }

  uint8_t hue8;
  uint8_t ampIdx;
  for(uint8_t i=0; i< LED_COUNT; i++){
    ampIdx = (i + startIdx) % LED_COUNT;
    hue[i] += FADE_SPEED + step;
    hue8 = hue[i] >> 8;
    uint32_t color = this -> wheel(hue8, data.bandAmp[ampIdx]);
    strip -> setPixelColor(i, color);
  }

}

