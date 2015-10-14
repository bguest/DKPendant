#include "Levels.h"
#include "Pixel.h"

Levels::Levels(){
}

void Levels::run(Leds *leds, EffectData data){
  uint8_t green = 128;
  int8_t red = -10;

  uint8_t x;
  uint8_t hue;

  for(uint8_t i = 0; i < 4; i++){
    x = (255*data.bandAmp[i])/data.maxBandAmp[i];
    hue = green - (green - red)*x/255;
    leds -> colorAtIndex( CHSV(hue, 255, 100), i);
  }
}

