
#include <SoftwareSerial.h>


//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(8, 9); //SIM800L Tx & Rx is connected to Arduino #9 & #8

String inputString = "";          // a String to hold incoming data
bool stringComplete = false;      // flag whether the string is complete


void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  inputString.reserve(200);     // Reserve 200 bytes for input string
  
  Serial.println("Initializing..."); 
  delay(1000);


  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  
  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial();
}

void loop()
{
  serialEvent();
  
   // print the string when a newline arrives:
  if (stringComplete) 
  {
    Serial.println(inputString);
    
    // clear the string and change stringComplete flag:
    inputString = "";
    stringComplete = false;
  }
}


void updateSerial()
{
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port,... allows sending commands to SIM800L?
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
  
}


void serialEvent()
{
  /*
   while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port,... allows sending commands to SIM800L?
  } 

  */
  while(mySerial.available()) 
  {
    char inChar = (char)mySerial.read();    // get the new byte:
    
    inputString += inChar;                // add it to the inputString:
    
    if (inChar == '\n')     // if the incoming character is a newline, set a flag so the main loop can do something about it:
    {
      stringComplete = true;  //we need to stop reading from serial now....
    }
  }
  
}
