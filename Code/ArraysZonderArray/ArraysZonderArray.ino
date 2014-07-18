const int pin_1  =  2;
const int pin_2  =  3;
const int pin_3  =  4;
const int pin_4  =  5;
const int pin_5  =  6;
const int pin_6  =  7;
const int pin_7  =  8;
const int pin_8  =  9;
const int pin_9  = 10;
const int pin_10 = 11;
const int pin_11 = 12;
const int pin_12 = 13;

void setup()
{
  pinMode(pin_1 ,OUTPUT); 
  pinMode(pin_2 ,OUTPUT); 
  pinMode(pin_3 ,OUTPUT); 
  pinMode(pin_4 ,OUTPUT); 
  pinMode(pin_5 ,OUTPUT); 
  pinMode(pin_6 ,OUTPUT); 
  pinMode(pin_7 ,OUTPUT); 
  pinMode(pin_8 ,OUTPUT); 
  pinMode(pin_9 ,OUTPUT); 
  pinMode(pin_10,OUTPUT); 
  pinMode(pin_11,OUTPUT); 
  pinMode(pin_12,OUTPUT); 
}

void loop()
{
  digitalWrite(pin_1 ,HIGH); 
  digitalWrite(pin_2 ,HIGH); 
  digitalWrite(pin_3 ,HIGH); 
  digitalWrite(pin_4 ,HIGH); 
  digitalWrite(pin_5 ,HIGH); 
  digitalWrite(pin_6 ,HIGH); 
  digitalWrite(pin_7 ,HIGH); 
  digitalWrite(pin_8 ,HIGH); 
  digitalWrite(pin_9 ,HIGH); 
  digitalWrite(pin_10,HIGH); 
  digitalWrite(pin_11,HIGH); 
  digitalWrite(pin_12,HIGH); 
  delay(1000);
  digitalWrite(pin_1 ,LOW); 
  digitalWrite(pin_2 ,LOW); 
  digitalWrite(pin_3 ,LOW); 
  digitalWrite(pin_4 ,LOW); 
  digitalWrite(pin_5 ,LOW); 
  digitalWrite(pin_6 ,LOW); 
  digitalWrite(pin_7 ,LOW); 
  digitalWrite(pin_8 ,LOW); 
  digitalWrite(pin_9 ,LOW); 
  digitalWrite(pin_10,LOW); 
  digitalWrite(pin_11,LOW); 
  digitalWrite(pin_12,LOW); 
  delay(1000);
}
