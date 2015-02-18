void setup()
{
  Serial.begin(9600);
}
void loop()
{
  //Air 
  // A: 

  //Breath
  // A: 211
  const int a = 1023 - analogRead(A1);
  //const int d = analogRead(A2);
  Serial.println(a);
  //Serial.print(" ");
  //Serial.println(d);
  delay(1000); 
}
