#include "Tempo.h"
#include "Arduino.h"
#include "Pendant.h"

Tempo::Tempo(){
  tapIdx = 0;
  _tempo = 0;
  tempoButton = Bounce();
}

void Tempo::init(){

  pinMode(TEMPO_BUTTON, OUTPUT);
  tempoButton.attach(TEMPO_BUTTON);
  tempoButton.interval(5);

}

void Tempo::run(){

  if(tempoButton.rose()){
    this -> recordTap();
  }

}

uint16_t Tempo::tempo(){
  if(_tempo > 0){
    return _tempo;
  }

  //Calculate Tempo
  uint8_t beats = 0;
  uint16_t durration = 0;
  for(uint8_t idx = 1; idx < TAP_COUNT; idx++){
    uint16_t diff = tapTimes[idx] - tapTimes[idx - 1];
    if(diff > 0 && diff < MAXIMUM_PERIOD){
      beats++;
      durration += diff;
    }
  }
  _tempo = durration/beats;
  return _tempo;
}

void Tempo::recordTap(){
  uint8_t idx = tapIdx % TAP_COUNT;

  tapTimes[idx] = millis();
  _tempo = 0;

  tapIdx++;
}
