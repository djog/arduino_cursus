# SerialMonitor

## Keer Twee

```
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    const int getal{Serial.parseInt()};
    Serial.print("2 x ");
    Serial.print(getal);
    Serial.print(" = ");
    Serial.println(getal * 2);
    delay(100);
  }
}
```