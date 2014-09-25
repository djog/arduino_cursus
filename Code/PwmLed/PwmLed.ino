#include <pwm_led.h>

void setup () {}

void loop()
{
  PwmLed led(11);
  for (int i=0; i!=256; ++i)
  {
    led.SetBrightness(i);
    delay(2); 
  }
  for (int i=0; i!=256; ++i)
  {
    led.SetBrightness(255-i);
    delay(2); 
  }
}
