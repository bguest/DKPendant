#ifndef EFFECT_DATA_H
#define EFFECT_DATA_H

struct EffectData{
  uint16_t tempo;
  uint16_t volume;
  uint16_t maxVolume;
  uint16_t bandAmp[4];
  uint16_t maxBandAmp[4];
};
#endif
