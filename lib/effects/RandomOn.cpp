#include "RandomOn.h"

RandomOn::RandomOn(){
  this -> randomize();
}

void RandomOn::randomize(){
  lastStep = 0;
  activePixel[0] = 0;
  activePixel[1] = 1;
  maxHueStep = random(0xFFFF);
}

void RandomOn::run(Adafruit_NeoPixel *strip, EffectData *data){

  unsigned long currMillis = millis();
  if(currMillis - lastStep > data->tempo){
    lastStep = currMillis;
    this ->updateActive();
    data->hue[activePixel[0]] += random(maxHueStep);
  }
  this-> off(strip);

  for(uint8_t i=0; i<2; i++){
    uint8_t hue8 = data->hue[activePixel[i]] >> 8;
    uint8_t brightness;
    if(i == 0){
       brightness = 255*(currMillis - lastStep)/data->tempo;
    }else{
       brightness = 255 - 255*(currMillis - lastStep)/data->tempo;
    }
    uint32_t color = this -> wheel(hue8, brightness);
    strip -> setPixelColor(activePixel[i], color);
  }
}

void RandomOn::updateActive(){
  activePixel[1] = activePixel[0];
  uint8_t sample[3];
  uint8_t i = 0;
  for(uint8_t j=0; j<LED_COUNT; j++){
    if(j != activePixel[1]){
      sample[i] = j;
      i++;
    }
  }
  activePixel[0] = sample[random(3)];
}
