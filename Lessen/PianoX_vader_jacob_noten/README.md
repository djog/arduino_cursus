# Vader Jacob met noten

Figuur 'De bladmuziek van Vader Jacob' laat de bladmuziek 
van Vader Jacob zien.

![De bladmuziek van Vader Jacob](VaderJacob.png)

## Frequenties

Elke noot heeft een naam:

```c++
const int NOTE_C3  = 131;
const int NOTE_D3  = 147;
const int NOTE_E3  = 165;
```

![De toonhoogten van noten](PianoNotenFrequenties.png)

De meest linker noot is `NOTE_C3`.

Een noot met een hoge frequentie klinkt hoger. Hoge tonen klinken irritanter. Volwassen vrouwen zijn beter in het zingen van hoge noten. Magnetronpiepjes hebben vaak een hoge toon.

Een noot met een lage frequentie klinkt lager. Volwassen mannen zijn beter in het zingen van lage noten. Een draaiende automotor heeft vaak een lage toon.

# Opdracht

Wat is de naam van de tweede noot van Vader Jacob?

## Oplossing

`NOTE_D3`.

## Duur

Elke noot heeft een lengte. 
De lengthe van een noot is hoe lang je deze hoort.
Dit wordt de duur van een noot genoemd.
Hieronder zie je duur van de belangrijkste soorten noten:

Plaatje|Naam|Duur in milliseconden
---|---|---
![hele noot](HeleNoot.png)|Hele noot|250
![dubbele noot](DubbleNoot.png)|Dubbele noot|500
![halve noot](HalveNoot.png)|Halve noot|125

De dubbele noot duurt twee keer zo lang als een hele noot.
De halve noot duurt half zo kart als een hele noot.

Een hele noot hoeft niet 250 milliseconden te duren. 
Een hele noot kan korter duren voor snelle liedjes.
Een hele noot kan langer duren voor langzame liedjes.

Als de hele noot korter wordt, worden de halve en dubbele noten ook korter.
Als de hele noot langer wordt, worden de halve en dubbele noten ook langer.

De eerste noot van Vader Jacob duurt dus 250 milliseconden.

## Opdracht

Wat is de toonhoogte en duur van de laatste noot van Vader Jacob?

## Oplossing

De toonhoogte is 131 Hertz. Dit is dezelfde hoogte als de eerste noot.

De laatste noot is een dubbele noot. Een dubbele noot heeft een duur is 500 millisconden.

## Aansluiten

![Aansluiten van een speaker](PianoAansluiten.png)


```c++
const int speaker_pin = 8;

void setup()
{
  tone(speaker_pin, NOTE_C3, 250); // Va
  delay(250);
}

void loop()
{

}
```

Sluit figuur 'Aansluiten van een speaker' aan.
Zet de code op de Arduino.

Let op: de `250` moet in zowel `tone` als `delay`!

## Opdracht

 1. Hoe vaak wordt het liedje gespeeld?
 2. Waarom staat er `Va` in de code?

## Oplossing

 1. Een keer
 2. Omdat dit de eerste noot van Vader Jacob is

## Opdracht

Programmeer zelf de tweede noot. Zet achteraan de regel `// der`, zodat je weet waar we in het liedje zijn

## Oplossing

```c++
const int speaker_pin = 8;

void setup()
{
  tone(speaker_pin, NOTE_C3, 250); // Va
  delay(250);
  tone(speaker_pin, NOTE_D3, 250); // der
  delay(250);
}

void loop()
{

}
```

## Opdracht

Programmeer alvast de laatste noot. Zet achteraan de regel `// bom`, zodat je weet waar we in het liedje zijn

## Oplossing

```c++
const int speaker_pin = 8;

void setup()
{
  tone(speaker_pin, NOTE_C3, 250); // Va
  delay(250);
  tone(speaker_pin, NOTE_D3, 250); // der
  delay(250);


  tone(speaker_pin, NOTE_C3, 500); // bom
  delay(500);
}

void loop()
{

}
```


## Eindopdracht

Maak het liedje Vader Jacob af.