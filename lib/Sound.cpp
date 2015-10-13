#include "Sound.h"
#include "Arduino.h"
#include "fix_fft.h"

Sound::Sound(){
  maxVolume = 0;
  for(uint8_t i = 0; i < AVG_BANDS_COUNT; i++){
    maxBandAmp[i] = 0;
  }
}

void Sound::init(){
  pinMode(MIC_PIN, INPUT);
}

void Sound::run(){

  signed int val;

  for (uint8_t i=0; i < SAMPLES_COUNT; i++){
    val = analogRead(MIC_PIN);
    data[i] = val / 2 - 128;
    im[i] = 0;
  }

  //this could be done with the fix_fftr function without the im array.
  fix_fft(data,im,7,0);

  // this gets the absolute value of the values in the array, so we're only dealing with positive numbers
  for (uint8_t i=0; i< SAMPLES_COUNT;i++){
    data[i] = sqrt(data[i] * data[i] + im[i] * im[i]);
  };


  // Bands
  for(uint8_t i=0; i < AVG_BANDS_COUNT; i++){
    bandAmp[i] = 0;
    for(uint8_t j = 0; j < BAND_WIDTH/2; j++){
      bandAmp[i] += data[i*BAND_WIDTH/2 + j];
    }
    if(bandAmp[i] > maxBandAmp[i]){
      maxBandAmp[i] = bandAmp[i];
    }
  }

  // Volume
  volume = 0;
  for(uint8_t i = 0; i < AVG_BANDS_COUNT ; i++){
    volume += bandAmp[i];
  }
  if(volume > maxVolume){
    maxVolume = volume;
  }


}
