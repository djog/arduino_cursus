const int pin_led_success = 13;
const int pin_led1 = A0; //The pin 13 of the student
const int pin_led2 = A1; //The pin 12 of the student

void setup()
{
  Serial.begin(9600);
  pinMode(pin_led_success,OUTPUT);
  pinMode(pin_led1,INPUT);
  pinMode(pin_led2,INPUT);
  Serial.println("Trial1 start");
}

// States:
// 0: led1 high, led2 low
// 1: led1 low, led2 high
// 2: as 0
// 3: as 1

//Returns if it was successfull
bool StateZero()
{
  int count = 0;
  while (digitalRead(pin_led1) == HIGH && digitalRead(pin_led2) == LOW)
  { 
    ++count;
    if (count == 13) 
    {
      Serial.println("Fail StateZero: lasted too long");
      return false;
    }
    delay(100);
  }
  if (count < 8)
  {    
    Serial.println("Fail StateZero: lasted too short");
    return false;
  }
  return true;  
}

//Returns if it was successfull
bool StateOne()
{
  int count = 0;
  while (digitalRead(pin_led1) == LOW && digitalRead(pin_led2) == HIGH)
  { 
    ++count;
    if (count == 13) 
    {
      Serial.println("Fail StateOne: lasted too long");
      return false;
    }
    delay(100);
  }
  if (count < 8)
  {    
    Serial.println("Fail StateOne: lasted too short");
    return false;
  }
  return true;  
}

// Both states must last approximately one second
void loop()
{
  if (digitalRead(pin_led1) == HIGH && digitalRead(pin_led2) == LOW)
  {
    Serial.println("0: Start StateZero");
    {
      const bool success = StateZero();
      if (!success) return;
    }
    Serial.println("1: Start StateOne");
    {
      const bool success = StateOne();
      if (!success) return;
    }
    Serial.println("2: Start StateZero");
    {
      const bool success = StateZero();
      if (!success) return;
    }
    Serial.println("3: Start StateOne");
    {
      const bool success = StateOne();
      if (!success) return;
    }
    //SUCCESS!
    digitalWrite(pin_led_success,HIGH);
  }
  delay(100);
}
