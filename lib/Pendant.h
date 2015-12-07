#ifndef PENDANT_H
#define PENDANT_H

#include "Arduino.h"
#include "Power.h"
#include "Tempo.h"
#include "Sound.h"
#include "Effects.h"
#include "IRremote.h"

#define PENDANT_ID 0x55
//#define PENDANT_ID 0xAA
//#define PENDANT_ID 0x7F
#define IR_PIN 5

class Pendant{
  public:
    Pendant();
    void init();
    void run();

  private:
    Power power;
    Tempo tempoButton;
    Sound sound;
    Effects effects;

    IRsend irSend;
    IRrecv *irrecv;
    decode_results irResults;
    void handleIrCode(uint32_t irCode);
};
#endif
