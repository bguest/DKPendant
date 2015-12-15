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
    uint8_t pixel[3];
    unsigned long lastStep;
    int8_t hueSpeed;
    void updatePixels();

};


#endif
