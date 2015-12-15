#include "RandomSound.h"

RandomSound::RandomSound(){
  this -> randomize();
  lastStep = 0;
}

void RandomSound::randomize(){
  onPixel = random(4);
  maxHueStep = random(0x0FFF);
  for(uint8_t i=0; i< LED_COUNT; i++){
    brightness[i] = random(0xFFFF);
  }
}

void RandomSound::run(Adafruit_NeoPixel *strip, EffectData *data){

  unsigned long currMillis = millis();
  if( data->volume  >= data->maxVolume ){
  //if( currMillis - lastStep > data->tempo ){
    this->updatePixels();
    data->hue[onPixel] += random(maxHueStep);
  }
  this-> off(strip);

  uint16_t diff = currMillis - lastStep;
  lastStep = currMillis;

  for(uint8_t i=0; i<LED_COUNT; i++){
    uint8_t hue8 = data->hue[i] >> 8;
    uint16_t delta = 0xFFFF*diff/data->tempo;
    if(i == onPixel){
      if(delta < 0xFFFF - brightness[i]){
        brightness[i] += delta;
      }else{
        brightness[i] = 0xFFFF;
      }
    }else{
      if(delta < brightness[i]){
        brightness[i] -= delta;
      }else{
        brightness[i] = 0x0000;
      }
    }
    uint32_t color = this -> wheel(hue8, brightness[i]);
    strip -> setPixelColor(i, color);
  }
}

void RandomSound::updatePixels(){
  onPixel = random(4);
}
