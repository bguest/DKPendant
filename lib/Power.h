#ifndef POWER_H
#define POWER_H

#define SLEEP_PIN 3

#define MIN_ON_TIME 2000

#include <avr/sleep.h>
#include <Bounce2.h>

class Power{

  public:
    Power();
    void init();
    void off();
    bool buttonPressed();

  private:
    Bounce sleepButton;
};

#endif
