# Les 19: 1-pin-7-parallelle_weerstanden-piano

In deze les gaan we een simpele piano maken, die 1 pin gebruikt en 7 parallelle weerstanden.

We bouwen de piano stap voor stap op en testen elke stap apart.

Het uitlezen van de knoppen hebben we al eerder gezien in lesboekje 2, bladzijde 16.
Het afspelen van een geluidje hebben we al eerder gezien in lesboekje 3, bladzijde 17.

![Piano](18_frequenties.png) | We beginnen met de middelste toets met frequentie 247. Dan bouwen we naar links 3 toetsen erbij. Daarna bouwen we rechts 3 toetsen erbij. De frequenties staan in dit plaatje,
:-------------:|:----------------------------------------: 

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

Krijg je een geluid als je op de knop drukt? Dan kun je door naar opdracht 2.

## Opdracht 2

Sluit een tweede knop aan **links** van de eerste, met twee weerstanden ervoor die parallel staan [dus 5k], zie plaatje


![Een pin](19_fig_2_bb.png)

![parallel](parallel.PNG) | Twee parallele weerstanden van 10k geeft een weerstand van 5k.
:-------------:|:----------------------------------------: 

![serie](serie.PNG) | Twee weerstanden van 10k in serie geeft een weerstand van 20k.
:-------------:|:----------------------------------------: 

Gebruik deze code:

![denk](EmojiThinking.png) | Is het nodig om de hele code opnieuwe in te voeren?
:-------------:|:----------------------------------------: 



```c++
int speaker_pin = 8;
int piano_pin = A0;
int sensorValue = 0;

void setup()
{
  pinMode(speaker_pin, OUTPUT);
  pinMode(piano_pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = (analogRead(piano_pin));
  Serial.println(sensorValue);
  if (sensorValue > 680)                          //bekijk de Seriële monitor !!
  {
    tone(speaker_pin, 220);
    delay(250);
    noTone(speaker_pin);
    delay(250);
  }
  else if (sensorValue > 510)                          //bekijk de Seriële monitor !!
  {
    tone(speaker_pin, 247);
    delay(250);
    noTone(speaker_pin);
    delay(250);
  }
}
```


## Opdracht 3

Bouw nu een derde toets, links van de vorige. 

Gebruik nu 3 parallele weerstanden.

![denk](EmojiThinking.png) | Gebruik de seriële monitor om de waarde van de nieuwe knop te bepalen.
:-------------:|:----------------------------------------: 

![denk](EmojiThinking.png) | Welke frequentie krijgt de nieuwe knop?
:-------------:|:----------------------------------------: 
## Oplossing 3



```c++
int speaker_pin = 8;
int piano_pin = A0;
int sensorValue = 0;

void setup()
{
  pinMode(speaker_pin, OUTPUT);
  pinMode(piano_pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = (analogRead(piano_pin));
  Serial.println(sensorValue);
  if (sensorValue > 820)                          //bekijk de Seriële monitor !!
  {
    tone(speaker_pin, 220);
    delay(250);
    noTone(speaker_pin);
    delay(250);
  }
  else if (sensorValue > 680)                          //bekijk de Seriële monitor !!
  {
    tone(speaker_pin, 247);
    delay(250);
    noTone(speaker_pin);
    delay(250);
  }
  else if (sensorValue > 510)                          //bekijk de Seriële monitor !!
  {
    tone(speaker_pin, 247);
    delay(250);
    noTone(speaker_pin);
    delay(250);
  }
}
```
## Opdracht 4

[vierde toets, links van de vorige, met 8 parallele voorschakelweerstanden, nu weer zelf code schrijven]

## Oplossing 4

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

## Opdracht 5

[vijfde toets, rechts van de vorige, met 2 serie voorschakelweerstanden, nu weer zelf code schrijven]

[smiley: tip: de nieuwe waardes worden hoger dan ?384. Het nieuwe if statement moet nu eerst!]

## Oplossing 5
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
