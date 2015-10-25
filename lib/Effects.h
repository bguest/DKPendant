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
#include "effects/ShiftFade.h"

#define SPIN 0
#define LEVELS 1
#define SHIFT_FADE 2
#define EFFECT_COUNT 3

const uint8_t UPDATE_DURRATION = 5;

class Effects{
  public:
    Effects();
    void init();
    void run();
    void setTempo(uint16_t tempo);
    void setSoundInfo(Sound* sound);
    void changeEffect();

  private:
    unsigned long lastRun;
    uint8_t cEffect;
    Effect* currEffect;

    Spin spin;
    Levels levels;
    ShiftFade shiftFade;

    Adafruit_NeoPixel strip;
    EffectData data;
};
#endif
