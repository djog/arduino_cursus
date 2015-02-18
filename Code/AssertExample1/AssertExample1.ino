//#include "main.h"

#include <Arduino.h>
//#include "main.h"
#include "arduinoassert.h"

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Assert(1==2);
}
