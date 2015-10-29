#include "Pendant.h"

#define PENDANT_ID 0xFF01

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
      sound.reset();
      effects.changeEffect();
    }
    effects.setTempo(tempoButton.tempo());
  }
  if(tempoButton.heldOn){
    uint32_t send = (PENDANT_ID << 16);
    send |= (uint32_t)tempoButton.tempo();
    irSend.sendSAMSUNG(send, 32);
  }

  effects.run();
}
