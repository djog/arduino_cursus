int pin_rood = 9;

void setup()
{
  pinMode(pin_rood, OUTPUT);
}

void loop()
{
  for (int i = 0; i!=256; ++i)
  {
    analogWrite(pin_rood, i);
    delay(30);
  }
}