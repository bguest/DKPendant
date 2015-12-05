#ifndef SPIN_H
#define SPIN_H

#include "Adafruit_NeoPixel.h"
#include "EffectData.h"

class Spin : public Effect{
  public:
    Spin();
    void run(Adafruit_NeoPixel *strip, EffectData *data);
};
#endif

