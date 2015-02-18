#include <Servo.h>

const int pin_servo = 2;

Servo servo;

const int n = 80;

void setup()
{
  servo.attach(pin_servo);    

  servo.write(n);
  delay(1000);
}

void loop()
{
  servo.write(n-5);
  delay(200);
  servo.write(n);
  delay(1000);
  servo.write(n+5);
  delay(200);
  servo.write(n);
  delay(1000);
}
