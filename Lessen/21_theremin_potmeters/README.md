# Les 21: Theremin met potmeters

In deze les gaan we een theremin maken met potmeters.






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
  vol.tone(analogRead(A0), analogRead(A1) / 4); // pa
  vol.delay(100);
}
```




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
  const int volume = 0.25 * input_volume; 
  vol.tone(toon_hoogte, volume);
  vol.delay(10);
}
```




## Een Arduino aansluiten

Sluit een Arduino zo aan:

![Blink zonder led](1a_blink_zonder_led.png)

Je zult wel een USB kabel in de Arduino en in een laptop moeten doen

## Opdracht 1

Sluit de Arduino aan.

![Sunglasses](EmojiSunglasses.png) | De Arduino heeft zelf al een lampje dat je kunt programmeren.
:-------------:|:----------------------------------------: 

\pagebreak

## De Arduino IDE opstarten

Om een Arduino te programmeren hebben we een programma nodig.
Dit programma noemen we 'de Arduino IDE' (IDE spreek je uit
als 'ie-dee-ee')

De Arduino IDE staat op alle laptops van de cursus.
Hier zie je het logo van de Arduino IDE:

![Logo van de Arduino IDE](1a_blink_ide_logo.png)

Je kunt de Arduino IDE ook starten, door:

 * Druk op de Windows toets (linksonder, tussen `Ctrl` en `Alt`)
 * Type `arduino` (kleine letters) en dan Enter

Als het goed is, zie je de Arduino IDE:

![De Arduino IDE](1a_blink_ide.png)

![Sunglasses](EmojiSunglasses.png) | IDE betekent 'Integrated Development Environment', het programma waarmee je programmeert.
:-------------:|:----------------------------------------: 

\pagebreak

## Ons eerste programma

Dit is (een versie van) de code van `Blink`:

```c++
void setup() 
{
  pinMode(13, OUTPUT);
}

void loop() 
{
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
```

![Computer](EmojiComputer.png) | ![Smiley](EmojiSmiley.png)
:-------------:|:----------------------------------------: 
`void setup() { }`|'Lieve computer, doe wat tussen accolades staat een keer.'

![Computer](EmojiComputer.png) | ![Smiley](EmojiSmiley.png)
:-------------:|:----------------------------------------: 
`void loop() { }`|'Lieve computer, doe de hele tijd wat tussen accolades staat.'

Type de code over in de Arduino IDE en klik op `Upload`.

![Hier kun je op `Upload` klikken](1a_blink_upload.png)

## Opdracht 2

Laat het LEDje 10x zo snel knipperen. 
Hint: het LEDje is nu 1000 milliseconden aan en 1000 milliseconden uit.

\pagebreak

## Oplossing 2

```c++
void setup() 
{
  pinMode(13, OUTPUT);
}

void loop() 
{
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
}
```

![Computer](EmojiComputer.png) | ![Smiley](EmojiSmiley.png)
:-------------:|:----------------------------------------: 
`pinMode(13, OUTPUT);`|'Lieve computer, zorg dat er stroom uit pin 13 kan komen.'

![Computer](EmojiComputer.png) | ![Smiley](EmojiSmiley.png)
:-------------:|:----------------------------------------: 
`digitalWrite(13, HIGH);`|'Lieve computer, zet spanning op pin 13.'

![Computer](EmojiComputer.png) | ![Smiley](EmojiSmiley.png)
:-------------:|:----------------------------------------: 
`delay(1000);`|'Lieve computer, doe nu 1000 milliseconden niks.'

![Computer](EmojiComputer.png) | ![Smiley](EmojiSmiley.png)
:-------------:|:----------------------------------------: 
`digitalWrite(13, LOW);`|'Lieve computer, zet geen spanning op pin 13.'

## Opdracht 3

Laat het LEDje zo snel als kan knipperen. Wat zie je?

\pagebreak

## Oplossing 3

Er zijn meer oplossingen, dit is er een:

```c++
void setup() 
{
  pinMode(13, OUTPUT);
}

void loop() 
{
  digitalWrite(13, HIGH);
  delay(1);
  digitalWrite(13, LOW);
  delay(1);
}
```

![Bowtie](EmojiBowtie.png) | Ook goed: `delay(0);` of de regels met `delay` helemaal weghalen.
:-------------:|:----------------------------------------: 

Je ziet het lampje niet meer knipperen. 

![Sunglasses](EmojiSunglasses.png) | Het lampje knippert wel, maar onze ogen kunnen niet snel genoeg kijken om het te zien.
:-------------:|:----------------------------------------: 

\pagebreak

## Blink

Nu is het tijd Blink aan te sluiten:

![Blink](1a_blink.png)

 * Haal het USB snoer uit de computer, zodat de Arduino geen spanning meer heeft
 * Sluit Blink aan zoals op de tekening
 * Zet de spanning weer op de Arduino
 * Als het goed is, knippert het rode LEDje nu mee met het LEDje op de Arduino. 

![Bowtie](EmojiBowtie.png) | Als het LEDje niet brandt, draai deze dan om.
:-------------:|:----------------------------------------: 

## Opdracht 4

Sluit je LEDje nu aan op pin 12.

\pagebreak

## Oplossing 4

![Blink met LEDje op pin 12](1a_blink_op_12.png)

## Opdracht 5

Zorg nu dat het LEDje op pin 12 gaat knipperen op de seconde.

\pagebreak

## Oplossing 5

```c++
void setup() 
{
  pinMode(12, OUTPUT);
}

void loop() 
{
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  delay(100);
}
```

## Eindopdracht

Sluit de LED aan op pin 11 en laat deze 2 keer per seconde knipperen.

![Sunglasses](EmojiSunglasses.png) | Gelukt? Laat dit zien aan een volwassene voor een sticker!
:-------------:|:----------------------------------------: 

## Extra

 * Bas On Tech video: [https://youtu.be/KgMocAMAJvg](https://youtu.be/KgMocAMAJvg)
