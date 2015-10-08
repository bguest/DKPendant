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
  EffectData data;
  data.tempo = _tempo;

  currEffect -> run(&leds, data);
  leds.run();
}


void Effects::setTempo(uint16_t aTempo){
  _tempo = aTempo;
}
