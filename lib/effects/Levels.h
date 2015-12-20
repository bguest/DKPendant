#ifndef LEVELS_H
#define LEVELS_H

#include "Adafruit_NeoPixel.h"
#include "EffectData.h"

class Levels : public Effect{
  public:
    Levels();
    void randomize();
    void run(Adafruit_NeoPixel *strip, EffectData *data);

  private:
    int8_t hueSpeed[LED_COUNT];
};
#endif

