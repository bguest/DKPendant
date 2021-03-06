#include "Sound.h"
#include "Arduino.h"
#include "fix_fft.h"

#define UINT8_MAX 0xFF

Sound::Sound(){
  maxVolume = 0;
  for(uint8_t i = 0; i < AVG_BANDS_COUNT; i++){
    maxBandAmp[i] = 0;
  }
}

void Sound::init(){
  pinMode(MIC_PIN, INPUT);
}

uint8_t Sound::volume(){
  return (UINT8_MAX * _volume)/maxVolume;
}

uint8_t Sound::bandAmp(uint8_t i){
  return (UINT8_MAX * _bandAmp[i])/maxBandAmp[i];
}

void Sound::run(){

  signed int val;

  for (uint8_t i=0; i < SAMPLES_COUNT; i++){
    val = analogRead(MIC_PIN);
    data[i] = val / 2 - 128;
    im[i] = 0;
  }

  //this could be done with the fix_fftr function without the im array.
  fix_fft(data,im,BANDS_COUNT,0);

  // this gets the absolute value of the values in the array, so we're only dealing with positive numbers
  for (uint8_t i=0; i< SAMPLES_COUNT;i++){
    data[i] = sqrt(data[i] * data[i] + im[i] * im[i]);
  };


  // Bands
  for(uint8_t i=0; i < AVG_BANDS_COUNT; i++){
    _bandAmp[i] = 0;
    for(uint8_t j = 0; j < BAND_WIDTH/4; j++){
      _bandAmp[i] += data[i*BAND_WIDTH/4 + j];
    }
    if(_bandAmp[i] > maxBandAmp[i]){
      maxBandAmp[i] = _bandAmp[i];
    }
  }

  // Volume
  _volume = 0;
  for(uint8_t i = 0; i < AVG_BANDS_COUNT ; i++){
    _volume += _bandAmp[i];
  }
  if(_volume > maxVolume){
    maxVolume = _volume;
  }


}
