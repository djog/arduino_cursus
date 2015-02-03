/*
  Shift Register SN74HC595 voorbeeldcode 1
  (C) 2015 Richel Bilderbeek

  Aangepast van onderstaand:
*/
/*
SparkFun Inventor's Kit Galileo
Example sketch 13

SHIFT REGISTER

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

Version 2.0 6/2012 MDG
*/
/*

Omschrijving chip en verbindingen:

 16 15 14 13 12 11 10 9
 |  |  |  |  |  |  |  |
 +--+--+--+--+--+--+--+
 |>                   |
 +--+--+--+--+--+--+--+
 |  |  |  |  |  |  |  |
 1  2  3  4  5  6  7  8

 Verbindingen:

 1: LED 2
 2: LED 3
 3: LED 4
 3: LED 5
 5: LED 6
 6: LED 7
 7: LED 8 
 8: GND
 9: wordt niet gebruikt
 10: naar 5V
 11: naar D4: clock pin
 12: naar D3: latch pin
 13: naar GND
 14: naar D2: data pin
 15: naar LED1
 16: naar 5V

 Officiele pin namen:

 1: Q2
 2: Q3
 3: Q4
 3: Q5
 5: Q6
 6: Q7
 7: Q8 
 8: GND
 9: QH* (wordt niet gebruikt)
 10: SRCLR* (naar 5V)
 11: SRCLK (naar D4): clock pin
 12: RCLK (naar D3): latch pin
 13: OE* (naar GND)
 14: SER (naar D2): data pin
 15: Q1
 16: VCC (naar 5V)

*/

const int datapin  = 2; 
const int latchpin = 3;
const int clockpin = 4;

void setup()
{
  pinMode(datapin,  OUTPUT);
  pinMode(latchpin, OUTPUT);
  pinMode(clockpin, OUTPUT);  
}


void loop()
{
  for (int i=0; i!=256; ++i)
  {
    //Laat het getal i als binair zien
    ShowBinary(i);
    delay(100);
  }
}


void ShowBinary(const int getal)
{
  // Stuur de data naar het shift register
  shiftOut(datapin, clockpin, MSBFIRST, getal);

  // Zet de latch aan en uit, zodat de outputs aan gaan
  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}

