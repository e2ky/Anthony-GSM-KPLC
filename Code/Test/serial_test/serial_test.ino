
String inputString = "";          // a String to hold incoming data
bool stringComplete = false;      // whether the string is complete


void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);

  // Reserve 200 bytes for input string
  inputString.reserve(200);     
  
  Serial.println("Initializing..."); 
  //delay(1000);

}

void loop()
{
  // print the string when a newline arrives:
  if (stringComplete) 
  {
    Serial.println(inputString);
    
    // clear the string and change stringComplete flag:
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent()
{
  while (Serial.available()) 
  {
    // get the new byte:
    char inChar = (char)Serial.read();

    // print character as it gets saved
    Serial.println(inChar);
        
    // add it to the inputString:
    inputString += inChar;
    
    // if the incoming character is a newline, set a flag so the main loop can do something about it:
    if (inChar == '\n') 
    {
      stringComplete = true;
    }
  }  
}
