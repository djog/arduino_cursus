
```
int knopPin = 2;
int ledPin = 13;
int toestandKnop = 0;
int geel = 12;
int groen = 10;
int rood = 8;

void setup() {
pinMode(ledPin, OUTPUT);
pinMode(knopPin, INPUT);
pinMode(geel, OUTPUT);
pinMode(groen, OUTPUT);
pinMode(rood,OUTPUT);
}

void loop() {
toestandKnop = digitalRead(knopPin);
if (toestandKnop == HIGH) {
 // delay(10000);
  digitalWrite(ledPin, LOW);
digitalWrite(geel, HIGH);
digitalWrite(groen, HIGH);
digitalWrite(rood, LOW);
}


else {

  digitalWrite(ledPin, HIGH);
digitalWrite(groen, LOW);
 digitalWrite(geel, LOW);
  digitalWrite(rood, HIGH);
  }
}

```
