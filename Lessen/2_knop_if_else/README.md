# 2. Knop if ... else


## Aansluiten

![Stroomschema](2_knop_if_else.png)

![Sunglasses](EmojiSunglasses.png) | De weerstand aan de knop wordt een 'Pull Down' weerstand genoemd
:-------------:|:----------------------------------------: 

## Code

Hier is code om het lampje aan te laten gaan,
als de knop wordt ingedrukt:

```c++
void setup() 
{
  pinMode(13, OUTPUT);
  pinMode( 2, INPUT );
}

void loop()
{
  digitalWrite(13, digitalRead(2));
}
```

![Computer](EmojiComputer.png)    | ![Smiley](EmojiSmiley.png)
:--------------------------------:|:----------------------------------------: 
`digitalRead(2)`                  |'Lieve computer, geef mij HIGH als er op pin 2 spanning staat. Geef anders LOW'
`digitalWrite(13, digitalRead(2))`|'Zet op pin 13 spanning als er op pin 2 spanning staat'

## Vragen

 * 1. Als je de knop indrukt, gaat de lamp dan uit of aan?
 * 2. Er is een regel `pinMode( 2, INPUT )`. Waarom staat er een spatie voor de `2`? Mag die spatie weg?

## Oplossingen

 * 1. De knop gaat dan aan
 * 2. Er staat een spatie, omdat dit mooier eruit ziet met de regel erboven. De spatie mag weg. 

![Sunglasses](EmojiSunglasses.png) | Goede programmeurs werken netjes
:-------------:|:----------------------------------------: 

## if

Met `if` kun je de Arduino iets laten doen, als iets zo is:

```c++
void setup() 
{
  pinMode(4, INPUT );
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  if (digitalRead(4) == HIGH)
  {
    digitalWrite(5, HIGH);
  }
  else
  {
    digitalWrite(6, LOW);
  }
}
```

In deze code wordt gekeken of op pin 4 spanning staat. Zo ja, dan zet de Arduino
spanning op pin 5. Anders (`else`) haalt de Arduino de spanning van pin 6 af.

![Computer](EmojiComputer.png)  | ![Smiley](EmojiSmiley.png)
:------------------------------:|:----------------------------------------: 
`if (digitalRead(4) == HIGH) {}`|'Lieve computer, als er spanning op pin 4 staat, doe dan hetgeen tussen accolades'

![Sunglasses](EmojiSunglasses.png) | De `=` kun je uitspreken als 'zet op'. De `==` kun je uitspreken als 'is gelijk aan'
:-------------:|:----------------------------------------: 

## Opdracht

Maak de code zo, dat:

 * als je op de knop drukt, dat het lampje aan gaat 
 * als je op de knop niet indrukt, dat het lampje uit gaat

![Bowtie](EmojiBowtie.png) | Na de ronde haken van `if` komt geen puntkomma
:-------------:|:----------------------------------------: 

## Oplossing

```c++
void setup() 
{
  pinMode(13, OUTPUT);
  pinMode( 2, INPUT );
}

void loop()
{
  if (digitalRead(2) == HIGH)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
}
```

\pagebreak

## Opdracht 'Knop met twee LEDjes'

Sluit een tweede LEDje aan. Maak de code zo, dat:

 * als je op de knop drukt, dat het eerste lampje aan gaat en het tweede LEDje uit 
 * als je op de knop niet indrukt, dat het eerste lampje uit gaat en het tweede LEDje uit


![Sunglasses](EmojiSunglasses.png)| Binnen de accolades van een `if` kun je meerdere regels typen. Net als tussen de accolades van `setup` en `loop`!
:-------------:|:----------------------------------------: 

![Bowtie](EmojiBowtie.png) | Vergeet de `else` ('doe anders') niet!
:-------------:|:----------------------------------------: 

\pagebreak

## Oplossing 'Knop met twee LEDjes'

Figuur `Oplossing van 'Knop met twee LEDjes'` laat zien hoe je dit aan moet sluiten.

![Oplossing van 'Knop met twee LEDjes'](2_knop_if_else_2.png)

Dit is de code:

```c++
void setup() 
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode( 2, INPUT );
}

void loop()
{
  if (digitalRead(2) == HIGH)
  {
    digitalWrite(12, LOW );
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW );
  }
  delay(10);
}
```

## Eindopdracht

Sluit een tweede knop aan. Maak de code zo, dat

 * als je op de eerste knop drukt, dat het eerste lampje aan gaat
 * als je de eerste knop niet indrukt, dat het eerste lampje uit gaat
 * als je op de tweede knop drukt, dat het tweede lampje uit gaat
 * als je de tweede knop niet indrukt, dat het tweede lampje aan gaat

![Sunglasses](EmojiSunglasses.png)| Je kunt vaker `if` na elkaar zetten
:-------------:|:----------------------------------------: 

![Bowtie](EmojiBowtie.png) | Voor een tweede knop heb je een tweede weerstand van tienduizend Ohm nodig
:-------------:|:----------------------------------------: 

