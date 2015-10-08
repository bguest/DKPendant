#ifndef TEMPO_H
#define TEMPO_H

#include <Bounce2.h>

const uint8_t TAP_COUNT = 8;
const uint16_t MAXIMUM_PERIOD = 3000;

class Tempo{

  public:
    Tempo();
    void init();
    void run();
    uint16_t tempo();

  private:
    Bounce tempoButton;
    uint8_t tapIdx;
    uint16_t tapTimes[TAP_COUNT];
    uint16_t _tempo;

    void recordTap();
};


#endif
