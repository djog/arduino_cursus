const int pin_led = 13;

void setup()
{
  Serial.begin(9600); 
  pinMode(pin_led,OUTPUT);
}

void loop()
{
  String s;
  while (Serial.available()) 
  {
    s += static_cast<char>(Serial.read());
    delay(1);
  }
  if (s.length() == 0) return;
  if (s == "HIGH")
  { 
    digitalWrite(pin_led,HIGH);
  }
  else if (s == "LOW")
  { 
    digitalWrite(pin_led,LOW);
  }
  else
  {
    //Pech gehad!
  }
  delay(1000);
}
