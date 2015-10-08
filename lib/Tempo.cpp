#include "Tempo.h"
#include "Arduino.h"
#include "Pendant.h"

Tempo::Tempo(){
  tapIdx = 0;
  _tempo = 0;
  _shouldUpdate = false;
  _isDoubleTap = false;
  tempoButton = Bounce();
}

void Tempo::init(){

  pinMode(TEMPO_BUTTON,INPUT_PULLUP);

  tempoButton.attach(TEMPO_BUTTON);
  tempoButton.interval(5);
  for(uint8_t idx = 0; idx < TAP_COUNT; idx++){
    tapTimes[idx] = 0;
  }

}

void Tempo::run(){

  tempoButton.update();

  if(tempoButton.fell()){
    this -> recordTap();
  }
}

uint16_t Tempo::tempo(){
  if(_shouldUpdate){
    this -> runCalc();
  }
  return _tempo;
}

bool Tempo::isDoubleTap(){
  if(_shouldUpdate){
    this -> runCalc();
  }
  bool rtn = _isDoubleTap;
  _isDoubleTap = false;
  return rtn;
}

void Tempo::runCalc(){

  uint8_t beats = 0;
  uint16_t durration = 0;
  _isDoubleTap = false;

  for(uint8_t idx = 1; idx < TAP_COUNT; idx++){
    int16_t diff = tapTimes[idx] - tapTimes[idx - 1];

    if(diff > DOUBLE_TAP_PERIOD && diff < MAXIMUM_PERIOD){
      beats++;
      durration += diff;
    }else if(diff > 0 && diff < DOUBLE_TAP_PERIOD){
      _isDoubleTap = true;
      tapTimes[idx] = tapTimes[idx-1];
    }
  }
  if(beats > 0){
    Serial.println(_tempo);
    _shouldUpdate = false;
    _tempo = durration/beats;
  }
}

void Tempo::recordTap(){
  uint8_t idx = tapIdx % TAP_COUNT;

  tapTimes[idx] = millis();
  _shouldUpdate = true;
  _isDoubleTap = false;

  tapIdx++;
}
