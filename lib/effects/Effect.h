#ifndef EFFECT_H
#define EFFECT_H

#include "Leds.h"
#include "EffectData.h"

class Effect{
  public:
    Effect();
    virtual void run(Leds *leds, EffectData data);
};
#endif
