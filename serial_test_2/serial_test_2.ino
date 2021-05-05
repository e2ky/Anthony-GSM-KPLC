
#include <SoftwareSerial.h>


//Create software serial object to communicate with device

//Tx & Rx is connected to Arduino #9 & #8 respectively
SoftwareSerial mySerial(8, 9); 


void setup() 
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);

  //Begin serial communication with Arduino and external device
  mySerial.begin(9600);  
  
  Serial.println("Initializing..."); 
  delay(1000);
}


void loop() 
{
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
