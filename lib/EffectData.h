#ifndef EFFECT_DATA_H
#define EFFECT_DATA_H

#define UINT8_MAX 0xFF
#define UINT16_MAX 0xFFFF

struct EffectData{
  uint16_t tempo; // Period between taps
  uint8_t volume;
  uint8_t maxVolume;
  uint8_t startIdx;
  uint8_t bandAmp[4];
  uint16_t hue[4];
};
#endif
