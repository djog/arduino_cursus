/*

EEPROM lezen, programma om de EEPROM te lezen

(C) 2015 Richel Bilderbeek

*/

#include <EEPROM.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //De EEPROM heeft 512 adressen (van nul tot en met 511)
  for (int adres = 0; adres != 512; ++adres)
  {
    const byte waarde = EEPROM.read(adres);
    Serial.print(adres);
    Serial.print(": ");
    Serial.println(waarde, DEC);
    delay(500);
  }
}
