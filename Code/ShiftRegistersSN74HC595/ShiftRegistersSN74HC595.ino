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


Omschrijving chip SN74HC595:

 16 15 14 13 12 11 10 9
 |  |  |  |  |  |  |  |
 +--+--+--+--+--+--+--+
 |>                   |
 +--+--+--+--+--+--+--+
 |  |  |  |  |  |  |  |
 1  2  3  4  5  6  7  8

 Officiele pin namen:

 1: Q2
 2: Q3
 3: Q4
 3: Q5
 5: Q6
 6: Q7
 7: Q8 
 8: GND
 9: QH*: om te daisy chainen, anders ongebruikt
 10: SRCLR* (naar 5V)
 11: SRCLK (naar D4): clock pin
 12: RCLK (naar D3): latch pin
 13: OE* (naar GND)
 14: SER (naar D2): data pin
 15: Q1
 16: VCC (naar 5V)


Eerste shift register:

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
 9: naar pin 14 van het tweede shift register (dit is de daisy chain verbinding)
 10: naar 5V
 11: naar D4: clock pin
 12: naar D3: latch pin
 13: naar GND
 14: naar D2: data pin
 15: naar LED1
 16: naar 5V

Tweede shift register:

 16 15 14 13 12 11 10 9
 |  |  |  |  |  |  |  |
 +--+--+--+--+--+--+--+
 |>                   |
 +--+--+--+--+--+--+--+
 |  |  |  |  |  |  |  |
 1  2  3  4  5  6  7  8

 Verbindingen:

 1: LED 10
 2: LED 11
 3: LED 12
 3: LED 13
 5: LED 14
 6: LED 15
 7: LED 816
 8: GND
 9: wordt niet gebruikt
 10: naar 5V
 11: naar D4: clock pin
 12: naar D3: latch pin
 13: naar GND
 14: naar pin 9 van eerste shift register (dit is de daisy chain verbinding)
 15: naar LED 9
 16: naar 5V

*/

const int datapin  = 2;
const int latchpin = 3;
const int clockpin = 4;



void setup() 
{
  pinMode(latchpin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(datapin , OUTPUT);
}

void loop() 
{
  for (int i = 0; i!=65536; ++i) 
  {
    ShowBinary(i);
    delay(25);
  }
}

void ShowBinary(const int value) 
{
  //Start met schrijven
  digitalWrite(latchpin,LOW);

  //Bereken wat te schrijven
  // (dit moet in twee keer: een keer per shift register)
  const int high_value = value / 256;
  const int low_value  = value % 256;

  //Schrijf naar de shift registers
  //(opmerking: mocht je toch maar een shift register aansluiten,
  // dan wordt de high_value gewoon overschreven door de low_value,
  // oftewel: je ziet dan enkel de low_value)
  WriteToShiftRegister(high_value); 
  WriteToShiftRegister(low_value);

  //Klaar met schrijven
  digitalWrite(latchpin,HIGH);
}

void WriteToShiftRegister(const byte value) 
{
  // This shifts 8 bits out MSB first, 
  //on the rising edge of the clock,
  //clock idles low

  //prepare shift register for bit shifting
  digitalWrite(datapin, LOW);
  digitalWrite(clockpin, LOW);

  for (int i=7; i>=0; i--)  
  {
    digitalWrite(clockpin, 0);

    //if the value passed to myDataOut and a bitmask result 
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000 
    // and proceeds to set pinState to 1.
    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(datapin, value & (1<<i) ? HIGH : LOW);
    //register shifts bits on upstroke of clock pin  
    digitalWrite(clockpin, HIGH);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(datapin, LOW);
  }

  //stop shifting
  digitalWrite(clockpin, LOW);
}
