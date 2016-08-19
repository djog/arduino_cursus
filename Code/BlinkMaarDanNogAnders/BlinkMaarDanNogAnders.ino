void setup() {
  pinMode(13,OUTPUT);
}

void loop() {
  digitalWrite(13, (millis()/1000)%2);
}
