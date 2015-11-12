#ifndef PENDANT_H
#define PENDANT_H

#include "Arduino.h"
#include "Power.h"
#include "Tempo.h"
#include "Sound.h"
#include "Effects.h"
#include "IRremote.h"

class Pendant{
  public:
    Pendant();
    void init();
    void run();

  private:
    Power power;
    IRsend irSend;
    Tempo tempoButton;
    Sound sound;
    Effects effects;
};
#endif
