/*
    Arduino Uno Keypad Emulation - Basic test

    Uses CD4051B Analog Multiplexer

    Both COM Pins (Pin 3) Connected

    CD4051B_1 ---> Rows (Channels 0-3)
    CD4051B_2 ---> Columns (Channels 0-2)

    CD4051B Truth Table
    _________________________________
    |                 |             |
    |Input States     |             |
    |-----------------| Channel ON  |
    |  C  |  B  |  A  |             |
    |-----|-----|-----|-------------|
    |  0  |  0  |  0  |      0      |
    |-----|-----|-----|-------------|
    |  0  |  0  |  1  |      1      |
    |-----|-----|-----|-------------|
    |  0  |  1  |  0  |      2      |
    |-----|-----|-----|-------------|
    |  0  |  1  |  1  |      3      |
    |-----|-----|-----|-------------|
    |  1  |  0  |  0  |      4      |
    |-----|-----|-----|-------------|
    |  1  |  0  |  1  |      5      |
    |-----|-----|-----|-------------|
    |  1  |  1  |  0  |      6      |
    |-----|-----|-----|-------------|
    |  1  |  1  |  1  |      7      |
    ---------------------------------

    Code Truth Table

    Legend: CD1 ---> Rows   e.g CD1 0 refers to Row 1
            CD2 ---> Columns  e.g CD2 0 refers to Column 1
    _________________________________________________________________________
    |                                               ||               ||     |
    |                 Input States                  ||  Channel ON   ||     |
    |-----------------------------------------------||---------------|| Key |
    | CD1_C | CD1_B | CD1_A | CD2_C | CD2_B | CD2_A ||  CD1  |  CD2  ||     |
    |-------|-------|-------|-------|-------|-------||-------|-------||-----|
    |   0   |   0   |   0   |   0   |   0   |   0   ||   0   |   0   ||  1  |
    |-------|-------|-------|-------|-------|-------||-------|-------||-----|
    |   0   |   0   |   0   |   0   |   0   |   1   ||   0   |   1   ||  2  |
    |-------|-------|-------|-------|-------|-------||-------|-------||-----|
    |   0   |   0   |   0   |   0   |   1   |   0   ||   0   |   2   ||  3  |
    |-------|-------|-------|-------|-------|-------||-------|-------||-----|
    |   0   |   0   |   1   |   0   |   0   |   0   ||   1   |   0   ||  4  |
    |-------|-------|-------|-------|-------|-------||-------|-------||-----|
    |   0   |   0   |   1   |   0   |   0   |   1   ||   1   |   1   ||  5  |
    |-------|-------|-------|-------|-------|-------||-------|-------||-----|
    |   0   |   0   |   1   |   0   |   1   |   0   ||   1   |   2   ||  6  |
    |-------|-------|-------|-------|-------|-------||-------|-------||-----|
    |   0   |   1   |   0   |   0   |   0   |   0   ||   2   |   0   ||  7  |
    |-------|-------|-------|-------|-------|-------||-------|-------||-----|
    |   0   |   1   |   0   |   0   |   0   |   1   ||   2   |   1   ||  8  |
    |-------|-------|-------|-------|-------|-------||-------|-------||-----|
    |   0   |   1   |   0   |   0   |   1   |   0   ||   2   |   2   ||  9  |
    |-------|-------|-------|-------|-------|-------||-------|-------||-----|
    |   0   |   1   |   1   |   0   |   0   |   0   ||   3   |   0   ||  *  |
    |-------|-------|-------|-------|-------|-------||-------|-------||-----|
    |   0   |   1   |   1   |   0   |   0   |   1   ||   3   |   1   ||  0  |
    |-------|-------|-------|-------|-------|-------||-------|-------||-----|
    |   0   |   1   |   1   |   0   |   1   |   0   ||   3   |   2   ||  #  |
    -------------------------------------------------------------------------


    By:- Kim
    Date: 08-07-2021
*/

int inChar;     // setup for data storage

int cd1_a = 2;
int cd1_b = 3;
int cd1_c = 4;
int cd2_a = 5;
int cd2_b = 6;
int cd2_c = 7;

void setup()
{
  Serial.begin(9600);

  Serial.println("Initializing...");
  delay(1000);

  // set all pins as outputs
  pinMode (cd1_a, OUTPUT);
  pinMode (cd1_b, OUTPUT);
  pinMode (cd1_c, OUTPUT);
  pinMode (cd2_a, OUTPUT);
  pinMode (cd2_b, OUTPUT);
  pinMode (cd2_c, OUTPUT);

}

