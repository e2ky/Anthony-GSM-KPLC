/*
    Arduino Uno Keypad Emulation
    By:- Kim
    Date: 19-06-2021
*/

char inChar;     // setup  for data storage

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
}

void recvData()
{
  while (Serial.available())
  {
    inChar = (char)Serial.read();     // get new byte
    emulate();
  }
}

void emulate()
{
  Serial.print("Emulating...");
  Serial.write(inChar);
  switch (inChar)
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
