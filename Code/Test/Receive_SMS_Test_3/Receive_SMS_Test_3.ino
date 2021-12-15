/*
#include <SoftwareSerial.h>


//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(8, 9); //SIM800L Tx & Rx is connected to Arduino #3 & #2
*/

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  /*
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);
  */

  Serial.println("Initializing..."); 
  delay(1000);
/*

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial();
  */

  // SIM800l handshake
  Serial.println("AT"); //Once the handshake test is successful, it will back to OK

  // Configuring TEXT mode
  Serial.println("AT+CMGF=1"); // If successful, will return okay

  // Decides how newly arrived SMS messages should be handled
  Serial.println("AT+CNMI=1,2,0,0,0"); 
}

void loop()
{
  serialEvent();
}

void serialEvent()
{
  while (Serial.available());
  {
    Serial.read();
  }
}
