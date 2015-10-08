#include <Bounce2.h>
#include <Pendant.h>

Pendant pendant;

void setup(){
  Serial.begin(9600);
  pendant.init();
}

void loop(){
  pendant.run();
}
