#ifndef RICHEL_PWM_LED_H
#define RICHEL_PWM_LED_H

bool IsPwmPin(const int pin);

struct PwmLed
{
  PwmLed(const int pin);
  int GetPin() const { return m_pin; }
  void SetBrightness(const int brightness);
  private:
  const int m_pin;
};

#endif // RICHEL_PWM_LED_H
