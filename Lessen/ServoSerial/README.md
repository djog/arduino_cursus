# ServoSerial

Je kunt een servo motor met de seriele monitor aansturen.

Bijvoorbeeld met deze code:

```
#include <Servo.h>

Servo mijn_servo;

void setup()
{
  Serial.begin(9600);
  mijn_servo.attach(9);
}

void loop()
{
  if (Serial.available())
  {
    const int getal{Serial.parseInt()};
    Serial.print("Ik zet de servo op ");
    Serial.println(getal);
    mijn_servo.write(getal);
    delay(1000);
  }
}
```

