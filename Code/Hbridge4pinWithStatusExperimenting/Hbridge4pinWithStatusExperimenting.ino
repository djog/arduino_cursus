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
  digitalWrite(pin_1,(rand() >> 4) % 2 ? LOW : HIGH);
  digitalWrite(pin_2,(rand() >> 4) % 2 ? LOW : HIGH);
  digitalWrite(pin_3,(rand() >> 4) % 2 ? LOW : HIGH);
  digitalWrite(pin_4,(rand() >> 4) % 2 ? LOW : HIGH);

  delay(100);

}
