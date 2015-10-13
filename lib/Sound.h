#ifndef SOUND_H
#define SOUND_H

#include "Arduino.h"

#define MIC_PIN A3

const uint8_t BANDS_COUNT = 7;
const uint8_t SAMPLES_COUNT = 128; // 2**BANDS_COUNT

class Sound{
  public:
    Sound();
    void init();
    void run();
    uint16_t maxVol;
    uint16_t volume;

  private:
    char im[SAMPLES_COUNT];
    char data[SAMPLES_COUNT];
    char data_avgs[SAMPLES_COUNT];

};

#endif
