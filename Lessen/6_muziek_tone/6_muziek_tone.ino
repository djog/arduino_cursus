void setup()
{
  pinMode(8, OUTPUT);
}

void loop()
{
  tone(8, 440);
  delay(1000);
  noTone(8);
  tone(8, 880);
  delay(1000);
  noTone(8);
}