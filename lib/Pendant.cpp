#include "Pendant.h"

Pendant::Pendant(){
};

void Pendant::init(){
  tempoButton.init();
}

void Pendant::run(){
  tempoButton.run();
  bool isDouble = tempoButton.isDoubleTap();
  if(isDouble){
    Serial.println("DOUBLE TAP");
  }
}
