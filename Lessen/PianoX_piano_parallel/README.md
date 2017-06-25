# Piano parallel


```c++
const int speaker_pin = 8;
const int toets_1_pin = A0;
const int toets_2_pin = A1;
const int toets_3_pin = A2;

void setup()
{
  pinMode(speaker_pin, OUTPUT);
  pinMode(toets_1_pin, INPUT);
  pinMode(toets_2_pin, INPUT);
  pinMode(toets_3_pin, INPUT);
}

void loop()
{
  const int toonlengte = 125;
  int toonhoogte = 0;
  if (digitalRead(toets_1_pin) == HIGH)
  {
    toonhoogte = 131;
  }
  else if (digitalRead(toets_2_pin) == HIGH)
  {
    toonhoogte = 147;
  }
  else if (digitalRead(toets_3_pin) == HIGH)
  {
    toonhoogte = 165;
  }
  tone(speaker_pin, toonhoogte, toonlengte);
  delay(toonlengte);
}
```