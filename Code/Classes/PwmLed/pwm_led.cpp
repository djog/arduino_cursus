#include "pwm_led.h"

#include <Arduino.h>

bool IsPwmPin(const int pin)
{
  switch (pin)
  {
    case 3: 
    case 5: 
    case 6: 
    case 9: 
    case 10: 
    case 11: 
      return true;
    default:
      return false;
  }
}

PwmLed::PwmLed(const int pin) 
  : m_pin(pin) 
{
  if (!IsPwmPin(pin))
  {
    while (1) {Serial.println("Not a PWM pin"); delay(1000); }
  }
  pinMode(m_pin,OUTPUT); 
}

void PwmLed::SetBrightness(const int brightness) 
{ 
  analogWrite(m_pin,brightness); 
}
