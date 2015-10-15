#include "Pixel.h"
#include "Color16.h"

Pixel::Pixel(){
  color = 0x000000;
  //hsv16 = CHSV16(0,0,0);
};


void Pixel::setColor(uint32_t clr){
  color = clr;
}

//void Pixel::setHue16(uint16_t hue){
  //hsv16.hue = hue;
//}

//void Pixel::addHue16(int16_t deltaHue){
  //hsv16.hue += deltaHue;
//}

//uint16_t Pixel::getHue16(){
  //return hsv16.hue;
//}

uint32_t Pixel::getColor(){
  //color.hue = (hsv16.hue >> 8);
  //color.sat = (hsv16.sat >> 8);
  //color.val = (hsv16.val >> 8);
  return color;
}

//CHSV16 Pixel::getHsv16(){
  //return hsv16;
//}

//void Pixel::setHsv16(CHSV16 clr){
  //hsv16 = clr;
//}

