# Neopixel 1: Blink

In deze les gaan we Blink doen met NeoPixels

![De FLORAbrella, een paraplu met NeoPixels](florabrella-led-umbrella-with-ne.jpg)

\pagebreak

## Neopixel 1: opdracht 1, aansluiten

Sluit een Arduino zo aan op de NeoPixels:

 * NeoPixel GND naar Arduino GND
 * NeoPixel 5V naar Arduino 5V
 * NeoPixel DIN naar Arduino pin 6

\pagebreak

## Neopixel 1: opdracht 1, programmeren

Dit is de code van `Blink`:

```c++
#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

void loop() 
{
  pixels.setPixelColor(0, pixels.Color(64, 0, 0));
  pixels.show();
  delay(1000);
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.show();
  delay(1000);
}
```

![Computer](EmojiComputer.png) | ![Smiley](EmojiSmiley.png)
:-------------:|:----------------------------------------: 
`pixels.show()`|'Lieve computer, laat de LEDjes hun kleuren zien.'

Type de code over in de Arduino IDE en klik op `Upload`.

\pagebreak

## Neopixel 1: opdracht 2

Nu knippert
 
  * het eerste LEDje: een Arduino begint bij nul te tellen
  * in rood: oftwel met een roodwaarde van 64, groenwaarde van 0 en een blauwwaarde van 0

Laat nu 

 * het tweede LEDje
 * groen 
 * omstebeurt knipperen

\pagebreak

## Neopixel 1: oplossing 2

```c++
#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

void loop() 
{
  pixels.setPixelColor(0, pixels.Color(64, 0, 0));
  pixels.show();
  delay(1000);
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 64, 0));
  pixels.show();
  delay(1000);
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
}
```

\pagebreak

## Neopixel 1: opdracht 3

Laat nu 

 * het derde LEDje
 * blauw
 * omstebeurt knipperen, na rood en groen

\pagebreak

## Neopixel 1: oplossing 3

```c++
#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

void loop() 
{
  pixels.setPixelColor(0, pixels.Color(64, 0, 0));
  pixels.show();
  delay(1000);
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 64, 0));
  pixels.show();
  delay(1000);
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 0, 64));
  pixels.show();
  delay(1000);
  pixels.setPixelColor(2, pixels.Color(0, 0, 0));
}
```

\pagebreak

## Neopixel 1: opdracht 4

Gebruik nu onderstaande code, maar maak de LEDjes blauw:

```c++
#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

int welk_ledje = 0;
void loop() 
{
  pixels.setPixelColor(welk_ledje, pixels.Color(64, 0, 0));
  pixels.show();
  delay(100);
  welk_ledje = welk_ledje + 1; 
}
```

\pagebreak

## Neopixel 1: oplossing 4

```c++
#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

int welk_ledje = 0;
void loop() 
{
  pixels.setPixelColor(welk_ledje, pixels.Color(0, 0, 64));
  pixels.show();
  delay(100);
  welk_ledje = welk_ledje + 1; 
}
```

\pagebreak

## Neopixel 1: opdracht 5

Gebruik nu niet een blauwwaarde van `64`, maar van `welk_ledje`. Wat zie je?

\pagebreak

## Neopixel 1: oplossing 5

```c++
#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

int welk_ledje = 0;

void loop() 
{
  pixels.setPixelColor(welk_ledje, pixels.Color(0, 0, welk_ledje));
  pixels.show();
  delay(100);
  welk_ledje = welk_ledje + 1; 
}
```

\pagebreak

## Neopixel 1: opdracht 5

Gebruik nu niet een roodwaarde van `0`, maar van `64 - welk_ledje`. Wat zie je?

\pagebreak

## Neopixel 1: oplossing 5

```c++
#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

int welk_ledje = 0;

void loop() 
{
  pixels.setPixelColor(welk_ledje, pixels.Color(64 - welk_ledje, 0, welk_ledje));
  pixels.show();
  delay(100);
  welk_ledje = welk_ledje + 1; 
}
```

\pagebreak

## Neopixel 1: opdracht 6

Inplaats van `welk_ledje` steeds een hoger te maken,
kunnen we dat ook doen met een nieuwe variabele: `roodwaarde`.
Maak een nieuwe variabele, van het type `int`, met de naam `roodwaarde` en beginwaarde nul.
Gebruik `roodwaarde` daar waar je de roodwaarde van een LEDje bepaalt.
Laat `roodwaarde` steeds 1 hoger worden.

\pagebreak

## Neopixel 1: oplossing 6

