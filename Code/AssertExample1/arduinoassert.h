#ifndef ARDUINOASSERT_H
#define ARDUINOASSERT_H

//Version 1.0

//From http://www.richelbilderbeek.nl/CppAssert.htm
#ifdef NDEBUG
  #define Assert(x) ((void)0)
#else
  #include <Arduino.h>
  //#include <Serial.h>
  #define Assert(x)                     \
  if (!(x))                             \
  {                                     \
    Serial.print("ERROR!!\n");          \
    Serial.print("Assertion failed\n"); \
    Serial.print(#x);                   \
    delay(10000);                       \
    exit(1);                            \
  }
#endif

#endif // ARDUINOASSERT_H

//Version history:
// - 2013-01-17: version 1.0: initial version
