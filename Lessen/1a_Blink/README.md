# Les 1a: Blink

In deze les gaan we de allergemakkelijkste schakeling maken die er is: Blink!

## Een Arduino aansluiten

Sluit een Arduino zo aan:

![Blink zonder led](1a_blink_zonder_led.png)

Je zult wel een USB kabel in de Arduino en in een laptop moeten doen

## Opdracht

Sluit de Arduino aan.

![Sunglasses](EmojiSunglasses.png) | De Arduino heeft zelf al een lampje dat je kunt programmeren.
:-------------:|:----------------------------------------: 

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

## Opdracht

Laat het LEDje 10x zo snel knipperen. 
Hint: het LEDje is nu 1000 milliseconden aan en 1000 milliseconden uit.

## Oplossing

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
`delay(1000);`|'Lieve computer, doe nu 1000 milliseconden niks.'

## Opdracht

Laat het LEDje zo snel als kan knipperen. Wat zie je?

## Oplossing

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

Ook goed zijn `delay(0);` of de regels met `delay` helemaal weghalen.

Je ziet het lampje niet meer knipperen. 

![Sunglasses](EmojiSunglasses.png) | Het lampje knippert wel, maar onze ogen kunnen niet snel genoeg kijken om het te zien.
:-------------:|:----------------------------------------: 

## Blink

Nu is het tijd Blink aan te sluiten:

![Blink](1a_blink.png)

 * Haal de USB snoer uit de computer, zodat de Arduino geen spanning meer heeft
 * Sluit Blink aan zoals op de tekening
 * Zet de spanning weer op de Arduino
 * Als het goed is, knippert het rode LEDje nu mee met het LEDje op de Arduino. 

![Bowtie](EmojiBowtie.png) | Als het LEDje niet brand, draai deze dan om.
:-------------:|:----------------------------------------: 

## Opdracht

Sluit je LEDje nu aan op pin 12.

## Oplossing

![Blink met LEDje op pin 12](1a_blink_op_12.png)

## Opdracht

Zorg nu dat het LEDje op pin 12 gaat knipperen op de seconde.

## Oplossing

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

![Computer](EmojiComputer.png) | ![Smiley](EmojiSmiley.png)
:-------------:|:----------------------------------------: 
`pinMode(13, OUTPUT);`|'Lieve computer, zorg dat er stroom uit pin 13 kan komen.'
`digitalWrite(13, HIGH);`|'Lieve computer, zet spanning op pin 13.'

## Eindopdracht

Sluit de LED aan op pin 11 en laat deze 2 keer per seconde knipperen.

![Sunglasses](EmojiSunglasses.png) | Gelukt? Laat dit zien aan een volwassene voor een sticker!
:-------------:|:----------------------------------------: 
