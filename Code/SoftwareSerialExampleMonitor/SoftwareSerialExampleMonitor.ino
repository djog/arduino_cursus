/*
 Software serial multple serial test
 
 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.
 
 The circuit: 
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 
*/
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup()  
{
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() // run over and over
{
  bool changed = false;
  while (mySerial.available())
  {
    Serial.write(mySerial.read());
    changed = true;
  }
  if (changed) { Serial.print('\n'); }
  while (Serial.available()){
    mySerial.write(Serial.read());
  }
}

