# Les 20: 1-pin-7-weerstanden-in-serie-piano




```c++
void setup()
{
  Serial.begin(9600);  
  pinMode(A0, INPUT);
}

void loop()
{
  Serial.println(analogRead(A0));
  delay(1000);
}

// 0
// 213
// 382
// 523
// 650
// 769
// 889
```