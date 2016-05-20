# Blink Blink Blink

`Blink Blink Blink` is het programma `Blink`, maar dan met drie lampjes.

## Aansluiten

Sluit de Arduino als volgt aan:

![Aansluiten van Blink Blink Blink](BlinkBlinkBlinkBreadboard.png.png)

 * LEDje: dit lampje heeft een richting. De lange poot moet aan de kant van pin 13 zitten
 * Weerstand: dit is duizend (bruin-zwart-rood-goud) Ohm. Ook 330 (oranje-oranje-zwart-goud) Ohm is goed 
 * Draadjes: probeer dezelfde kleuren te gebruiken als op het plaatje. Als dit niet lukt, gebruik dan andere kleuren

## Programmeren

Dit is (een versie van) de code van `Blink`:

```
int rodePin = 11;
int groenePin = 10;

void setup() 
{
  pinMode(rodePin, OUTPUT);
  pinMode(groenePin, OUTPUT);
}

void loop() 
{
  digitalWrite(rodePin, HIGH);
  digitalWrite(groenePin, LOW);
  delay(1000);
  digitalWrite(rodePin, LOW);
  digitalWrite(groenePin, HIGH);
  delay(1000);
}
```

 * `int rodePin = 11`: in mensentaal is dit: 'Lieve computer, onthoud een heel getal genaamd rodePin. Als ik rodePin schrijf, vul dan 11 in'
 * `int groenePin = 10`: in mensentaal is dit: 'Lieve computer, onthoud een heel getal genaamd groenePin. Als ik groenePin schrijf, vul dan 10 in'
 * `void setup() {}`: de `setup` function zorgt ervoor dat alles tussen de accolades (`{` en `}`) een keer gedaan wordt
 * `pinMode(rodePin, OUTPUT)`: zeg dat er stroom uit pin 'rodePin' kan komen
 * `pinMode(groenePin, OUTPUT)`: zeg dat er stroom uit pin 'groenePin' kan komen
 * `void loop() {}`: de `function` function zorgt ervoor dat alles tussen de accolades (`{` en `}`) de rest van de tijd herhaald wordt
 * `digitalWrite(rodePin, HIGH)`: zet spanning op pin 'rodePin'
 * `digitalWrite(groenePin, LOW)`: haal de spanning van pin 'groenePin' af
 * `delay(1000)`: wacht duizend milliseconden
 * `digitalWrite(rodePin, LOW)`: haal de spanning van pin 'rodePin' af
 * `digitalWrite(groenePin, HIGH)`: zet spanning op pin 'groenePin'

## Vragen en opdrachten

 * Waarom gebruiken we het woord `rodePin` inplaats van het getal 11?
 * Mag je het woord `rodePin` veranderen in het woord `rode_pin`?
 * Mag je het woord `rodePin` veranderen in de woorden `rode pin`?
 * Wat gebeurt er als je schrijft `int rodePin = 9`? 
 * Wat gebeurt er als je schrijft `int rodePin = 13`? 
 * Zorg zelf dat ook het blauwe LEDje mee knippert. Tip: kopieer minstens vier regels
 * Maak een patroon dat omstebeurt de rode, groene en blauwe LED knipperen
 * Maak een lichtpatroon waarbij ook soms twee LEDjes tegelijk branden


