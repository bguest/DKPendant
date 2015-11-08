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
  heldOn = false;
}

void Tempo::init(){

  pinMode(TEMPO_BUTTON, INPUT);

  tempoButton.attach(TEMPO_BUTTON);
  tempoButton.interval(5);
  for(uint8_t idx = 0; idx < TAP_COUNT; idx++){
    tapTimes[idx] = 0;
  }

}

void Tempo::run(){

  tempoButton.update();
  _didUpdate = false;

  unsigned long currMillis = millis();

  if(tempoButton.rose()){
    this -> recordTap();
    _didUpdate = true;
    heldStart = currMillis;
  }

  heldOn = false;

  if(digitalRead(TEMPO_BUTTON) == HIGH){
    if( currMillis - heldStart >= 1000){
      heldOn = true;
      heldStart = currMillis;
    }
  }else{
    heldStart = currMillis;
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
