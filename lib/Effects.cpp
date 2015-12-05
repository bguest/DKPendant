#include "Effects.h"
#include "effects/Effect.cpp"
#include "effects/Spin.cpp"
#include "effects/Levels.cpp"
#include "effects/ShiftFade.cpp"

Effects::Effects(){
  //currEffect = &levels;
  //cEffect = LEVELS;
  currEffect = &spin;
  cEffect = SPIN;
  lastRun = 0;
}

void Effects::init(){
  strip = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
  strip.begin();
  strip.show();
}

void Effects::randomize(){
  for(uint8_t i; i<LED_COUNT; i++){
    data.hue[i] = random(255) << 8;
  }
  currEffect -> randomize();
}

void Effects::run(){
  unsigned long currMillis = millis();
  if(currMillis - lastRun > UPDATE_DURRATION){
    lastRun = currMillis;
    currEffect -> run(&strip, &data);
    strip.show();
  }
}

void Effects::setSoundInfo(Sound *sound){
  data.volume = sound -> volume();
  for(uint8_t i = 0; i < 4; i++){
    data.bandAmp[i] = sound -> bandAmp(i);
  }
}

void Effects::setTempo(uint16_t aTempo){
  data.tempo = aTempo;
}

void Effects::setHueAll(uint8_t hue){
  for(uint8_t i=0; i<LED_COUNT; i++){
    data.hue[i] = hue << 8;
  }
}

uint8_t Effects::getEffect(){
  return cEffect;
}

void Effects::setEffect(uint8_t kEffect){
  cEffect = kEffect;
  switch(cEffect){
    case SPIN: currEffect = &spin; break;
    case LEVELS: currEffect = &levels; break;
    case SHIFT_FADE: currEffect = &shiftFade; break;
  }
  currEffect -> randomize();
}

void Effects::changeEffect(){
  cEffect++;
  cEffect = cEffect % EFFECT_COUNT;
  this -> setEffect(cEffect);
}

void Effects::off(){
  currEffect -> off(&strip);
  strip.show();
}
