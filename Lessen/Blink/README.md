# Blink

`Blink` is het eerste programma dat je leert op Arduino.

## Aansluiten

Sluit de Arduino als volgt aan:

![Aansluiten van Blink](BlinkBroadboard.png)

 * LEDje: dit lampje heeft een richting. De lange poot moet aan de kant van pin 13 zitten
 * Weerstand: dit is duizend (bruin-zwart-rood-goud) Ohm. Ook 330 (oranje-oranje-zwart-goud) Ohm is goed 
 * Draadjes: probeer dezelfde kleuren te gebruiken als op het plaatje. Als dit niet lukt, gebruik dan andere kleuren

## Programmeren

Dit is (een versie van) de code van `Blink`:

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
