#include "Tempo.h"
#include "Arduino.h"

Tempo::Tempo(){
  tapIdx = 0;
  _tempo = 0;
  _shouldUpdate = false;
  _didUpdate = false;
  _isDoubleTap = false;
  heldStart = 0;
  tempoButton = Bounce();
}

void Tempo::init(){

  pinMode(TEMPO_BUTTON,INPUT_PULLUP);

  tempoButton.attach(TEMPO_BUTTON);
  tempoButton.interval(1);
  for(uint8_t idx = 0; idx < TAP_COUNT; idx++){
    tapTimes[idx] = 0;
  }

}

void Tempo::run(){

  tempoButton.update();
  _didUpdate = false;

  if(tempoButton.fell()){
    this -> recordTap();
    _didUpdate = true;
    heldStart = millis();
  }

  heldOn = false;

  if(digitalRead(TEMPO_BUTTON) == LOW){
    if( (millis() - heldStart) > 1000){
      heldOn = true;
      heldStart = millis();
    }
  }else{
    heldOn = false;
    heldStart = millis();
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

bool Tempo::didUpdate(){
  return _didUpdate;
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
