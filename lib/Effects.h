#ifndef EFFECTS_H
#define EFFECTS_H

#define LED_COUNT 4
#define LED_PIN 4

#include "Adafruit_NeoPixel.h"
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

    Adafruit_NeoPixel strip;
    EffectData data;
};
#endif
