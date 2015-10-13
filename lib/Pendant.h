#ifndef PENDANT_H
#define PENDANT_H

#define TEMPO_BUTTON 2

#include "Arduino.h"
#include "Tempo.h"
#include "Sound.h"
#include "Effects.h"

class Pendant{
  public:
    Pendant();
    void init();
    void run();

  private:
    Tempo tempoButton;
    Sound sound;
    Effects effects;
};
#endif
