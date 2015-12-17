#include "Effects.h"
#include "effects/Effect.cpp"
#include "effects/Spin.cpp"
#include "effects/Levels.cpp"
#include "effects/ShiftFade.cpp"
#include "effects/Snake.cpp"
#include "effects/RandomOn.cpp"
#include "effects/RandomSound.cpp"

Effects::Effects(){
  //currEffect = &levels;
  //cEffect = LEVELS;
  //currEffect = &spin;
  //cEffect = SPIN;
  //currEffect = &snake;
  //cEffect = SNAKE;
  //currEffect = &randomOn;
  //cEffect = RANDOM_ON;
  currEffect = &randomSound;
  cEffect = RANDOM_SOUND;
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
  data.startIdx = 0;
  data.tempo = 240;
  currEffect -> randomize();
}

void Effects::run(){
  unsigned long currMillis = millis();
  if(currMillis - lastRun > UPDATE_DURRATION){
    lastRun = currMillis;
    this -> updateStartIdx();
    currEffect -> run(&strip, &data);
    strip.show();
  }
}
void Effects::updateStartIdx(){
  unsigned long currMillis = millis();
  if(currMillis - lastStep > data.tempo){
    data.startIdx = ++startIdx % LED_COUNT;
    lastStep = currMillis;
  }
}

void Effects::setSoundInfo(Sound *sound){
  data.volume = data.volume/2 + sound->volume()/2;
  for(uint8_t i = 0; i < 4; i++){
    data.bandAmp[i] = data.bandAmp[i]/2 + sound->bandAmp(i)/2;
  }
  data.maxVolume = sound->maxVolume;
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
    case SNAKE: currEffect = &snake; break;
    case RANDOM_ON: currEffect = &randomOn; break;
    case RANDOM_SOUND: currEffect = &randomSound; break;
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
