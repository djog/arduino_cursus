void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    const int i = Serial.parseInt();
    Serial.print("Ik lees de int: ");
    Serial.println(i);
  }
  delay(100);
}


