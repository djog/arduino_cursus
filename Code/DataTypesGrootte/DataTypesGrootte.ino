void setup()
{
  Serial.begin(9600); 
  Serial.println("Datatype sizes (in bytes)");

  Serial.println("Hele getallen:");
  Serial.print("char: "); Serial.println(sizeof(char));
  Serial.print("signed char: "); Serial.println(sizeof(signed char));
  Serial.print("unsigned char: "); Serial.println(sizeof(unsigned char));

  Serial.print("short: "); Serial.println(sizeof(short));
  Serial.print("signed short: "); Serial.println(sizeof(signed short));
  Serial.print("unsigned short: "); Serial.println(sizeof(unsigned short));

  Serial.print("int: "); Serial.println(sizeof(int));
  Serial.print("signed int: "); Serial.println(sizeof(signed int));
  Serial.print("unsigned int: "); Serial.println(sizeof(unsigned int));
  Serial.print("long: "); Serial.println(sizeof(long));
  Serial.print("signed long: "); Serial.println(sizeof(signed long));
  Serial.print("unsigned long: "); Serial.println(sizeof(unsigned long));
  Serial.print("long long: "); Serial.println(sizeof(long long));
  Serial.print("signed long long: "); Serial.println(sizeof(signed long long));
  Serial.print("unsigned long long: "); Serial.println(sizeof(unsigned long long));

  Serial.println("Gebroken getallen:");
  Serial.print("double: "); Serial.println(sizeof(double));
  Serial.print("float: "); Serial.println(sizeof(float));
  Serial.print("long double: "); Serial.println(sizeof(long double));

  Serial.println("Karakters:");
  Serial.print("char: "); Serial.println(sizeof(char));
  Serial.print("byte: "); Serial.println(sizeof(byte));

  Serial.println("Booliaanse logica:");
  Serial.print("bool: "); Serial.println(sizeof(bool));
  Serial.print("boolean: "); Serial.println(sizeof(boolean));
}

void loop()
{
  
}
