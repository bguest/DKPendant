#ifndef LEDS_H
#define LEDS_H

#define LED_COUNT 4

#include "FastLED.h"

class Leds{

  public:
    Leds();
    void init();
    void run();

  private:
    CRGB leds[LED_COUNT];

};

#endif
