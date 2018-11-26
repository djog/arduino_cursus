const int toon_hoogte_trig_pin = 13;
const int toon_hoogte_echo_pin = 12;

const int volume_trig_pin = 11;
const int volume_echo_pin = 10;

#include "Volume.h"

Volume vol; // Piezo in pin 5

void setup() 
{  
  pinMode(toon_hoogte_trig_pin, OUTPUT);
  pinMode(toon_hoogte_echo_pin, INPUT);
  pinMode(volume_trig_pin, OUTPUT);
  pinMode(volume_echo_pin, INPUT);
  vol.begin();
}

double meet_afstand_cm(const int trig_pin, const int echo_pin)
{
  digitalWrite(trig_pin, HIGH);
  vol.delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  const long tijdsduur_msec = pulseIn(echo_pin, HIGH);
  vol.delay(20);
  return 0.5 * tijdsduur_msec / 29.1;
}

void loop() 
{
  const double toon_hoogte_afstand_cm = meet_afstand_cm(
    toon_hoogte_trig_pin, 
    toon_hoogte_echo_pin
  );
  const double volume_afstand_cm = meet_afstand_cm(volume_trig_pin, volume_echo_pin);
  
  int toon_hoogte = 440;
  if (toon_hoogte_afstand_cm < 22.0) 
  { 
    toon_hoogte = 110.0 * pow(2.0, 4.0 * toon_hoogte_afstand_cm / 22.0); 
  }
  int volume = 0;
  if (volume_afstand_cm < 22.0) 
  { 
    volume = 255.0 * volume_afstand_cm / 22.0;
  }
  vol.tone(toon_hoogte, volume);
  vol.delay(10);
}


