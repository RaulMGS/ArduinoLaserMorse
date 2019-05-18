#ifndef Led_h
#define Led_h

#include "Arduino.h"
class Led{
  private:
    byte pin;
    boolean state;

  public:
    Led();
    Led(byte pin);
    void toggle(boolean state);
};
#endif
