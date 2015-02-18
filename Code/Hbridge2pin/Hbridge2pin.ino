const int pin_a = 2;
const int pin_b = 3;

void setup()
{
  pinMode(pin_a,OUTPUT);
  pinMode(pin_b,OUTPUT);
}

void loop()
{
  //Standby
  {
    digitalWrite(pin_a,LOW);
    digitalWrite(pin_b,LOW);
    delay(50);
  }
  //From a to b
  {
    digitalWrite(pin_a,LOW);
    digitalWrite(pin_b,HIGH);
    delay(1000);
  }
  //Standby
  {
    digitalWrite(pin_a,LOW);
    digitalWrite(pin_b,LOW);
    delay(50);
  }
  //From b to a
  {
    digitalWrite(pin_b,LOW);
    digitalWrite(pin_a,HIGH);
    delay(1000);
  }
}
