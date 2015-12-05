#ifndef EFFECT_H
#define EFFECT_H

#include "EffectData.h"

class Effect{
  public:
    Effect();
    uint32_t wheel(byte WheelPos, uint8_t brightness);
    void off(Adafruit_NeoPixel *strip);
    virtual void run(Adafruit_NeoPixel *strip, EffectData *data);
    virtual void randomize();
};
#endif
