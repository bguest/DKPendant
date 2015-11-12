#include "Power.h"
#include "Arduino.h"

Power::Power(){
  powerIn = Bounce();
  isOn = true;

}

void Power::init(){
  pinMode(POWER_PIN_IN, INPUT);
  powerIn.attach(POWER_PIN_IN);

  pinMode(POWER_PIN_OUT, OUTPUT);
  digitalWrite(POWER_PIN_OUT, HIGH);
}

void Power::run(){

  if(millis() < MIN_ON_TIME){
    return;
  }

  if(powerIn.rose()){
    isOn = false;
  }

  if(isOn){
    digitalWrite(POWER_PIN_OUT, HIGH);
  }else{
    digitalWrite(POWER_PIN_OUT, LOW);
  }

}

