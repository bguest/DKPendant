#ifndef RANDOM_ON_H
#define RANDOM_ON_H

#include "Adafruit_NeoPixel.h"
#include "EffectData.h"

class RandomOn : public Effect{

  public:
    RandomOn();
    void run(Adafruit_NeoPixel *strip, EffectData *data);
    void randomize();

  private:
    uint8_t activePixel[2];
    unsigned long lastStep;
    uint16_t maxHueStep;

    void updateActive();
};



#endif
