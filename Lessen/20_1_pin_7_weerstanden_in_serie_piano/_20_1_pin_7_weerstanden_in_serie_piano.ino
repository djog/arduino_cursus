const int speaker_pin = 8;
const int piano_pin = A0;

void setup()
{
  Serial.begin(9600);  
  pinMode(A0, INPUT);
}

void loop()
{
  const int piano_waarde = analogRead(piano_pin);
  Serial.println(piano_waarde);
  if (piano_waarde < 150)
  {
    tone(speaker_pin, 175, 250);
    delay(250);
  }
  else if (piano_waarde < 300)
  {
    tone(speaker_pin, 196, 250);
    delay(250);
  }
  else if (piano_waarde < 450)
  {
    tone(speaker_pin, 220, 250);
    delay(250);
  }
  else if (piano_waarde < 600)
  {
    tone(speaker_pin, 247, 250);
    delay(250);
  }
  else if (piano_waarde < 700)
  {
    tone(speaker_pin, 262, 250);
    delay(250);
  }
  else if (piano_waarde < 800)
  {
    tone(speaker_pin, 294, 250);
    delay(250);
  }
  else if (piano_waarde < 950)
  {
    tone(speaker_pin, 330, 250);
    delay(250);
  }
  delay(1);
}
