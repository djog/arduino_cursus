template <class T>
int Test()
{
  const int sz = 150; //Arraygrootte
  const int r = 1000; //Aantal herhalingen
  T v[sz];
  T sum = 0;
  for (int j=0; j!=r; ++j)
  {
    for (int i=0; i!=sz; ++i)
    {
      ++v[i];
      sum += v[i];
    }
  }
  return sum;
}

void setup()
{
  Serial.begin(9600); 
}

void loop()
{
  const double t0 = millis();  
  const int s0 = Test<char>();
  const double t1 = millis();  
  const int s1 = Test<short>();
  const double t2 = millis();  
  const int s2 = Test<int>();
  const double t3 = millis();  
  const int s3 = Test<long>();
  const double t4 = millis();  
  const int s4 = Test<long long>();
  const double t5 = millis();  
  
  const double t_char      = t1-t0;
  const double t_short     = t2-t1;
  const double t_int       = t3-t2;
  const double t_long      = t4-t3;
  const double t_long_long = t5-t4;

  Serial.println(s0);
  Serial.println(s1);
  Serial.println(s2);
  Serial.println(s3);
  Serial.println(s4);
  
  Serial.print("char: "); Serial.println(t_char);
  Serial.print("short: "); Serial.println(t_short);
  Serial.print("int: "); Serial.println(t_int);
  Serial.print("long: "); Serial.println(t_long);
  Serial.print("long long: "); Serial.println(t_long_long);

  Serial.print("char (per byte): "); Serial.println(t_char/sizeof(char));
  Serial.print("short (per byte): "); Serial.println(t_short/sizeof(short));
  Serial.print("int (per byte): "); Serial.println(t_int/sizeof(int));
  Serial.print("long (per byte): "); Serial.println(t_long/sizeof(long));
  Serial.print("long long (per byte): "); Serial.println(t_long_long/sizeof(long long));

  delay(1000);
}
