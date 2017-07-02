# Piano serie

## Piezo aansluiten

## Knop aansluiten

## Tweede knop aansluiten

## Eindopdracht: derde knop aansluiten

![Eindopdracht](Piano_serie.png)

```c++
const int speaker_pin = 8;
const int toets_1_pin = A0;
const int toets_2_pin = A1;
const int toets_3_pin = A2;

void setup()
{
  pinMode(speaker_pin, OUTPUT);
  pinMode(toets_1_pin, INPUT);
  pinMode(toets_2_pin, INPUT);
  pinMode(toets_3_pin, INPUT);
}

void loop()
{
  const int toonlengte = 125;
  int toonhoogte = 0;
  if (digitalRead(toets_1_pin) == HIGH)
  {
    toonhoogte = 131;
  }
  else if (digitalRead(toets_2_pin) == HIGH)
  {
    toonhoogte = 147;
  }
  else if (digitalRead(toets_3_pin) == HIGH)
  {
    toonhoogte = 165;
  }
  tone(speaker_pin, toonhoogte, toonlengte);
  delay(toonlengte);
}
```

 1. Houd knop 3 ingedrukt. Het geluid klinkt hakkelig. Hoe kan dat?
 2. Wat gebeurt er als je twee knoppen indrukt?
 3. Een gewone piano heeft 88 toetsen. Kun je een piano op deze manier bouwen met een Arduino Uno?

## Eindopdracht antwoorden

 1. Omdat de Arduino eerst pin 1, dan pin 2, dan pin 3 leest. Dit lezen kost tijd. In deze tijd is er geen geluid
 2. Je hoort de laagste toon
 3. Ja, want je hebt maar een pin nodig

