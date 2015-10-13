#ifndef LEVELS_H
#define LEVELS_H

#include "Leds.h"
#include "EffectData.h"

class Levels : public Effect{
  public:
    Levels();
    void run(Leds *leds, EffectData data);
};
#endif

