#include "Power.h"
#include "Arduino.h"

void wake()
{
  sleep_disable();     // cancel sleep as a precaution
  detachInterrupt (0); // precautionary while we do other stuff
}  // end of wake


Power::Power(){
  sleepButton = Bounce();
}

void Power::init(){
  pinMode(SLEEP_PIN, INPUT_PULLUP);

  sleepButton.attach(SLEEP_PIN);
  sleepButton.interval(1);
}

bool Power::buttonPressed(){

  bool buttonPressed = false;
  sleepButton.update();

  if( sleepButton.fell() ){
    buttonPressed = true;
  }
  return buttonPressed;
}

void Power::off(){

  // disable ADC
  ADCSRA = 0;

  set_sleep_mode (SLEEP_MODE_PWR_DOWN);
  sleep_enable();

  // Do not interrupt before we go to sleep, or the
  // ISR will detach interrupts and we won't wake.
  noInterrupts ();

  // will be called when pin D2 goes low
  attachInterrupt (digitalPinToInterrupt(SLEEP_PIN), wake, FALLING);
  EIFR = bit (INTF0);  // clear flag for interrupt 0

  // turn off brown-out enable in software
  // BODS must be set to one and BODSE must be set to zero within four clock cycles
  //MCUCR = bit (BODS) | bit (BODSE);
  // The BODS bit is automatically cleared after three clock cycles
  //MCUCR = bit (BODS);

  // We are guaranteed that the sleep_cpu call will be done
  // as the processor executes the next instruction after
  // interrupts are turned on.
  interrupts ();  // one cycle
  sleep_cpu ();   // one cycle
}