void loop()
{
  inChar = 0;
  recvData();
}

void recvData()
{
  while (inChar < 10)
  {
    emulate();
    delay (500);
    key_release ();
    delay(500);
    inChar ++;
  }


}

void emulate()
{
  Serial.println("Emulating...");
  Serial.println(inChar);
  switch (inChar)
  {
    case 1:
      digitalWrite (cd1_a, LOW);
      digitalWrite (cd1_b, LOW);
      digitalWrite (cd1_c, LOW);
      digitalWrite (cd2_a, LOW);
      digitalWrite (cd2_b, LOW);
      digitalWrite (cd2_c, LOW);
      break;

    case 2:
      digitalWrite (cd1_a, LOW);
      digitalWrite (cd1_b, LOW);
      digitalWrite (cd1_c, LOW);
      digitalWrite (cd2_a, HIGH);
      digitalWrite (cd2_b, LOW);
      digitalWrite (cd2_c, LOW);
      break;

    case 3:
      digitalWrite (cd1_a, LOW);
      digitalWrite (cd1_b, LOW);
      digitalWrite (cd1_c, LOW);
      digitalWrite (cd2_a, LOW);
      digitalWrite (cd2_b, HIGH);
      digitalWrite (cd2_c, LOW);
      break;

    case 4:
      digitalWrite (cd1_a, HIGH);
      digitalWrite (cd1_b, LOW);
      digitalWrite (cd1_c, LOW);
      digitalWrite (cd2_a, LOW);
      digitalWrite (cd2_b, LOW);
      digitalWrite (cd2_c, LOW);
      break;

    case 5:
      digitalWrite (cd1_a, HIGH);
      digitalWrite (cd1_b, LOW);
      digitalWrite (cd1_c, LOW);
      digitalWrite (cd2_a, HIGH);
      digitalWrite (cd2_b, LOW);
      digitalWrite (cd2_c, LOW);
      break;

    case 6:
      digitalWrite (cd1_a, HIGH);
      digitalWrite (cd1_b, LOW);
      digitalWrite (cd1_c, LOW);
      digitalWrite (cd2_a, LOW);
      digitalWrite (cd2_b, HIGH);
      digitalWrite (cd2_c, LOW);
      break;

    case 7:
      digitalWrite (cd1_a, LOW);
      digitalWrite (cd1_b, HIGH);
      digitalWrite (cd1_c, LOW);
      digitalWrite (cd2_a, LOW);
      digitalWrite (cd2_b, LOW);
      digitalWrite (cd2_c, LOW);
      break;

    case 8:
      digitalWrite (cd1_a, LOW);
      digitalWrite (cd1_b, HIGH);
      digitalWrite (cd1_c, LOW);
      digitalWrite (cd2_a, HIGH);
      digitalWrite (cd2_b, LOW);
      digitalWrite (cd2_c, LOW);
      break;

    case 9:
      digitalWrite (cd1_a, LOW);
      digitalWrite (cd1_b, HIGH);
      digitalWrite (cd1_c, LOW);
      digitalWrite (cd2_a, LOW);
      digitalWrite (cd2_b, HIGH);
      digitalWrite (cd2_c, LOW);
      break;

    case '*':
      digitalWrite (cd1_a, HIGH);
      digitalWrite (cd1_b, HIGH);
      digitalWrite (cd1_c, LOW);
      digitalWrite (cd2_a, LOW);
      digitalWrite (cd2_b, LOW);
      digitalWrite (cd2_c, LOW);
      break;

    case 0:
      digitalWrite (cd1_a, HIGH);
      digitalWrite (cd1_b, HIGH);
      digitalWrite (cd1_c, LOW);
      digitalWrite (cd2_a, HIGH);
      digitalWrite (cd2_b, LOW);
      digitalWrite (cd2_c, LOW);
      break;

    case '#':
      digitalWrite (cd1_a, HIGH);
      digitalWrite (cd1_b, HIGH);
      digitalWrite (cd1_c, LOW);
      digitalWrite (cd2_a, LOW);
      digitalWrite (cd2_b, HIGH);
      digitalWrite (cd2_c, LOW);
      break;
      
    default:
      recvData();


  }

}


void key_release()
{
  digitalWrite (cd1_a, HIGH);
  digitalWrite (cd1_b, HIGH);
  digitalWrite (cd1_c, HIGH);
  digitalWrite (cd2_a, HIGH);
  digitalWrite (cd2_b, HIGH);
  digitalWrite (cd2_c, HIGH);
}
