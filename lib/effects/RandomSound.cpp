#include "RandomSound.h"

RandomSound::RandomSound(){
  this -> randomize();
  lastStep = 0;
}

void RandomSound::randomize(){
  onPixel = random(4);
  hueStep = random(0xFF);
  for(uint8_t i=0; i< LED_COUNT; i++){
    brightness[i] = random(0xFFFF);
  }
}

void RandomSound::run(Adafruit_NeoPixel *strip, EffectData *data){

  unsigned long currMillis = millis();
  if( data->volume  >= 0.7*data->maxVolume ){
  //if( currMillis - lastStep > data->tempo ){
    this->updatePixels();
    lastStep = currMillis;
  }
  this-> off(strip);
  data->hue[onPixel] += data->volume*4;

  for(uint8_t i=0; i<LED_COUNT; i++){
    uint8_t hue8 = data->hue[i] >> 8;
    uint16_t delta = 0xFFFF/max(data->tempo, 150);
    if(i == onPixel){
      if(delta < 0xFFFF - brightness[i]){
        brightness[i] += delta;
      }else{
        brightness[i] = 0xFFFF;
      }
    }else{
      if(delta/2 < brightness[i]){
        brightness[i] -= 0.4*delta;
      }else{
        brightness[i] = 0x0000;
      }
    }
    uint32_t color = this -> wheel(hue8, brightness[i] >> 8);
    strip -> setPixelColor(i, color);
  }
}

void RandomSound::updatePixels(){
  onPixel = random(4);
}
