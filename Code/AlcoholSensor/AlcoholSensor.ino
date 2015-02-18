void setup()
{
  Serial.begin(9600);
}
void loop()
{
  //Above bottle of whiskey: 
  // A: 817 | 774
  // D:  10 | 20

  //In air
  // A: 50
  // D: 888
  const int a = analogRead(A1);
  //const int d = analogRead(A2);
  Serial.println(a);
  //Serial.print(" ");
  //Serial.println(d);
  delay(1000); 
}
