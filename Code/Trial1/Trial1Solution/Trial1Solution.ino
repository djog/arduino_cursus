const int pin_led1 = 13;
const int pin_led2 = 12;

void setup()
{
  pinMode(pin_led1,OUTPUT);
  pinMode(pin_led2,OUTPUT);
}

void loop()
{
  digitalWrite(pin_led1,HIGH); 
  digitalWrite(pin_led2,LOW); 
  delay(1000);
  digitalWrite(pin_led1,LOW); 
  digitalWrite(pin_led2,HIGH); 
  delay(1000);
}
