//  +-V_high -+
//  |         |
//  3         4
//  |         |
//  +---M-----+
//  |         |
//  1         2
//  |         |
//  +-V_low---+
//
// Route A
//
//  +-V_high -+
//            |
//            4
//            |
//  +---M-----+
//  |          
//  1          
//  |          
//  +-V_low---+
//
// Route A
//
//  +-V_high -+
//  |          
//  3          
//  |          
//  +---M-----+
//            |
//            2
//            |
//  +-V_low---+


const int pin_1 = 2;
const int pin_2 = 3;
const int pin_3 = 4;
const int pin_4 = 5;

void setup()
{
  pinMode(pin_1,OUTPUT);
  pinMode(pin_2,OUTPUT);
  pinMode(pin_3,OUTPUT);
  pinMode(pin_4,OUTPUT);
  
}

void loop()
{
  //The time between a change in current direction
  const int my_toggle_delay = 1000; //msec
  //Route A
  digitalWrite(pin_1,LOW);
  digitalWrite(pin_2,LOW);
  digitalWrite(pin_3,LOW);
  digitalWrite(pin_4,LOW);
  delay(50);
  digitalWrite(pin_1,HIGH);
  digitalWrite(pin_4,HIGH);

  delay(my_toggle_delay);
  
  //Route B
  digitalWrite(pin_1,LOW);
  digitalWrite(pin_2,LOW);
  digitalWrite(pin_3,LOW);
  digitalWrite(pin_4,LOW);
  delay(50);
  digitalWrite(pin_2,HIGH);
  digitalWrite(pin_3,HIGH);
  delay(my_toggle_delay);
}
