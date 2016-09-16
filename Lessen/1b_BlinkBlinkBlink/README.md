# Les 1b: Blink Blink Blink

Deze les heet 'Blink Blink Blink', omdat het [de les Blink](../1a_Blink/README.md) is, maar dan met drie lampjes.

Weet je nog niet hoe je een lampje aansluit? Ga dan naar [les 1a: Blink](../1a_Blink/README.md).

In deze les leer je:

 * Hoe je meerdere LEDjes aansluit
 * Wat een variable is
 * Hoe je een variabele gebruikt
 * Hoe je een programma aanpast 

## Waarom variabelen?

Dit is de code van Blink:

```
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

## Vragen en opdrachten

 * Wat doet deze code ook alweer?

![Blink](Blink.png)

 * Sluit Blink aan (het plaatje hierboven). Upload deze code op je Arduino. Wat zie je gebeuren?
 * Als je het getal `13` ziet, waar denk je dan aan? 
 * Als je het getal `1000` ziet, waar denk je dan aan? 
 * Als je het LEDje op een andere pin wil zetten, op hoeveel plekken moet je de code aanpassen?

## Een variabele

Hier zien we Blink met een variabele:

```
int pin_led = 13;

void setup() 
{
  pinMode(pin_led, OUTPUT);
}

void loop() 
{
  digitalWrite(pin_led, HIGH);
  delay(1000);
  digitalWrite(pin_led, LOW);
  delay(1000);
}
```

In de eerste regel zeg je: 
'Lieve Arduino, onthoud een int (dat is een heel getal). 
Ik noem dat hele getal `pin_led`'.
De waarde van `pin_led` is `13`'.

Vanaf nu, als je schrijft `pin_led`, dan vult de Arduino daar `13` in.

## Vragen en opdrachten

 * Upload deze code op je Arduino. Wat zie je gebeuren?
 * Verander de beginwaarde van `pin_led` naar `12`. Het lampje knippert nu niet meer. Pas de bedrading van de machine aan, zodat deze het weer doet
 * Vervang het getal `1000` door een nieuwe variable, `wacht_tijd`. Dit is een int (een heel getal) met de beginwaarde `1000`. 
 * Waarom gebruiken programmeurs variabelen?


## Blink Blink Blink aansluiten

Nu is het tijd Blink aan te sluiten:

![BlinkBlinkBlink](BlinkBlinkBlink.png)

 * Haal de USB snoer uit de computer, zodat de Arduino geen spanning meer heeft
 * Sluit de onderdelen aan zoals op de tekening

## Code

Hier staat weer de code van Blink:

```
int pin_rood = 11;
int pin_groen = 10;

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

Dit is wat het doet:

 * `void setup() {}`: de `setup` function zorgt ervoor dat alles tussen de accolades (`{` en `}`) een keer gedaan wordt
 * `pinMode(13, OUTPUT)`: zeg dat er stroom uit pin 13 kan komen
 * `void loop() {}`: de `function` function zorgt ervoor dat alles tussen de accolades (`{` en `}`) de rest van de tijd herhaald wordt
 * `digitalWrite(13, HIGH)`: zet spanning op pin 13
 * `delay(1000)`: wacht duizend milliseconden
 * `digitalWrite(13, LOW)`: haal de spanning van pin 13 af

## Vragen en opdrachten

 * Hoe lang is duizend milliseconden ongeveer?
 * Wat gebeurt er als je de `digitalWrite(13, HIGH)` weghaalt?
 * Wat gebeurt er als je de `digitalWrite(13, LOW)` weghaalt?
 * Wat gebeurt er als je de eerste `delay(1000)` weghaalt?
 * Wat gebeurt er als je de tweede `delay(1000)` weghaalt?
 * Laat het LEDje 10x zo snel knipperen. Tip: in welke twee regels wacht de Arduino?
 * Laat het LEDje aan en uit gaan zonder wachttijd. Zie je de LED knipperen? Hoe kan dat?
 * Stel de wachttijd zo in, dat je het LEDje nog net kunt zien knipperen. Welke wachttijd is dat ongeveer?

De LED zit nu verbonden met pin 13. Haal de LED uit pin 13 en verbind deze met pin 12.

 * Zorg dat je code weer werkt. Tip: je zult drie keer een 13 moeten veranderen naar een 12
 * Wat gebeurt er als je het LEDje omdraait?
 * Wat gebeurt er als je de weerstand omdraait?
