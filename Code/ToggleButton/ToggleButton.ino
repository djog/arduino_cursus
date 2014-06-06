///Connections:
///A0 -> LED -> Resistance -> GND
///GND -> Switch -> A0

///ToggleButton changes state after a certain time
struct ToggleButton
{
  ToggleButton(const int pin, const bool initial_state = true, const int delay_msec = 500)
    : m_current_state(initial_state), 
      m_delay_msec(delay_msec),
      m_last_time_msec(0), 
      m_pin(pin)
  {
    pinMode(m_pin, INPUT_PULLUP);
  }
  void Update()
  {
    const bool pressed = !digitalRead(m_pin); //Use of operator!, because it is a pull-up switch
    if (!pressed) 
    {
      m_last_time_msec = 0;
      return;
    }
    if (m_last_time_msec == 0) 
    { 
      m_last_time_msec = millis(); 
      return;
    }
    if (millis() - m_last_time_msec > m_delay_msec) 
    {
      m_current_state = !m_current_state;
      m_last_time_msec = 0;
    }
  }
  bool IsOn() const { return m_current_state; }
  private:
  bool m_current_state;
  const int m_delay_msec;
  int m_last_time_msec;
  const int m_pin;
};

void setup() 
{
  const int led_pin = 11;
  const int button_pin = A0;
  const bool is_on_at_start = true;
  const int delay_msec = 500;
  pinMode(led_pin, OUTPUT);
  ToggleButton button(button_pin,is_on_at_start,delay_msec);
  while (1)
  {
    button.Update();
    digitalWrite(led_pin,button.IsOn());
    
    //No need for a delay :-)
    //delay(10);
  }
}

void loop() 
{ 
  //No need from loop :-)
}

