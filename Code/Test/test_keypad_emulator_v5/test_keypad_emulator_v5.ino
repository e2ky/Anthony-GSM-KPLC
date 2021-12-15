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
 /* 
  //set all pins as outputs --+
  pinMode (col1, INPUT);
  pinMode (col2, INPUT);
  pinMode (col3, INPUT);
  pinMode (row1, INPUT);
  pinMode (row2, INPUT);
  pinMode (row3, INPUT);
  pinMode (row4, INPUT);
  */
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
  pinMode (col1, OUTPUT);
  pinMode (col2, INPUT);
  pinMode (col3, INPUT);
  pinMode (row1, OUTPUT);
  pinMode (row2, INPUT);
  pinMode (row3, INPUT);
  pinMode (row4, INPUT);
  digitalWrite (col1, HIGH);
  digitalWrite (row1, HIGH);
  delay (1000);

  Serial.println("2");
  pinMode (col1, INPUT);
  pinMode (col2, OUTPUT);
  pinMode (col3, INPUT);
  pinMode (row1, OUTPUT);
  pinMode (row2, INPUT);
  pinMode (row3, INPUT);
  pinMode (row4, INPUT);
  digitalWrite (col2, HIGH);
  digitalWrite (row1, HIGH);
  delay (1000);

  Serial.println("3");
  pinMode (col1, INPUT);
  pinMode (col2, INPUT);
  pinMode (col3, OUTPUT);
  pinMode (row1, OUTPUT);
  pinMode (row2, INPUT);
  pinMode (row3, INPUT);
  pinMode (row4, INPUT);
  digitalWrite (col3, HIGH);
  digitalWrite (row1, HIGH);
  delay (1000);

  Serial.println("4");
  pinMode (col1, OUTPUT);
  pinMode (col2, INPUT);
  pinMode (col3, INPUT);
  pinMode (row1, INPUT);
  pinMode (row2, OUTPUT);
  pinMode (row3, INPUT);
  pinMode (row4, INPUT);
  digitalWrite (col1, HIGH);
  digitalWrite (row2, HIGH);
  delay (1000);
        
  Serial.println("5");
  pinMode (col1, INPUT);
  pinMode (col2, OUTPUT);
  pinMode (col3, INPUT);
  pinMode (row1, INPUT);
  pinMode (row2, OUTPUT);
  pinMode (row3, INPUT);
  pinMode (row4, INPUT);
  digitalWrite (col2, HIGH);
  digitalWrite (row2, HIGH);
  delay (1000);

  Serial.println("6");
  pinMode (col1, INPUT);
  pinMode (col2, INPUT);
  pinMode (col3, OUTPUT);
  pinMode (row1, INPUT);
  pinMode (row2, OUTPUT);
  pinMode (row3, INPUT);
  pinMode (row4, INPUT);
  digitalWrite (col3, HIGH);
  digitalWrite (row2, HIGH);
  delay (1000);

  Serial.println("7");
  pinMode (col1, OUTPUT);
  pinMode (col2, INPUT);
  pinMode (col3, INPUT);
  pinMode (row1, INPUT);
  pinMode (row2, INPUT);
  pinMode (row3, OUTPUT);
  pinMode (row4, INPUT);
  digitalWrite (col1, HIGH);
  digitalWrite (row3, HIGH);
  delay (1000);

  Serial.println("8");
  pinMode (col1, INPUT);
  pinMode (col2, OUTPUT);
  pinMode (col3, INPUT);
  pinMode (row1, INPUT);
  pinMode (row2, INPUT);
  pinMode (row3, OUTPUT);
  pinMode (row4, INPUT);
  digitalWrite (col2, HIGH);
  digitalWrite (row3, HIGH);
  delay (1000);

  Serial.println("9");
  pinMode (col1, INPUT);
  pinMode (col2, INPUT);
  pinMode (col3, OUTPUT);
  pinMode (row1, INPUT);
  pinMode (row2, INPUT);
  pinMode (row3, OUTPUT);
  pinMode (row4, INPUT);
  digitalWrite (col3, HIGH);
  digitalWrite (row3, HIGH);
  delay (1000);

  Serial.println("*");
  pinMode (col1, OUTPUT);
  pinMode (col2, INPUT);
  pinMode (col3, INPUT);
  pinMode (row1, INPUT);
  pinMode (row2, INPUT);
  pinMode (row3, INPUT);
  pinMode (row4, OUTPUT);
  digitalWrite (col1, HIGH);
  digitalWrite (row4, HIGH);
  delay (1000);

  Serial.println("0");
  pinMode (col1, INPUT);
  pinMode (col2, OUTPUT);
  pinMode (col3, INPUT);
  pinMode (row1, INPUT);
  pinMode (row2, INPUT);
  pinMode (row3, INPUT);
  pinMode (row4, OUTPUT);
  digitalWrite (col2, HIGH);
  digitalWrite (row4, HIGH);
  delay (1000);

  Serial.println("#");
  pinMode (col1, INPUT);
  pinMode (col2, INPUT);
  pinMode (col3, OUTPUT);
  pinMode (row1, INPUT);
  pinMode (row2, INPUT);
  pinMode (row3, INPUT);
  pinMode (row4, OUTPUT);
  digitalWrite (col3, HIGH);
  digitalWrite (row4, HIGH);
  delay (1000);        
 
}
    
