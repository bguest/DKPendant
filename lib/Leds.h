#ifndef LEDS_H
#define LEDS_H

#define LED_COUNT 4

#ifdef DEBUG
  #define LED_PIN 3
#else
  #define LED_PIN 0
#endif

#include "Adafruit_NeoPixel.h"
#include "Pixel.h"

class Leds{

  public:
    Leds();
    void init();
    void run();

    void off(); //Turn LEDs all off

    void colorAtIndex(uint32_t color , uint8_t idx);
    uint32_t colorAtIndex(uint8_t idx);
    Pixel* pixelAtIndex(uint8_t idx);

    Pixel pixels[LED_COUNT];

  private:

    Adafruit_NeoPixel strip;
    //CRGB leds[LED_COUNT];

};

#endif
