# Les 19: 1-pin-7-parallelle_weerstanden-piano

In deze les gaan we een simpele piano maken, die 1 pin gebruikt en 7 parallelle weerstanden.
We bouwen de piano stap voor stap op en testen elke stap apart.

## Opdracht 1

Sluit figuur 'Een pin' aan. Zet de knop in het midden van je breadboard!

```

![Opdracht 1](19_1.png)

[Arduino + 10 kOhm + knop + 10K weerstand]

[knop moet in het midden van het breadboard staan]
```

Zet deze code op je Arduino:

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
  if (analogRead(piano_pin) > ?384)
  {
    tone(piano_pin, ?247, 250);
    delay(250);
  }
}
```

```
Smiley die uitlegt wat '>' betekent 
```

## Opdracht 2

Sluit een tweede knop aan, met twee weerstanden ervoor die parallel staan [dus 5k], zie plaatje

```
plaatje met losse twee weerstanden en knop
```

Bouw een volgende toets van de piano **links** van de eerste. Gebruik deze code:

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
