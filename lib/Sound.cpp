#include "Sound.h"
#include "Arduino.h"
#include "fix_fft.h"

Sound::Sound(){
  maxVol = 0;
}

void Sound::init(){
  pinMode(MIC_PIN, INPUT);
}

void Sound::run(){

  signed int val;
  uint8_t static i;

  for (i=0; i < SAMPLES_COUNT; i++){
    val = analogRead(MIC_PIN);
    data[i] = val / 2 - 128;
    im[i] = 0;
  }

  //this could be done with the fix_fftr function without the im array.
  fix_fft(data,im,7,0);

  // this gets the absolute value of the values in the array, so we're only dealing with positive numbers
  for (i=0; i< 64;i++){
    data[i] = sqrt(data[i] * data[i] + im[i] * im[i]);
  };

  // Sum Points
  volume = 0;
  for(i = 0; i < SAMPLES_COUNT ; i++){
    volume += data[i];
  }
  if(volume > maxVol){
    maxVol = volume;
  }


}
