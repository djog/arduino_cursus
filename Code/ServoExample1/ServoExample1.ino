#include <Servo.h>

const int pin_servo = 2;

Servo servo;

void setup()
{
  servo.attach(pin_servo);    
}

void loop()
{
  servo.write(0);
  delay(1000);
  servo.write(180);
  delay(1000);
}
