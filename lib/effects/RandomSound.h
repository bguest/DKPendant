#ifndef RANDOM_SOUND_H
#define RANDOM_SOUND_H

#include "Adafruit_NeoPixel.h"
#include "EffectData.h"

class RandomSound : public Effect{

  public:
    RandomSound();
    void run(Adafruit_NeoPixel *strip, EffectData *data);
    void randomize();

  private:
    unsigned long lastStep;
    uint8_t onPixel;
    uint16_t brightness[4];
    uint8_t hueStep;

    void updatePixels();
};



#endif
