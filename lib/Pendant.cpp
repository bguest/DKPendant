#include "Pendant.h"

Pendant::Pendant(){
};

void Pendant::init(){
  tempoButton.init();
}

void Pendant::run(){
  tempoButton.run();
  uint16_t tempo = tempoButton.tempo();
  Serial.println(tempo);
}
