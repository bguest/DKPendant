#ifndef SPIN_H
#define SPIN_H

#include "Leds.h"
#include "EffectData.h"

class Spin : public Effect{
  public:
    Spin();
    void run(Leds *leds, EffectData data);
};
#endif

