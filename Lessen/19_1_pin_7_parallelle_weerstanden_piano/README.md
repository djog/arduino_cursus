# Les 19: 1-pin-7-parallelle_weerstanden-piano

In deze les gaan we een simpele piano maken, die 1 pin gebruikt en 7 parallelle weerstanden.

We bouwen de piano stap voor stap op en testen elke stap apart.

Het uitlezen van de knoppen hebben we al eerder gezien in lesboekje 2, bladzijde 16.
Het afspelen van een geluidje hebben we al eerder gezien in lesboekje 3, bladzijde 17.

## Opdracht 1

Sluit de eerste knop aan volgens het plaatje. Zet de knop in het midden van je breadboard!

![Een pin](19_fig_1_bb.png)

![Bowtie](EmojiSunglasses.png) | De 'Pull Down' weerstand zorgt dat pin 2 verbonden is met GND als de knop niet ingedrukt is
:-------------:|:----------------------------------------: 

Zet deze code op je Arduino:

```c++
const int speaker_pin = 8;
const int piano_pin = A0;

void setup()
{
  pinMode(speaker_pin, OUTPUT);
  pinMode(piano_pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(piano_pin));
  if (analogRead(piano_pin) > 510)                          //bekijk de Seriële monitor !!
  {
    tone(speaker_pin, 247);
    delay(250);
    noTone(speaker_pin);
    delay(250);
  }
}
```

![Sunglasses](EmojiSunglasses.png) | '>' betekent 'groter dan'. De waarde A0 is nooit precies een getal.In de seriële monitor lezen we het getal dat bij de knop hoort af en testen  dan op een getal dat daar net iets onder ligt.
:-------------:|:----------------------------------------: 


## Opdracht 2

Sluit een tweede knop aan, met twee weerstanden ervoor die parallel staan [dus 5k], zie plaatje


![Een pin](19_fig_2_bb.png)

![Bowtie](parallel.png) |[Bowtie](parallel.PNG) | Parallel betekent naast elkaar. 
:-------------:|:----------------------------------------: 

Bouw een volgende toets van de piano **links** van de eerste. Gebruik deze code:

&nadenkende smiley& Is het nodig om de hele code In te voeren?

```c++
const int speaker_pin = 8;
const int piano_pin = A0;

void setup()
{
  pinMode(speaker_pin, OUTPUT);
  pinMode(piano_pin, INPUT);
}

void loop()
{
  if (analogRead(piano_pin) > 384)
  {
    tone(piano_pin, ?247, 250);
    delay(250);
  }
  else if (analogRead(piano_pin) > ?192)
  {
    tone(piano_pin, 175, 250);
    delay(250);
  }
}
```

## Oplossing 2

[plaatje van aansluiten]

## Opdracht 3

[derde toets, links van de vorige, met 4 parellle voorschakelweerstanden, nu ook zelf code schrijven]

## Oplossing 3

[code en schema hiero]

## Opdracht 4

[vierde toets, links van de vorige, met 8 parellle voorschakelweerstanden, nu weer zelf code schrijven]

## Oplossing 4

[code en schema hiero]

## Opdracht 5

[vijfde toets, rechts van de vorige, met 2 serie voorschakelweerstanden, nu weer zelf code schrijven]

[smiley: tip: de nieuwe waardes worden hoger dan ?384. Het nieuwe if statement moet nu eerst!]

## Oplossing 5

[code en schema hiero]

## Eindopdracht

Maak een piano van zeven toetsen. Zie figuur 'Frequenties' voor de andere getallen.

![Frequenties](18_frequenties.png)

```
Eindopdracht schets oplossing
juiste analogReads uitproberen/berekenen
juiste toonhoogten uit figuur 18_frequenties
```

```c++
const int speaker_pin = 8;
const int piano_pin = A0;

void setup()
{
  pinMode(speaker_pin, OUTPUT);
  pinMode(piano_pin, INPUT);
}

void loop()
{
  if (analogRead(piano_pin) > ?32)
  {
    tone(piano_pin, ?280, 250); 
    delay(250);
  }
  else if (analogRead(piano_pin) > ?64)
  {
    tone(piano_pin, ?270, 250); 
    delay(250);
  }
  else if (analogRead(piano_pin) > ?128)
  {
    tone(piano_pin, ?260, 250); 
    delay(250);
  }
  else if (analogRead(piano_pin) > ?384)
  {
    tone(piano_pin, 247, 250); 
    delay(250);
  }
  else if (analogRead(piano_pin) > ?192)
  {
    tone(piano_pin, ?230, 250);
    delay(250);
  }
  else if (analogRead(piano_pin) > ?96)
  {
    tone(piano_pin, ?220, 250);
    delay(250);
  }
  else if (analogRead(piano_pin) > ?48) 
  {
    tone(piano_pin, ?200, 250);
    delay(250);
  }
}
```
