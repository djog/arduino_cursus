#include <Servo.h>

const int pin_servo = 2;
const int pin_input = A0;

Servo servo;

const int n = 80;

void setup()
{
  pinMode(pin_input,INPUT);
  servo.attach(pin_servo);    

  servo.write(n);
  delay(1000);
  
  Serial.begin(9600);
}

void loop()
{
  const int input = analogRead(pin_input);
  Serial.println(input);
  if (input < 100)
  {  
    servo.write(n-5);
    delay(200);
    servo.write(n);
    delay(1000);
  }
  else if (input > 600)
  {
    servo.write(n+5);
    delay(200);
    servo.write(n);
    delay(1000);
  }
  
}
