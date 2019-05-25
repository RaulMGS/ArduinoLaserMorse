#define PIN_LED_START 2 
#define PIN_LED_STOP 3
#define PIN_LED_LASER 6

#define PIN_BTN_1 8
#define PIN_BTN_2 9
#define PIN_BTN_3 10
#define PIN_BTN_START 13

#include "src/Led.h"
#include "src/Morse.h"

// Morse master
Morse m;

// Leds
Led ledOn;
Led ledOff;

// Start Button pressCount -> odd = off, even = on
int btnStartPresses = 0;

void setup() {
  // setup morse;
  m = Morse(PIN_LED_LASER);
  
  // setup the on/off leds
  ledOff = Led(PIN_LED_STOP);
  ledOn = Led(PIN_LED_START);

  // setup the buttons
  pinMode(PIN_BTN_1, INPUT);
  pinMode(PIN_BTN_2, INPUT);
  pinMode(PIN_BTN_3, INPUT);
  pinMode(PIN_BTN_START, INPUT);

  Serial.begin(9600);
}

void loop() {
  // listen for program start button
  if(digitalRead(PIN_BTN_START)) {
    btnStartPresses++;
  }
  
  // OFF STATE
  if(btnStartPresses % 2 == 0)
  {
    ledOn.toggle(LOW);
    ledOff.toggle(HIGH);
    btnStartPresses = 0;
    delay(500);
  }
  
  // ON STATE
  if(btnStartPresses % 2 != 0)
  {
    ledOn.toggle(HIGH);
    ledOff.toggle(LOW);
    delay(500);

    // listen for message buttons
    if(digitalRead(PIN_BTN_1)) {  
      m.play("upt");
    }
    else if(digitalRead(PIN_BTN_2)) {
      m.play("ac");
    }
    else if(digitalRead(PIN_BTN_3)) { 
      m.play("hello there");
    }
  }
}
