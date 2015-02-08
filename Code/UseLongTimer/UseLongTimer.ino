#include "LongTimer.h"


void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  LongTimer t;
  while (1)
  {
    t.Update();
    String s;
    s += (t.GetHours() % 24); 
    s += ":";
    s += (t.GetMins() % 60); 
    s += ":";
    s += (t.GetSecs() % 60); 
    s += ":";
    s += (t.GetMsecs() % 1000);
    Serial.println(s);
    delay(1234);
  }
}
