# 24: Theremin met joystick

In deze les gaan we een theremin met joystick maken.

\pagebreak

## 24.1: opdracht: aansluiten piezo

 * Sluit een piezo aan op pin 5.
 * Gebruik een weerstand van tienduizend Ohm,
   kleurcode: bruin-zwart-oranje-goud

\pagebreak

## 24.1: oplossing: aansluiten piezo

![Aansluiten piezo](24_theremin_joystick_piezo.png)

\pagebreak

## 24.2: opdracht: de `volume` bibliotheek

Upload de volgende code:

```c++
#include "Volume.h"

Volume vol; // Piezo in pin 5

void setup()
{
  vol.begin();
}

void loop()
{
  const int toon_hoogte = 440;
  const int volume = 255;
  vol.tone(toon_hoogte, volume);
  vol.delay(10);
}
```

Doet de 'Volume' bibliotheek het niet, ga dan naar de les 'Volume installeren'.

\pagebreak

## 24.3: opdracht: aansluiten joystick

Sluit een joystick aan:

Pin joystick|Pin Arduino
------------|-----------
+5V         |5V
GND         |GND
VRx of VER  |A0

\pagebreak

## 24.3: oplossing: aansluiten joystick

![Aansluiten joystick](24_theremin_joystick_een.png)

\pagebreak

## 24.4: opdracht: toon hoogte lineair

Lees de joystick.

Gebruik:

```c++
const int input_toon_hoogte = /* lees de waarde van A0 */;
```

```c++
const int toon_hoogte = input_toon_hoogte;
```

\pagebreak

## 24.4: oplossing: toon hoogte lineair

```c++
#include "Volume.h"

Volume vol; // Piezo in pin 5

void setup()
{
  pinMode(A0, INPUT);
  vol.begin();
}

void loop()
{
  const int input_toon_hoogte = analogRead(A0);
  const int toon_hoogte = input_toon_hoogte;
  const int volume = 255;
  vol.tone(toon_hoogte, volume);
  vol.delay(10);
}
```

\pagebreak

## 24.5: opdracht: toonhoogte exponentieel

De toonhoogte klinkt nog niet mooi. 
Dat komt omdat hogere tonen steeds verder van elkaar af gaan zitten.
Met `pow` kunnen we een machtverheffing doen (wat dat ook is),
zodat we mooi door de tonen heen kunnen gaan.

Vervang:

```c++
const int toon_hoogte = input_toon_hoogte;
```

door:

```c++
const int toon_hoogte = 110.0 * pow(2.0, 0.002 * input_toon_hoogte);
```

\pagebreak

## 24.5: oplossing: toonhoogte exponentieel

```c++
#include "Volume.h"

Volume vol; // Piezo in pin 5

void setup()
{
  pinMode(A0, INPUT);
  vol.begin();
}

void loop()
{
  const int input_toon_hoogte = analogRead(A0);
  const int toon_hoogte = 110.0 * pow(2.0, 0.002 * input_toon_hoogte);
  const int volume = 255;
  vol.tone(toon_hoogte, volume);
  vol.delay(10);
}
```

\pagebreak

## 24.6: eindopdracht

 * Sluit een tweede pin (`VRy` of `HOR`) van de joystick aan op A1.
 * Gebruik:

```c++
const int input_volume = /* lees de waarde van A1 */;
```

 * Gebruik:

```c++
const int volume = 1.0 * pow(2.0, 0.0078125 * input_volume);
```
