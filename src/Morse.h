#ifndef Morse_h
#define Morse_h

#include "Arduino.h"
#include "Led.h"
class Morse{
  private:
    Led laserComponent;
  public:
    Morse();
    Morse(byte laserpin);
    
    void dot();
    void line();
    
    void play(char c);
    void play(String str);
};
#endif
