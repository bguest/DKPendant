#include "Snake.h"

Snake::Snake(){
  lastStep = 0;
  this -> randomize();
}

void Snake::randomize(){
  for(uint8_t i=0; i<3; i++){
    pixel[i] = i;
  }
  hueSpeed = random(-30,30);
}

void Snake::run(Adafruit_NeoPixel *strip, EffectData *data){

  unsigned long currMillis = millis();
  if(currMillis - lastStep > data->tempo){
    lastStep = currMillis;
    this ->updatePixels();
    uint8_t p = pixel[0];
    data->hue[p] = data->hue[pixel[1]]/2 + data->hue[p]/ + 0xFF;
  }
  this-> off(strip);

  for(uint8_t i=0; i<3; i++){
    uint8_t hue8 = data->hue[pixel[i]] >> 8;
    uint8_t brightness;
    switch(i){
      case 0:
        brightness = 127 - 127*(currMillis - lastStep)/data->tempo;
        break;
      case 1:
        brightness = 255 - 127*(currMillis - lastStep)/data->tempo;
        break;
      case 2:
        brightness = 255*(currMillis - lastStep)/data->tempo;
        break;
    }
    uint32_t color = this -> wheel(hue8, brightness);
    strip -> setPixelColor(pixel[i], color);
  }
}

void Snake::updatePixels(){
  for(uint8_t i=0; i<3; i++){
    pixel[i]++;
    pixel[i] = pixel[i] % LED_COUNT;
  }
}
