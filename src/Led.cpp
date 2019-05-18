#include "Arduino.h"
#include "Led.h"

Led::Led(){
  
  this->pin = 0;
  state = LOW;
  
  // set the pinmode of the laser
  pinMode(pin, OUTPUT);
}

Led::Led(byte pin){
  
  this->pin = pin;
  state = LOW;
  
  // set the pinmode of the laser
  pinMode(pin, OUTPUT);
}

void Led::toggle(boolean state){
  if(state == this->state) return;
  
  this->state = state;
  digitalWrite(pin, state);
}
