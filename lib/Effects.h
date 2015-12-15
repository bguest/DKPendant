#ifndef EFFECTS_H
#define EFFECTS_H

#define LED_COUNT 4
#define LED_PIN 10

#include "Adafruit_NeoPixel.h"
#include "Arduino.h"
#include "Sound.h"
#include "effects/Effect.h"
#include "effects/Spin.h"
#include "effects/Levels.h"
#include "effects/ShiftFade.h"
#include "effects/Snake.h"
#include "effects/RandomOn.h"
#include "effects/RandomSound.h"

#define SPIN 0
#define SHIFT_FADE 1
#define LEVELS 2
#define SNAKE 3
#define RANDOM_ON 4
#define RANDOM_SOUND 5
#define EFFECT_COUNT 6

const uint8_t UPDATE_DURRATION = 5;

class Effects{
  public:
    Effects();
    void init();
    void run();
    void setTempo(uint16_t tempo);
    void setSoundInfo(Sound* sound);
    void randomize();
    void setEffect(uint8_t kEffect);
    uint8_t getEffect();
    void setHueAll(uint8_t hue);
    void changeEffect();
    void off();

  private:
    unsigned long lastRun;
    uint8_t cEffect;
    Effect* currEffect;

    unsigned long lastStep;
    uint8_t startIdx;
    void updateStartIdx();

    Spin spin;
    Levels levels;
    ShiftFade shiftFade;
    Snake snake;
    RandomOn randomOn;
    RandomSound randomSound;

    Adafruit_NeoPixel strip;
    EffectData data;
};
#endif
