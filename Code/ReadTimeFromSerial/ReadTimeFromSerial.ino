void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if (!Serial.available()) { delay(100); return; }
  const int h = Serial.available() ? Serial.parseInt() : 0;
  const char c1 = Serial.available() ? Serial.read() : ':';
  const int m = Serial.available() ? Serial.parseInt() : 0;
  const char c2 = Serial.available() ? Serial.read() : ':';
  const int s = Serial.available() ? Serial.parseInt() : 0;
  Serial.print(h*2);
  Serial.print(c1);
  Serial.print(m*2);
  Serial.print(c2);
  Serial.println(s*2);
}








