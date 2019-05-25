#include "Morse.h"
Morse::Morse(){
  laserComponent = Led(0);
}
Morse::Morse(byte laserpin){
  laserComponent = Led(laserpin);
  
  // set the pinmode of the laser
  pinMode(laserpin, OUTPUT);
}
void Morse::dot(){
  laserComponent.toggle(HIGH);
  delay(250);
  laserComponent.toggle(LOW);
  delay(250);
}
void Morse::line(){
  laserComponent.toggle(HIGH);
  delay(1000);
  laserComponent.toggle(LOW);
  delay(250);
}
void Morse::play(char c){
  if(c == 'a'){ dot(); line();}
  else if(c == 'b'){ line(); dot(); dot(); dot();}
  else if(c == 'c'){ line(); dot(); line(); dot();}
  else if(c == 'd'){ line(); dot(); dot();}
  else if(c == 'e'){ dot();}
  else if(c == 'f'){ dot(); dot(); line(); dot();}
  else if(c == 'g'){ line(); line(); dot();}
  else if(c == 'h'){ dot(); dot(); dot(); dot();}
  else if(c == 'i'){ dot(); dot();}
  else if(c == 'j'){ dot(); line(); line(); line();}
  else if(c == 'k'){ line(); dot(); line();}
  else if(c == 'l'){ dot(); line(); dot(); dot();}
  else if(c == 'm'){ line(); line();}
  else if(c == 'n'){ line(); dot();}
  else if(c == 'o'){ dot(); line(); dot(); dot(); dot();}
  else if(c == 'p'){ dot(); dot(); dot(); dot(); dot();}
  else if(c == 'q'){ line(); line(); dot(); line();}
  else if(c == 'r'){ dot(); line(); dot();}
  else if(c == 's'){ dot(); dot(); dot();}
  else if(c == 't'){ line();}
  else if(c == 'u'){ dot(); dot(); line();}
  else if(c == 'v'){ dot(); dot(); dot(); line();}
  else if(c == 'w'){ dot(); line(); line();}
  else if(c == 'x'){ dot(); dot(); line(); dot(); dot(); dot();}
  else if(c == 'y'){ line(); line(); dot(); dot(); dot();}
  else if(c == 'z'){ dot(); line(); line(); dot(); dot();}
}
void Morse::play(String str){
  Serial.print(str + "\n");
  for(int i=0;i<str.length();i++){
    play(str.charAt(i));
  }
}
