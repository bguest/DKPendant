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
  effects.setSoundInfo(&sound);

  if(tempoButton.didUpdate()){
    if(tempoButton.isDoubleTap()){
      effects.changeEffect();
      Serial.println("DOUBLE TAP");
    }
    effects.setTempo(tempoButton.tempo());
  }

  effects.run();

}
