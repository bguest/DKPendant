#include "Pendant.h"

Pendant::Pendant(){
  irrecv = new IRrecv(IR_PIN);
};

void Pendant::init(){
  power.init();
  tempoButton.init();
  effects.init();
  sound.init();
  irrecv -> enableIRIn();
}

void Pendant::run(){

  if(power.buttonPressed()){
    effects.off();
    power.off();
  }

  if(irrecv -> decode(&irResults)) {
    //Serial.println(results.value, HEX);
    this -> handleIrCode(irResults.value);
    irrecv -> resume(); // Receive the next value
  }

  tempoButton.run();
  sound.run();
  effects.setSoundInfo(&sound);

  if(tempoButton.didUpdate()){
    if(tempoButton.isDoubleTap()){
      sound.reset();
      effects.changeEffect();
    }
    effects.setTempo(tempoButton.tempo());
  }
  if(tempoButton.heldOn){
    uint32_t send = PENDANT_ID << 24;
    send |= effects.getEffect() << 16;
    send |= tempoButton.tempo();
    irSend.sendSAMSUNG(send, 32);
    //this -> handleIrCode(send);
  }

  effects.run();
}

void Pendant::handleIrCode(uint32_t irCode){
  uint8_t kEffect = 0x00FF & irCode >> 16;
  //effects.setEffect(kEffect);
  effects.setEffect(SHIFT_FADE);
  uint16_t tempo = 0x0000FFFF & irCode;
  uint8_t hue = irCode >> 24;
  effects.setHueAll(hue);
  effects.setTempo(tempo);
}
