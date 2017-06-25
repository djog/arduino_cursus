# Piano

De piano is een bekend muziekinstrument.
Je kunt veel liedjes spelen op de piano.
In deze les gaan we pianomuziek laten horen op de Arduino.

## Piezo aansluiten

Om muziek te maken hebben we een piezo (zeg: 'pie-jee-zoo') nodig.
Deze is gemakkelijk aan te sluiten:

![Piano Aansluiten](PianoAansluiten.png)

Het weerstandje is tienduizend Ohm, met bandjes bruin-zwart-oranje-goud.

## Vader Jacob

Hier zie je de bladmuziek van Vader Jacob:

![Vader Jacob](VaderJacob.png)

Om deze muziek op de Arduino te zetten, moeten we weten hoe we bladmuziek kunnen lezen.

Hier zie je een plaatje van een piano:

![Piano met noten en frequenties](PianoNotenFrequenties.png)

Dit plaatje laat meerdere dingen zien:

 * Waar de toetsen van een piano zitten
 * Welke muzieknoot van bladmuziek bij elke toets hoort
 * Welke frequentie bij elke muzieknoot hoort

De toonhoogte van een muzieknoot wordt bepaalt door de frequentie.
De frequentie van een muzieknoot is hoe snel de lucht trilt.
Hoge tonen hebben een hoge frequentie.
Lage tonen hebben een lage frequentie.

De Arduino werkt met frequenties.

De eerste noot van Vader Jacob is de laagste noot op de piano van het plaatje.
Er staat het getal `131` bij. Dit is de frequentie van die muzieknoot.
Om die noot op de Arduino af te spelen:

```c++
void setup() 
{
  pinMode(8, OUTPUT);
  tone(8, 131, 750);
  delay(1000);
}

void loop() {}
```

Om de eerste twee noten te spelen:

```c++
void setup() 
{
  pinMode(8, OUTPUT);
  tone(8, 131, 750);
  delay(1000);
  tone(8, 147, 750);
  delay(1000);
}

void loop() {}
```


## Opdrachten

 * Sluit de Arduino aan met een piezo
 * Upload de code met een muzieknoot:
   * Wat betekent `pinMode(8, OUTPUT)`? Tip: op welke pin zit de piezo?
   * Wat betekent `tone(8, 131, 750)`? Tips: (1) op welke pin zit de piezo? (2) wat is de frequentie van de muzieknoot? (3) hoe lang duurt de toon?
   * Wat betekent `delay(1000)`? Tip: deze kennen we al uit les 1 `Blink`
 * Upload de code met twee muzieknoten:
   * Wat gebeurt er als je `tone(8, 131, 750)` vervangt door `tone(8, 131, 1000)`?
   * Waarom staan de `delay`s er? Tip: haal ze weg en luister wat er gebeurt
 * Maak nu zelf Vader Jacob
