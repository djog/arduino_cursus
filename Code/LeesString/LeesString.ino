void setup() 
{
  Serial.begin(9600);
}

String lees_string()
{
  String s;
  s.reserve(200);
  while (Serial.available()) 
  {
    const char c = static_cast<char>(Serial.read()); 
    if (c == '\n') break; 
    s += c;
  }
  return s;
}
void loop() 
{
  const String s = lees_string();
  if (s.length() > 0) { Serial.println(s); }
  delay(1000);
}


