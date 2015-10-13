#ifndef EFFECTS_H
#define EFFECTS_H

#include "Arduino.h"
#include "Sound.h"
#include "effects/Effect.h"
#include "effects/Spin.h"
#include "effects/Levels.h"

#define SPIN 0
#define LEVELS 1
#define EFFECT_COUNT 2

class Effects{
  public:
    Effects();
    void init();
    void run();
    void setTempo(uint16_t tempo);
    void setSoundInfo(Sound* sound);
    void changeEffect();

  private:
    uint8_t cEffect;
    Effect* currEffect;

    Spin spin;
    Levels levels;

    Leds leds;
    EffectData data;
};
#endif
