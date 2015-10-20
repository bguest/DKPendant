#include "Pendant.h"

Pendant::Pendant(){
};

void Pendant::init(){
  tempoButton.init();
  effects.init();
  sound.init();
  irSend.init();
}

void Pendant::run(){

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
