#include "mijn_header.h"

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  const int getal = analogRead(A0);
  const double spanning = NaarVoltage(getal);
  Serial.println(spanning);
  delay(10);
}
