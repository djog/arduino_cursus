bool IsAnalogPin(const int pin)
{
  switch (pin)
  {
    case 0: 
    case 1: 
    case 2: 
    case 3: 
    case 4: 
    case 5: 
    case 6: 
    case 7: 
    case 8: 
    case 9: 
    case 10: 
    case 11: 
    case 12: 
    case 13: 
    case A0: 
    case A1: 
    case A2: 
    case A3: 
    case A4: 
    case A5: 
      return true;
    default:
      return false;
  }
}

struct DigitalLed
{
  DigitalLed(const int pin) : m_pin(pin) 
  {
    if (!IsAnalogPin(pin))
    {
      while (1) {Serial.println("Not an analog pin"); delay(1000); }
    }
    pinMode(m_pin,OUTPUT); 
  }
  int GetPin() const { return m_pin; }
  void TurnOff() { digitalWrite(m_pin,LOW); }
  void TurnOn() { digitalWrite(m_pin,HIGH); }
  private:
  const int m_pin;
};


void setup () {}

void loop()
{
  DigitalLed led(13);
  while (1)
  {
    led.TurnOn();
    delay(100); 
    led.TurnOff();
    delay(100); 
  }
}
