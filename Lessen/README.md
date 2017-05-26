```
const int trig_pin = 9;
const int echo_pin = 10;
const int piezo_pin = 7;

void setup()
{
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT); 
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig_pin, LOW);
  
  const long duration = pulseIn(echo_pin, HIGH);
  //const int distance = duration * 0.034 / 2;
  Serial.println(duration);
  tone(piezo_pin, duration, 10);
  delay(10);
}
```