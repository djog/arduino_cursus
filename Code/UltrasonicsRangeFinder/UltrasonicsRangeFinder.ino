const int sonar_trigger_pin = 2;
const int sonar_echo_pin = 3;
const int led_pin = 9;

double measure_distance_cm()
{
  // send the sensor a 10 microsecond pulse:
  digitalWrite(sonar_trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonar_trigger_pin, LOW);

  // wait for the pulse to return. The pulse
  // goes from low to HIGH to low, so we specify
  // that we want a HIGH-going pulse below:
  const int pulse_length_um = pulseIn(sonar_echo_pin, HIGH);

  // can't send more than one pulse each 50 ms or
  // we could get interference
  delay(50);

  // convert to centimeters and return
  return static_cast<double>(pulse_length_um) / 58.0;
}


void setup()
{
  pinMode(sonar_trigger_pin,OUTPUT);
  pinMode(sonar_echo_pin,INPUT);
  pinMode(led_pin,OUTPUT);
  //Serial.begin(9600);
}


void loop()
{
  const double current_distance_cm = measure_distance_cm();
  const int current_distance_mm = static_cast<int>(10.0 * current_distance_cm);
  //Serial.println(current_distance_mm);
  //delay(100);
  //analogWrite(led_pin,current_distance_mm);
  tone(led_pin,440.0 * (0.1 *current_distance_cm));
}
