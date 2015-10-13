#include "Effects.h"
#include "effects/Effect.cpp"
#include "effects/Spin.cpp"

Effects::Effects(){
  currEffect = &spin;
  cEffect = SPIN;
}

void Effects::init(){
  leds.init();
}

void Effects::run(){
  Serial.print(data.maxVolume);
  currEffect -> run(&leds, data);
  leds.run();
}

void Effects::setVolume(uint16_t volume, uint16_t maxVolume){
  data.volume = volume;
  data.maxVolume = maxVolume;
}

void Effects::setTempo(uint16_t aTempo){
  data.tempo = aTempo;
}
