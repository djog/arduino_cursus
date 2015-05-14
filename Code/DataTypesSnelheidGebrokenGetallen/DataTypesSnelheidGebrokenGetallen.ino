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
  const int s0 = Test<float>();
  const double t1 = millis();  
  const int s1 = Test<double>();
  const double t2 = millis();  
  const int s2 = Test<long double>();
  const double t3 = millis();  
  
  const double t_float       = t1-t0;
  const double t_double      = t2-t1;
  const double t_long_double = t3-t2;

  Serial.println(s0);
  Serial.println(s1);
  Serial.println(s2);
  
  Serial.print("float: "); Serial.println(t_float);
  Serial.print("double: "); Serial.println(t_double);
  Serial.print("long double: "); Serial.println(t_long_double);

  Serial.print("float (per byte): "); Serial.println(t_float/sizeof(float));
  Serial.print("double (per byte): "); Serial.println(t_double/sizeof(double));
  Serial.print("long double (per byte): "); Serial.println(t_long_double/sizeof(long double));

  delay(1000);
}
