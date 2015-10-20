#ifndef PENDANT_H
#define PENDANT_H

#include "Arduino.h"
#include "Tempo.h"
#include "Sound.h"
#include "Effects.h"
#include "IRSend.h"

class Pendant{
  public:
    Pendant();
    void init();
    void run();

  private:
    IRSend irSend;
    Tempo tempoButton;
    Sound sound;
    Effects effects;
};
#endif
