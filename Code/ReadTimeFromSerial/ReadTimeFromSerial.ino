void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  const int h = Serial.available() ? Serial.parseInt() : 0;
  const char c1 = Serial.available() ? Serial.read() : ',';
  const int m = Serial.available() ? Serial.parseInt() : 0;
  Serial.print(h);
  Serial.print(c1);
  Serial.println(m);
  delay(1000);
}








