const int pin_a = 2;
const int pin_b = 3;
const int pin_c = 4;
const int pin_d = 5;

void setup()
{
  pinMode(pin_a,OUTPUT);
  pinMode(pin_b,OUTPUT);
  pinMode(pin_c,OUTPUT);
  pinMode(pin_d,OUTPUT);
}

void loop()
{
  //From a to b
  {
    digitalWrite(pin_b,LOW);
    digitalWrite(pin_d,LOW);
    digitalWrite(pin_a,HIGH);
    digitalWrite(pin_c,HIGH);
    delay(1000);
  }
   //From b to a 
  {
    digitalWrite(pin_a,LOW);
    digitalWrite(pin_c,LOW);
    digitalWrite(pin_b,HIGH);
    digitalWrite(pin_d,HIGH);
    delay(1000);
  }
}
