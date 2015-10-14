#ifndef LEDS_H
#define LEDS_H

#define LED_COUNT 4

#ifdef DEBUG
  #define LED_PIN 3
#else
  #define LED_PIN 0
#endif

#include "FastLED.h"
#include "Pixel.h"

class Leds{

  public:
    Leds();
    void init();
    void run();

    void off(); //Turn LEDs all off

    void colorAtIndex(CHSV color , uint8_t idx);
    CHSV colorAtIndex(uint8_t idx);
    Pixel* pixelAtIndex(uint8_t idx);

    Pixel pixels[LED_COUNT];

  private:
    CRGB leds[LED_COUNT];

};

#endif
