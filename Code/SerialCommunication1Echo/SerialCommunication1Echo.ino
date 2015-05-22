void setup() {
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()){
    Serial.write(Serial.read());
  }
}
