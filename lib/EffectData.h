#ifndef EFFECT_DATA_H
#define EFFECT_DATA_H

#define UINT8_MAX 0xFF

struct EffectData{
  uint16_t tempo;
  uint8_t volume;
  uint8_t bandAmp[4];
  uint16_t hue[4];
};
#endif
