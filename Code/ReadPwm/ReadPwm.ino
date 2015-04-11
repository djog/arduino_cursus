const int pin_led = 9;
const int pin_read = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(pin_read,INPUT);
  pinMode(pin_led,OUTPUT);
} 

/*
 The frequency of the PWM signal on most pins is approximately 490 Hz. On the Uno and similar boards, pins 5 and 6 have a frequency of approximately 980 Hz
*/
int GetPwm(const int pin_read)
{
  const int dist_micro_sec_int = pulseIn(pin_read,HIGH,1000);
  Serial.println(String("dist_micro_sec_int: ") + String(dist_micro_sec_int)); 
  if (dist_micro_sec_int == 0){
    if(digitalRead(pin_read) == LOW) return 0;
    else if(digitalRead(pin_read) == HIGH) return 255;
  }
  const double dist_micro_sec = static_cast<double>(dist_micro_sec_int);
  Serial.print("dist_micro_sec: "); 
  Serial.println(dist_micro_sec); //10 digits
  const double period_micro_sec = (1.0 / 490.0) * (1000.0 * 1000.0); //microsecond
  Serial.print("period_micro_sec: "); //10 digits
  Serial.println(period_micro_sec,10); 
  const double f = dist_micro_sec / period_micro_sec * 1.151; //compensate for rounding fault
  Serial.print("f: "); 
  Serial.println(f); 
  const double pwm = f * 255.0;
  Serial.print("pwm: "); 
  Serial.println(pwm); 
  return static_cast<int>(pwm);
}

void loop()
{
  //const int pwm = random(255);
  const int pwm = 254;
  analogWrite(pin_led,pwm);
  delay(100);
  const int pwm_measured = GetPwm(pin_read);
  Serial.println(String(pwm) + " " + String(pwm_measured)); 
  delay(1000);
}
