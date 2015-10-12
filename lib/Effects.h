#ifndef EFFECTS_H
#define EFFECTS_H

#include "Arduino.h"
#include "effects/Effect.h"
#include "effects/Spin.h"

#define SPIN 0
#define EFFECT_COUNT 1

class Effects{
  public:
    Effects();
    void init();
    void run();
    void setTempo(uint16_t tempo);
    void changeEffect();

  private:
    uint8_t cEffect;
    Effect* currEffect;

    Spin spin;

    Leds leds;
    uint16_t _tempo;
};
#endif
