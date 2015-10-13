#include "Effects.h"
#include "effects/Effect.cpp"
#include "effects/Spin.cpp"
#include "effects/Levels.cpp"

Effects::Effects(){
  currEffect = &spin;
  cEffect = SPIN;
}

void Effects::init(){
  leds.init();
}

void Effects::run(){
  currEffect -> run(&leds, data);
  leds.run();
}

void Effects::setSoundInfo(Sound *sound){
  data.volume = sound -> volume;
  data.maxVolume = sound -> maxVolume;
  for(uint8_t i = 0; i < 4; i++){
    data.maxBandAmp[i] = sound -> maxBandAmp[i];
    data.bandAmp[i] = sound -> bandAmp[i];
  }
}

void Effects::setTempo(uint16_t aTempo){
  data.tempo = aTempo;
}

void Effects::changeEffect(){
  cEffect++;
  cEffect = cEffect % EFFECT_COUNT;

  switch(cEffect){
    case SPIN: currEffect = &spin; break;
    case LEVELS: currEffect = &levels; break;
  }

}
