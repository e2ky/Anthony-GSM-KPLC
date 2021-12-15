#include "Adafruit_Keypad.h"

const byte ROWS = 4; 
const byte COLS = 3; 

char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; 
byte colPins[COLS] = {4, 3, 2}; 

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  customKeypad.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  customKeypad.tick();

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    Serial.print((char)e.bit.KEY);
    if(e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
    else if(e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
  }

  delay(100);
}
