/*
 *  Arduino Uno Keypad Emulation
 *  By:- Kim
 *  Date: 06-11-2020
*/ 
int i;
byte input [20];     // setup aray for data storage

boolean newData = false;

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
  
  i=0;      //set array index to 0
  
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
  recvData();
  emulate();
}

void recvData()
{
  while (Serial.available())
  {
    i=0;
    for (i = 0; i < 20; i++)
    {
      input[i] = Serial.read();
    }
  }
  input[20] = '#';
  newData = true;
}

void emulate()
{
  Serial.print("Emulating...");
  if (newData == true)
  {
    for (i = 0; i < 21; i++)
    {
      Serial.write(input[i]);
      switch (input[i])
      {
        case 1:
        digitalWrite (col1, HIGH);
        digitalWrite (col2, LOW);
        digitalWrite (col3, LOW);
        digitalWrite (row1, HIGH);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, LOW);
        break;
        
        case 2:
        digitalWrite (col1, LOW);
        digitalWrite (col2, HIGH);
        digitalWrite (col3, LOW);
        digitalWrite (row1, HIGH);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, LOW);
        break;
        
        case 3:
        digitalWrite (col1, LOW);
        digitalWrite (col2, LOW);
        digitalWrite (col3, HIGH);
        digitalWrite (row1, HIGH);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, LOW);
        break;
        
        case 4:
        digitalWrite (col1, HIGH);
        digitalWrite (col2, LOW);
        digitalWrite (col3, LOW);
        digitalWrite (row1, LOW);
        digitalWrite (row2, HIGH);
        digitalWrite (row3, LOW);
        digitalWrite (row4, LOW);
        break;
        
        case 5:
        digitalWrite (col1, LOW);
        digitalWrite (col2, HIGH);
        digitalWrite (col3, LOW);
        digitalWrite (row1, LOW);
        digitalWrite (row2, HIGH);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, LOW);
        break;
        
        case 6:
        digitalWrite (col1, LOW);
        digitalWrite (col2, LOW);
        digitalWrite (col3, HIGH);
        digitalWrite (row1, LOW);
        digitalWrite (row2, HIGH);
        digitalWrite (row3, LOW);
        digitalWrite (row4, LOW);
        break;
        
        case 7:
        digitalWrite (col1, HIGH);
        digitalWrite (col2, LOW);
        digitalWrite (col3, LOW);
        digitalWrite (row1, LOW);
        digitalWrite (row2, LOW);
        digitalWrite (row3, HIGH);
        digitalWrite (row4, LOW);
        break;
        
        case 8:
        digitalWrite (col1, LOW);
        digitalWrite (col2, HIGH);
        digitalWrite (col3, LOW);
        digitalWrite (row1, LOW);
        digitalWrite (row2, LOW);
        digitalWrite (row3, HIGH);
        digitalWrite (row4, LOW);
        break;
        
        case 9:
        digitalWrite (col1, LOW);
        digitalWrite (col2, LOW);
        digitalWrite (col3, HIGH);
        digitalWrite (row1, LOW);
        digitalWrite (row2, LOW);
        digitalWrite (row3, HIGH);
        digitalWrite (row4, LOW);
        break;
        
        case '*':
        digitalWrite (col1, HIGH);
        digitalWrite (col2, LOW);
        digitalWrite (col3, LOW);
        digitalWrite (row1, LOW);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, HIGH);
        break;
        
        case 0:
        digitalWrite (col1, LOW);
        digitalWrite (col2, HIGH);
        digitalWrite (col3, LOW);
        digitalWrite (row1, LOW);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, HIGH);
        break;
        
        case '#':
        digitalWrite (col1, LOW);
        digitalWrite (col2, LOW);
        digitalWrite (col3, HIGH);
        digitalWrite (row1, LOW);
        digitalWrite (row2, LOW);
        digitalWrite (row3, LOW);
        digitalWrite (row4, HIGH);
        break;
        
      }
      delay (10);
    }
    newData = false;
  }
}
    
