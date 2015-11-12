#ifndef POWER_H
#define POWER_H

#define POWER_PIN_OUT 6
#define POWER_PIN_IN 7

#define MIN_ON_TIME 2000

#include <Bounce2.h>

class Power{

  public:
    Power();
    void init();
    void run();

  private:
    Bounce powerIn;
    bool isOn;

};

#endif
