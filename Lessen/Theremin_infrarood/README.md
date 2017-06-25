# Theremin met infrarode afstandssensor

```c++
const int sensor_pin = A0;
const int piezo_pin = 8;

void setup()
{
  pinMode(piezo_pin, OUTPUT);
  pinMode(sensor_pin, INPUT); 
  Serial.begin(9600);
}

void loop()
{
  const int sensor_waarde = analogRead(sensor_pin);
  Serial.println(sensor_waarde);
  tone(piezo_pin, sensor_waarde, 10);
  delay(10);
}
```