#include "Pendant.h"

Pendant::Pendant(){
};

void Pendant::init(){
  tempoButton.init();
  effects.init();
}

void Pendant::run(){
  tempoButton.run();

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
