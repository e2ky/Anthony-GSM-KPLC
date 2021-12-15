/*
    Arduino Uno SIM800L

    Uses software serial

    Rx ---> Arduino 8
    Tx ---> Arduino 9

    By:- Kim
    Date: 10-08-2021

*/

//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(8, 9); //SIM800L Tx & Rx is connected to Arduino #9 & #8

void setup_sim800l()
{
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing SIM800L...");
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  void updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  void updateSerial();

  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  void updateSerial();
}


void updateSerial()
{
  while (Serial.available())
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port,... allows sending commands to SIM800L?
  }
  while (mySerial.available())
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }

}
