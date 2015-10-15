#ifndef SOUND_H
#define SOUND_H

#include "Arduino.h"

#ifdef DEBUG
  #define MIC_PIN A3
#else
  #define MIC_PIN A1
#endif

const uint8_t BANDS_COUNT = 5;
const uint8_t SAMPLES_COUNT = 32; // 2**BANDS_COUNT
const uint8_t AVG_BANDS_COUNT = 4; // Resolved Bands
const uint8_t BAND_WIDTH = SAMPLES_COUNT / AVG_BANDS_COUNT;

class Sound{
  public:
    Sound();
    void init();
    void run();
    uint8_t volume;
    uint8_t maxVolume;
    uint8_t bandAmp[AVG_BANDS_COUNT];
    uint8_t maxBandAmp[AVG_BANDS_COUNT];

  private:
    char im[SAMPLES_COUNT];
    char data[SAMPLES_COUNT];
    char data_avgs[SAMPLES_COUNT];

};

#endif
