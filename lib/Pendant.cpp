#include "Pendant.h"

Pendant::Pendant(){
};

void Pendant::init(){
  tempoButton.init();
  effects.init();
  sound.init();
}

void Pendant::run(){
  tempoButton.run();
  sound.run();
  effects.setVolume(sound.volume, sound.maxVol);

  if(tempoButton.didUpdate()){
    bool isDouble = tempoButton.isDoubleTap();
    if(isDouble){
#ifdef DEBUG
      Serial.println("DOUBLE TAP");
#endif
    }
    effects.setTempo(tempoButton.tempo());
  }

  effects.run();

}
