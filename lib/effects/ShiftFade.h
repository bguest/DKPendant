#ifndef SHIFT_FADE_H
#define SHIFT_FADE_H

#include "Adafruit_NeoPixel.h"
#include "EffectData.h"

class ShiftFade : public Effect{

  public:
    ShiftFade();
    void run(Adafruit_NeoPixel *strip, EffectData data);

  private:
    unsigned long lastStep;
    uint8_t startIdx;
    uint16_t hue[4];
};

#endif
