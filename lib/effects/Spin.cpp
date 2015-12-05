#include "Spin.h"

Spin::Spin(){
}

void Spin::run(Adafruit_NeoPixel *strip, EffectData *data){
  this -> off(strip);

  uint8_t idx = (millis() / data -> tempo) % LED_COUNT;
  uint8_t red = (0xFF*data -> volume) >> 8;

  uint8_t dx = (idx) % LED_COUNT;
  strip -> setPixelColor(dx, red, 0, 0 );

  red /= 2;
  dx = (idx + 1) % LED_COUNT;
  strip -> setPixelColor(dx, 0, red, 0);

  dx = (idx + 2) % LED_COUNT;
  strip -> setPixelColor(dx, 0, 0, red);
}

