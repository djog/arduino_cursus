int GetMaxChar()
{
  unsigned char c = -1; //Hoogste unsigned waarde
  c /= 2; //Hoogste signed waarde
  const int d = c; //Conversie
  return d;
}

int GetMaxInt()
{
  unsigned int c = -1; //Hoogste unsigned waarde
  c /= 2; //Hoogste signed waarde
  const int d = c; //Conversie
  return d;
}

long GetMaxLong()
{
  unsigned long c = -1; //Hoogste unsigned waarde
  c /= 2; //Hoogste signed waarde
  const long d = c; //Conversie
  return d;
}

long long GetMaxLongLong()
{
  unsigned long long c = -1; //Hoogste unsigned waarde
  c /= 2; //Hoogste signed waarde
  const long long d = c; //Conversie
  return d;
}

void setup()
{
  Serial.begin(9600); 

  Serial.print("char: "); Serial.println(GetMaxChar());
  Serial.print("int: "); Serial.println(GetMaxInt());
  Serial.print("long: "); Serial.println(GetMaxLong());

  //Serial::println kan nog geen long long laten zien
  //Daarom check ik of de variabele max_long_long gelijk is aan GetMaxLongLong(),
  //zodat ik die waarde als String kan copy-pasten
  const long long max_long_long = 9223372036854775807ll;
  if (max_long_long == GetMaxLongLong())
  {
    Serial.print("long long: 9223372036854775807");
  }
}

void loop()
{
  
}
