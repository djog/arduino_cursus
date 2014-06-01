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

struct PwmLed
{
  PwmLed(const int pin) : m_pin(pin) 
  {
    if (!IsPwmPin(pin))
    {
      while (1) {Serial.println("Not a PWM pin"); delay(1000); }
    }
    pinMode(m_pin,OUTPUT); 
  }
  int GetPin() const { return m_pin; }
  void SetBrightness(const int brightness) { analogWrite(m_pin,brightness); }
  private:
  const int m_pin;
};


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
