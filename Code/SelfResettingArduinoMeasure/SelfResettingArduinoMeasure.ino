/*
Self Resetting Arduino measurement to determine the reset time
Inspired by Thijs van Beers' SelfResettingArduino

(C) 2015 Richel Bilderbeek

*/

/*

Connections

     +   
     |\  |
     | \ |
     |  \|    +-----+
AP---+ L +----+  R  +--- GND
     |  /|    +-----+
     | / |
     |/  |
     +   

AP: Arduino pin led_pin
L: LED (connect plus (the longer leg) to AP)
R: resistance, 1 kOhm (brown-black-red-gold)
GND: GND of Arduino

         +-----+
AP---+---+ PUR +--- 5V  
     |   +-----+
     |
     RP

AP: Arduino pin reset_pin
PR: Arduino pin RESET
PUR: resistance, 10 kOhm (brown-black-orange-gold)
5V: 5V of Arduino

Start experiment: 15:54:58
Eind experiment : 15:55:22
Totale duur: 24 seconden
Aantal knipperingen: 10x
Duur knippering: 2.4 sec per knippering
Duur reset = duur_knippering - duur_delay = 2.4 - 1.0 = 1.4

Een reset duurt dus 1.4 seconde

*/

const int led_pin = 6; //Pin to LED that measurement is busy
const int reset_pin = 8; //Connect this pin to a pull-up resistor and the reset pin

void setup()
{
  digitalWrite(reset_pin,HIGH);  //This line is first, so when the Arduino is reset it doesn't reset again untill it's told to
  pinMode(reset_pin,OUTPUT);     //Very important, without this line resetting won't work
  
  pinMode(led_pin,OUTPUT);
}

void loop()
{
  digitalWrite(led_pin,HIGH);
  delay(1000); //Tijd om reset pin erin te doen

  //Reset Arduino
  digitalWrite(reset_pin,LOW);
}
