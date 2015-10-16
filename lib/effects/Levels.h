#ifndef LEVELS_H
#define LEVELS_H

#include "Adafruit_NeoPixel.h"
#include "EffectData.h"

class Levels : public Effect{
  public:
    Levels();
    void run(Adafruit_NeoPixel *strip, EffectData data);
};
#endif

