
#include <SoftwareSerial.h>

#include "keypad_emulator_v7.0.h"
#include "SIM800L_setup.h"

//char inChar;     //character to hold incoming data, byte by byte
String inputString = "";          // a String to hold incoming data
bool stringComplete = false;      // flag whether the string is complete
bool ignoreString = true;        //flag to determine whether to ignore line


void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  delay(1000);
  
  Serial.println("Initializing...");
  delay(1000);
  
  setup_sim800l();          // run sim800l setup

  setup_emulator();         // run keypad_emulate setup

  inputString.reserve(200);     // Reserve 200 bytes for input string
}


void loop()
{
  if (stringComplete)
  {
    Serial.println(inputString);        // print the string when a newline arrives:

    // clear the string and change stringComplete flag:
    inputString = "";
    stringComplete = false;
  }

  serialEvent();

}

void serialEvent()
{
  while (mySerial.available())
  {
    inChar = (char)mySerial.read();    // get the new byte:
    if (inChar == '+')    // if the incoming character is a +, don't emulate the line as this is system information e.g. phone no. ...
    {
      ignoreString = true;
    }

    readSMSEvent();

    if (!ignoreString)    // if the line is not a system message, emulate keypad stroke
    {
      emulate_key();    //code to emulate keypad stroke
      delay (750);
      key_release();
      delay (750);
    }

    if (stringComplete)
    {
      loop();   // exits the serial read
    }

  }

}

void readSMSEvent()
{
  inputString += inChar;                // add it to the inputString:

  /*
    if (inChar == ' ')      // if the incoming character is a space, ignore and don't emulate
    {
      inChar = "";
    }
  */

  if (inChar == '\n')     // if the incoming character is a newline, set a flag so the main loop can do something about it:
  {
    if (ignoreString)
    {
      inputString += "*+";
    }

    if (!ignoreString)
    {
      inputString += "end of text";
      inChar = '#';
      inputString += inChar;
    }

    stringComplete = true;  //we need to stop reading from serial now....
    ignoreString = false;    // end of line, reset so we don't ignore the next line (it might be the text we have been waiting for...)
  }
}
