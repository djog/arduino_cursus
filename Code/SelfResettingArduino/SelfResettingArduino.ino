/*
Self Resetting Arduino, an Arduino that will reset itself
Adapted from Thijs van Beers bu Richel Bilderbeek

(C) 2015 Thijs van Beers
*/

const int led_pin = 7;      //Connect led to this pin
const int reset_pin = 8;    //Connect this pin to a pull-up resistor and the reset pin
int countdown = 10;         //This will count down to the moment the Arduino will reset

/*
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

*/

void setup(){
  digitalWrite(reset_pin,HIGH);  //This line is first, so when the Arduino is reset it doesn't reset again untill it's told to
  pinMode(reset_pin,OUTPUT);     //Very important, without this line resetting won't work
  pinMode(led_pin,OUTPUT);       //
  Serial.begin(9600);        //Start the serial port
  
  digitalWrite(led_pin,HIGH);    //This long blink happens in the setup function,
  delay(1000);               //so if you see it you know your Arduino is reset
  digitalWrite(led_pin,LOW);
  delay(250);
}

void loop(){
  digitalWrite(led_pin,!digitalRead(led_pin));    //Write the led to the state it is not now, so HIGH when it's LOW and LOW when it's HIGH
  delay(250);
  Serial.println(countdown);              //Print the countdown to the serial monitor
  --countdown;                            //Count the countdown down
  
  if(countdown == 0){                     //When the countdown ended,
    digitalWrite(reset_pin,LOW);              //write the output pin connected to the reset pin LOW. This is the same as connecting it with ground, wich resets the Arduino.
  }
}
