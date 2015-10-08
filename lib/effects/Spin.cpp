#include "Spin.h"
#include "Pixel.h"

Spin::Spin(){
}

void Spin::run(Leds *leds, EffectData data){
  leds -> off();
  uint8_t idx = (millis() / data.tempo) % LED_COUNT;

  leds -> colorAtIndex( CHSV( 0, 255, 255), idx);

  uint8_t dx = (idx + 1) % LED_COUNT;
  leds -> colorAtIndex( CHSV( 0, 255, 100), dx);

  dx = (idx - 1) % LED_COUNT;
  leds -> colorAtIndex( CHSV( 0, 255, 100), dx);

  //idx = idx + 1 % LED_COUNT;
  //pixel = &(leds -> pixels[idx]);
  //pixel -> setColor( CHSV(0,0,128) );
}

