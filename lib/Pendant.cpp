#include "Pendant.h"

Pendant::Pendant(){
};

void Pendant::init(){

  power.init();
  tempoButton.init();
  effects.init();
  sound.init();
}

void Pendant::run(){

  power.run();
  tempoButton.run();
  sound.run();
  effects.setSoundInfo(&sound);

  if(tempoButton.didUpdate()){
    if(tempoButton.isDoubleTap()){
      effects.changeEffect();
    }
    effects.setTempo(tempoButton.tempo());
  }
  if(tempoButton.heldOn){
    irSend.sendSAMSUNG(0xBCDEF012, 32);
  }

  effects.run();
}
