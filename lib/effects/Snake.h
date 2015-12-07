#ifndef SNAKE_H
#define SNAKE_H

#include "Adafruit_NeoPixel.h"
#include "EffectData.h"

class Snake : public Effect{

  public:
    Snake();
    void run(Adafruit_NeoPixel *strip, EffectData *data);
    void randomize();

  private:
    int8_t hueSpeed;
    uint8_t hueStep;
};


#endif
