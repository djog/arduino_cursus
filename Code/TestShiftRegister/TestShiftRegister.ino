class ShiftRegister
{
  public:
  //Constructor
  ShiftRegister(
    const int data_pin,
    const int latch_pin,
    const int clock_pin
  )
    : m_data_pin(data_pin),
      m_latch_pin(latch_pin),
      m_clock_pin(clock_pin),
      m_state(0)
  {
    pinMode(m_data_pin,OUTPUT);
    pinMode(m_latch_pin,OUTPUT);
    pinMode(m_clock_pin,OUTPUT);
    SetAlles(0);
  }
  bool Get(const int i)
  {
    //Als m_state == 01010101, dan bij Get(0) moet een 1
    //                ^  ^  ^
    //                |  |  +-- Get(0) op 85 moet 1 zijn
    //                |  +----- Get(3) op 85 moet 0 zijn
    //                +-------- Get(6) op 85 moet 1 zijn
    // Dit is 85 (1 + 4 + 16 + 64 = 85)
    //
    //Get(0): m_state & (1 << i) == m_state & (1 << 0) == m_state & 1
    // 01010101
    // 00000001
    // 00000001 == true 
    //
    //Get(3): m_state & (1 << i) == m_state & (1 << 3) == m_state & 8
    // 01010101: 85
    // 00001000: 8
    // 00000000: 0 == false
    //
    //Get(6): m_state & (1 << i) == m_state & (1 << 6) == m_state & 64
    // 01010101: 85
    // 01000000: 64 
    // 01000000: 64 == true
    
    return m_state & (1 << i); 
  }
  //Zet de losse pinnen (nummer 0 tot en met 7) aan en uit
  void SetLos(const int i, const bool new_state)
  {
    const bool current_state = Get(i);
    if (current_state == new_state) return;
    if (current_state == LOW)
    {
      m_state += (1 << i);
    } 
    else
    {
      m_state -= (1 << i);      
    }
    SetAlles(m_state);
  }
  //Zet alle pinnen tegelijk in een aan-uit-combinatie
  void SetAlles(const int getal)
  {
    // Stuur de data naar het shift register
    shiftOut(m_data_pin, m_clock_pin, MSBFIRST, getal);

    // Zet de latch aan en uit, zodat de outputs aan gaan
    digitalWrite(m_latch_pin, HIGH);
    digitalWrite(m_latch_pin, LOW);
  }
  //Knipper pin nummer 'pin_nummer', dit is een getal van nul tot en met zeven
  void Toggle(const int pin_nummer)
  {
    SetLos(pin_nummer,!Get(pin_nummer));
  }
  private: 
  const int m_data_pin;
  const int m_latch_pin;
  const int m_clock_pin;
  //m_state bevat de toestand van de lampjes:
  // - 0: alles uit
  // - 255: alles aan
  // - 1: het eerste lampje aan, op de nulde pin
  // - 2: het tweede lampje aan, op de volgende pin
  // - 3: het eerste en tweede lampje aan
  int m_state; 
};

const int datapin  = 2; 
const int latchpin = 3;
const int clockpin = 4;



void Test()
{
  Serial.println("Start test");
  ShiftRegister s(0,0,0); //Nonsense pinnen
  if (s.Get(0) != LOW) Serial.println("ERROR 1");
  s.SetLos(0,HIGH);
  s.SetLos(1,HIGH);
  if (s.Get(0) != HIGH) Serial.println("ERROR 2");
  if (s.Get(1) != HIGH) Serial.println("ERROR 3");
  if (s.Get(2) != LOW) Serial.println("ERROR 4");

  Serial.println("Test klaar");
}

ShiftRegister shift_register(datapin,latchpin,clockpin);

void setup()
{
  Serial.begin(9600);
  Test();
}

void loop()
{
  /*
  for (int i=0; i!=256; ++i)
  {
    shift_register.Set(i);
    delay(100);
  }
  */
  for (int i=0; i!=8; ++i)
  {
    shift_register.SetLos(i,HIGH);
    delay(1000);
  }
  for (int i=0; i!=8; ++i)
  {
    shift_register.SetLos(i,LOW);
    delay(1000);
  }

  /*
  for (int i=0; i!=8; ++i)
  {
    shift_register.Toggle(i);
    delay(1000);
  }
  */
  /*
  for (int i=0; i!=8; ++i)
  {
    shift_register.Set(i,HIGH);
    delay(1000);
    shift_register.Set(i,LOW);
  }
  */
  /*
  for (int i=0; i!=8; ++i)
  {
    shift_register.Set(i,rand() % 2 ? HIGH : LOW); 
  }
  delay(1000);
  */
}  
