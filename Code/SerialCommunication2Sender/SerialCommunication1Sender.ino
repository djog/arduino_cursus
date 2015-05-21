void setup()
{
  Serial.begin(9600); 
}

void loop()
{
  Serial.write(1); //Geen println!
  delay(100);
  Serial.write(0); //Geen println!
  delay(100);
}
