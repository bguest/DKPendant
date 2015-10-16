#ifndef TEMPO_H
#define TEMPO_H

#ifndef __AVR_ATtiny85__
  #define TEMPO_BUTTON 3
#else
  #define TEMPO_BUTTON 3
#endif

#include <Bounce2.h>

const uint8_t TAP_COUNT = 8;

class Tempo{

  public:
    Tempo();
    void init();
    void run();
    uint16_t tempo();
    bool isDoubleTap();
    bool didUpdate();

  private:
    const uint16_t MAXIMUM_PERIOD = 2500;
    const uint16_t DOUBLE_TAP_PERIOD = 180;

    Bounce tempoButton;
    uint8_t tapIdx;
    uint16_t tapTimes[TAP_COUNT];

    bool _shouldUpdate;
    uint16_t _tempo;
    bool _isDoubleTap;
    bool _didUpdate;

    void recordTap();
    void runCalc();
};


#endif
