#include "Snake.h"

Snake::Snake(){
  this -> randomize();
}

void Snake::randomize(){
  for(uint8_t i=0; i<3; i++){
    pixel[i] = i;
  }
  hueSpeed = random(-30,30);
  hueStep = random(0,20);
}

void Snake::run(Adafruit_NeoPixel *strip, EffectData *data){

  data->hue[0] += hueSpeed;
  uint16_t clr = data->hue[0];
  uint8_t brightness = UINT8_MAX;
  for(uint8_t i=0; i<LED_COUNT; i++){
    data->hue[i] = clr + i*(hueStep << 8);
    uint8_t hue8 = data->hue[i] >> 8;
    uint32_t color = this -> wheel(hue8, brightness);
    brightness -= UINT8_MAX/4;
    uint8_t ledIdx = (i + data->startIdx) % LED_COUNT;
    strip -> setPixelColor(ledIdx, color);
  }
}
