/*
 *  Arduino Uno Keypad Emulation
 *  By:- Kim
 *  Date: 06-11-2020
*/ 

int col1 = 4;
int col2 = 5;
int col3 = 6;
int row1 = 7;
int row2 = 8;
int row3 = 9;
int row4 = 10;

void setup()
{
  Serial.begin(9600);
  
  Serial.println("Initializing..."); 
  delay(1000);
  
  //set all pins as outputs
  pinMode (col1, OUTPUT);
  pinMode (col2, OUTPUT);
  pinMode (col3, OUTPUT);
  pinMode (row1, OUTPUT);
  pinMode (row2, OUTPUT);
  pinMode (row3, OUTPUT);
  pinMode (row4, OUTPUT);
  
}

void loop()
{
  emulate();
  delay(10000);
}

void emulate()
{
  Serial.println("Emulating...");
  delay (1000);
      Serial.println("1");
      digitalWrite (col1, HIGH);
      digitalWrite (col2, LOW);
      digitalWrite (col3, LOW);
      digitalWrite (row1, HIGH);
      digitalWrite (row2, LOW);
      digitalWrite (row3, LOW);
      digitalWrite (row4, LOW);
      delay (1000);

      Serial.println("2");
        digitalWrite (col1, LOW);
        digitalWrite (col2, HIGH);
        digitalWrite (col3, LOW);
        digitalWrite (row1, HIGH);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, LOW);
        delay (1000);

      Serial.println("3");
        digitalWrite (col1, LOW);
        digitalWrite (col2, LOW);
        digitalWrite (col3, HIGH);
        digitalWrite (row1, HIGH);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, LOW);
        delay (1000);

      Serial.println("4");
        digitalWrite (col1, HIGH);
        digitalWrite (col2, LOW);
        digitalWrite (col3, LOW);
        digitalWrite (row1, LOW);
        digitalWrite (row2, HIGH);
        digitalWrite (row3, LOW);
        digitalWrite (row4, LOW);
        delay (1000);
        
      Serial.println("5");
        digitalWrite (col1, LOW);
        digitalWrite (col2, HIGH);
        digitalWrite (col3, LOW);
        digitalWrite (row1, LOW);
        digitalWrite (row2, HIGH);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, LOW);
        delay (1000);

      Serial.println("6");
        digitalWrite (col1, LOW);
        digitalWrite (col2, LOW);
        digitalWrite (col3, HIGH);
        digitalWrite (row1, LOW);
        digitalWrite (row2, HIGH);
        digitalWrite (row3, LOW);
        digitalWrite (row4, LOW);
        delay (1000);

      Serial.println("7");
        digitalWrite (col1, HIGH);
        digitalWrite (col2, LOW);
        digitalWrite (col3, LOW);
        digitalWrite (row1, LOW);
        digitalWrite (row2, LOW);
        digitalWrite (row3, HIGH);
        digitalWrite (row4, LOW);
        delay (1000);

      Serial.println("8");
        digitalWrite (col1, LOW);
        digitalWrite (col2, HIGH);
        digitalWrite (col3, LOW);
        digitalWrite (row1, LOW);
        digitalWrite (row2, LOW);
        digitalWrite (row3, HIGH);
        digitalWrite (row4, LOW);
        delay (1000);

      Serial.println("9");
        digitalWrite (col1, LOW);
        digitalWrite (col2, LOW);
        digitalWrite (col3, HIGH);
        digitalWrite (row1, LOW);
        digitalWrite (row2, LOW);
        digitalWrite (row3, HIGH);
        digitalWrite (row4, LOW);
        delay (1000);

      Serial.println("*");
        digitalWrite (col1, HIGH);
        digitalWrite (col2, LOW);
        digitalWrite (col3, LOW);
        digitalWrite (row1, LOW);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, HIGH);
        delay (1000);

      Serial.println("0");
        digitalWrite (col1, LOW);
        digitalWrite (col2, HIGH);
        digitalWrite (col3, LOW);
        digitalWrite (row1, LOW);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, HIGH);
        delay (1000);

      Serial.println("#");
        digitalWrite (col1, LOW);
        digitalWrite (col2, LOW);
        digitalWrite (col3, HIGH);
        digitalWrite (row1, LOW);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, HIGH);
        delay (1000);        
 
}
    
