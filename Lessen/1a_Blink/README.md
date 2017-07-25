# Les 1a: Blink

In deze les gaan we de allergemakkelijkste schakeling maken die er is: Blink!

In deze les leer je:

 * Hoe je een LEDje aansluit
 * Je eerste Arduino programmeercode
 * Hoe je een LEDje laat knipperen

## Een Arduino aansluiten

Sluit een Arduino zo aan:

![Blink zonder led](BlinkZonderLed.png)

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

![Logo van de Arduino IDE](ArduinoIdeLogo.png)

Je kunt de Arduino IDE ook starten, door:

 * Druk op de Windows toets (linksonder, tussen `Ctrl` en `Alt`)
 * Type `arduino` (kleine letters) en dan Enter

Als het goed is, zie je de Arduino IDE:

![De Arduino IDE](ArduinoIde.png)

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

## Blink

Nu is het tijd Blink aan te sluiten:

![Blink](Blink.png)

 * Haal de USB snoer uit de computer, zodat de Arduino geen spanning meer heeft
 * Sluit Blink aan zoals op de tekening
 * Zet de spanning weer op de Arduino
 * Als het goed is, knippert het rode LEDje nu mee met het LEDje op de Arduino. 

:bowtie: Als het LEDje niet brand, draai deze dan om.

## Opdracht

Sluit Blink aan zoals figuur `Blink`.

## Vragen en opdrachten

 * Wat doet deze code ook alweer?
 * Kun je het lampje tien keer zo snel laten knipperen? Proberen en kijken! Tip: het lampje gaat aan/uit na duizend milliseconden
 * Kun je het lampje op z'n snelst laten knipperen? Proberen en kijken! Als je iets onverwachts ziet: klopt! Waarom is dat?
 * Haal het draadje uit gat `13` en doe deze in `12`. Verander het programma zo dat het lampje weer knippert


## Eindopdracht