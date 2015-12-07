#ifndef SHIFT_FADE_H
#define SHIFT_FADE_H

#include "Adafruit_NeoPixel.h"
#include "EffectData.h"

class ShiftFade : public Effect{

  public:
    ShiftFade();
    void run(Adafruit_NeoPixel *strip, EffectData *data);
    void randomize();

  private:
    int8_t hueSpeed[LED_COUNT];
};

#endif
