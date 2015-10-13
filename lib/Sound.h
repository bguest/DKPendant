#ifndef SOUND_H
#define SOUND_H

#include "Arduino.h"

#define MIC_PIN A3

const uint8_t BANDS_COUNT = 7;
const uint8_t SAMPLES_COUNT = 128; // 2**BANDS_COUNT
const uint8_t AVG_BANDS_COUNT = 4; // Resolved Bands
const uint8_t BAND_WIDTH = SAMPLES_COUNT / AVG_BANDS_COUNT;

class Sound{
  public:
    Sound();
    void init();
    void run();
    uint16_t volume;
    uint16_t maxVolume;
    uint16_t bandAmp[AVG_BANDS_COUNT];
    uint16_t maxBandAmp[AVG_BANDS_COUNT];

  private:
    char im[SAMPLES_COUNT];
    char data[SAMPLES_COUNT];
    char data_avgs[SAMPLES_COUNT];

};

#endif
