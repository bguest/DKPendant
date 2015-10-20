#ifndef IR_SEND_H
#define IR_SEND_H

#define IRLED PINB1 // pin 6 on ATtiny85

#include "Arduino.h"

class IRSend {
  public:
    IRSend();
    void init();
    void sendSAMSUNG (unsigned long data,  int nbits);

  private:

};

#endif
