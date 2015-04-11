void setup()
{
  Serial.begin(9600); 
}

void loop()
{
  Serial.print("HIGH"); //Geen println!
  delay(1000);
  Serial.print("LOW"); //Geen println!
  delay(1000);
}
