#ifndef PENDANT_H
#define PENDANT_H

#define TEMPO_BUTTON 1

#include "Arduino.h"
#include "Tempo.h"

class Pendant{
  public:
    Pendant();
    void init();
    void run();

  private:
    Tempo tempoButton;
};
#endif
