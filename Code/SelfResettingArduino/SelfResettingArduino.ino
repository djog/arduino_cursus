/*
Self Resetting Arduino; an Arduino that will reset itself (duh!).
(C) 2015 Thijs van Beers
*/

const int led = 7;      //Connect led to pin 7 
const int reset = 8;    //Connect pin 8 to a pull-up resistor and the reset pin
int countdown = 10;     //This will count down to the moment the Arduino will reset

void setup(){
  digitalWrite(reset,HIGH);  //This line is first, so when the Arduino is reset it doesn't reset again untill it's told to
  pinMode(reset,OUTPUT);     //Very important, without this line resetting won't work
  pinMode(led,OUTPUT);       //
  Serial.begin(9600);        //Start the serial port
  
  digitalWrite(led,HIGH);    //This long blink happens in the setup function,
  delay(1000);               //so if you see it you know your Arduino is reset
  digitalWrite(led,LOW);
  delay(250);
}

void loop(){
  digitalWrite(led,!digitalRead(led));    //Write the led to the state it is not now, so HIGH when it's LOW and LOW when it's HIGH
  delay(250);
  Serial.println(countdown);              //Print the countdown to the serial monitor
  --countdown;                            //Count the countdown down
  
  if(countdown == 0){                     //When the countdown ended,
    digitalWrite(reset,LOW);              //write the output pin connected to the reset pin LOW. This is the same as connecting it with ground, wich resets the Arduino.
  }
}
