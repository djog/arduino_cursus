
const int pin_led = 13;

void setup()
{
  Serial.begin(9600); 
  pinMode(pin_led,OUTPUT);
}

void loop()
{
  while (Serial.available()) 
  {
    const byte s = Serial.read();
    digitalWrite(pin_led,s == 1 ? HIGH : LOW);
  }
  delay(100);
}
