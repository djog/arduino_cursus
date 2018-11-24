# Les 21: Theremin met potmeters

```c++
#include "Volume.h"

Volume vol; // Piezo in pin 5

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  vol.begin();
}

void loop()
{
  const int input_toon_hoogte = analogRead(A0);
  const int input_volume = analogRead(A1);
  const int toon_hoogte = 110 * pow(2.0, 0.002 * input_toon_hoogte);
  const int volume = 1.0 * pow(2.0, 0.0078125 * input_volume);
  vol.tone(toon_hoogte, volume);
  vol.delay(10);
}
```

