# Chatroom

Met dit project kun je chatten met je buren.

## Stroomschema

Sluit zoveel Arduino's aan in een cirkel als volgt:

![Stroomschema](SoftwareSerialChatRoom.png)

## Code

```
/*
Van links ontvang je 

A0: TX (verbind met 2 van je linkerbuur)
A1: RX (verbind met 3 van je linkerbuur)
 
Naar rechts stuur je

2: RX (verbind met A0 van je rechterbuur)
3: TX (verbind met A1 van je rechterbuur)
*/

#include <SoftwareSerial.h>

SoftwareSerial links(A1,A0); // RX, TX
SoftwareSerial rechts(2,3);  // RX, TX

void setup()  
{
  Serial.begin(9600);
  links.begin(9600);
  rechts.begin(9600);
  pinMode(8, OUTPUT);
}

String LeesLinks()
{
  String s;
  while (links.available())
  {
    s += static_cast<char>(links.read());
  }
  return s;  
}

String LeesSerial()
{
  String s;
  while (Serial.available())
  {
    s += static_cast<char>(Serial.read());
  }
  return s;
}








void loop()
{
  //Luister of links wat te 
  links.listen();
  //Geef boodschap van links door
  if (links.available())
  {
    const String s = LeesLinks();
    Serial.print("Ik lees van links: ");
    Serial.println(s);
    if (s.length() > 1)
    {
      Serial.print("Ik stuur door naar rechts: ");
      const String t 
        = s.substring(0,s.length() - 1);
      Serial.println(t);
      rechts.print(t); 
    }
    delay(100);
  }
  //Geef eigen boodschap door
  if (Serial.available())
  {
    const String s = LeesSerial();
    Serial.print(
      "Ik lees van de seriele monitor: ");
    Serial.println(s);
    rechts.print(s); 
    delay(100);
  }
  delay(100);
}
```