```c++
#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

int welk_ledje = 0;
int roodwaarde = 0;

void loop() 
{
  pixels.setPixelColor(welk_ledje, pixels.Color(roodwaarde, 0, welk_ledje));
  pixels.show();
  delay(100);
  welk_ledje = welk_ledje + 1; 
  roodwaarde = roodwaarde + 1;
}
```

\pagebreak

## Neopixel 1: opdracht 7

Inplaats van `welk_ledje` steeds een hoger te maken,
kunnen we dat ook doen met een nieuwe variabele: `blauwwaarde`.
Maak een nieuwe variabele, van het type `int`, met de naam `blauwwaarde` en beginwaarde `32`.
Gebruik `blauwwaarde` daar waar je de roodwaarde van een LEDje bepaalt.
Laat `blauwwaarde` steeds 1 hoger worden.

\pagebreak

## Neopixel 1: oplossing 7

```c++
#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

int welk_ledje = 0;
int roodwaarde = 0;
int blauwwaarde = 0;

void loop() 
{
  pixels.setPixelColor(welk_ledje, pixels.Color(roodwaarde, 0, blauwwaarde));
  pixels.show();
  delay(100);
  welk_ledje = welk_ledje + 1; 
  roodwaarde = roodwaarde + 1;
  blauwwaarde = blauwwaarde + 1;
}
```

\pagebreak

## Neopixel 1: opdracht 8

Inplaats van `roodwaarde` steeds een hoger te maken,
kunnen we deze ook steeds twee hoger maken.
Maar we willen niet dat `roodwaarde` boven de `64` komt.
Gebruik een `if` statement: als `roodwaarde` groter is dan `64`, 
dat `roodwaarde` dan nul wordt.

\pagebreak

## Neopixel 1: oplossing 8

```c++
#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

int welk_ledje = 0;
int roodwaarde = 0;
int blauwwaarde = 0;

void loop() 
{
  pixels.setPixelColor(welk_ledje, pixels.Color(roodwaarde, 0, blauwwaarde));
  pixels.show();
  delay(100);
  welk_ledje = welk_ledje + 1; 
  roodwaarde = roodwaarde + 2;
  blauwwaarde = blauwwaarde + 1;
  if (roodwaarde > 64)
  {
    roodwaarde = 0;
  }
}
```

\pagebreak

## Neopixel 1: opdracht 9

Inplaats van `blauwwaarde` steeds een hoger te maken,
kunnen we deze ook steeds drie hoger maken.
Maar we willen niet dat `blauwwaarde` boven de `64` komt.
Gebruik een `if` statement: als `blauwwaarde` groter is dan `64`, 
dat `blauwwaarde` dan nul wordt.

\pagebreak

## Neopixel 1: oplossing 9

```c++
#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

int welk_ledje = 0;
int roodwaarde = 0;
int blauwwaarde = 0;

void loop() 
{
  pixels.setPixelColor(welk_ledje, pixels.Color(roodwaarde, 0, blauwwaarde));
  pixels.show();
  delay(100);
  welk_ledje = welk_ledje + 1; 
  roodwaarde = roodwaarde + 2;
  blauwwaarde = blauwwaarde + 3;
  if (roodwaarde > 64)
  {
    roodwaarde = 0;
  }
  if (blauwwaarde > 64)
  {
    blauwwaarde = 0;
  }
}
```

\pagebreak

## Neopixel 1: opdracht 10

`welk_ledje` wordt nu steeds een hoger.
Voeg nu een `if` statement toe: als `welk_ledje` groter *of gelijk* is dan `aantal_neopixels`, 
dat `welk_ledje` dan nul wordt.

\pagebreak

## Neopixel 1: oplossing 10

```c++
#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

int welk_ledje = 0;
int roodwaarde = 0;
int blauwwaarde = 0;

void loop() 
{
  pixels.setPixelColor(welk_ledje, pixels.Color(roodwaarde, 0, blauwwaarde));
  pixels.show();
  delay(100);
  welk_ledje = welk_ledje + 1; 
  roodwaarde = roodwaarde + 2;
  blauwwaarde = blauwwaarde + 3;
  if (roodwaarde > 64)
  {
    roodwaarde = 0;
  }
  if (blauwwaarde > 64)
  {
    blauwwaarde = 0;
  }
  if (welk_ledje >= aantal_neopixels)
  {
    welk_ledje = 0;
  }
}
```

\pagebreak

## Neopixel 1: eindopdracht

Maak een nieuwe variabele `groenwaarde`, die de groenwaarde van de LEDjes bepaalt.
Deze wordt steeds vier meer. Als `groenwaarde` boven de 64 uitkomt, zet deze dan op nul.


