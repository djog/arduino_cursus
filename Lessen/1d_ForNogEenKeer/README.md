# Les 1d: For nog een keer

In deze les gebruiken we meer `for` loops.

## Intro

Bouw dit:

![1d_ForNogEenKeer](1d_ForNogEenKeer.png)

Programmeer dit:

```c++
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(1000);
}
```

## Opdracht

Verander het `setup` gedeelte naar een for loop.

Tip: gebruik:

```c++
  for (int i=2; i<4; ++i) 
  {
    pinMode(i, OUTPUT);
  }
```

## Oplossing

```c++
void setup()
{
  for (int i=2; i<4; ++i) 
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(1000);
}
```

## Opdracht

Laat nu de LEDjes aan gaan met een for loop.

## Oplossing

```c++
void setup()
{
  for (int i=2; i<4; ++i) 
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for (int i=2; i<4; ++i) 
  {
    digitalWrite(i, HIGH);
  }
  delay(1000);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(1000);
}
```

## Opdracht

Laat nu de LEDjes uit gaan met een for loop

## Oplossing

```c++
void setup()
{
  for (int i=2; i<4; ++i) 
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for (int i=2; i<4; ++i) 
  {
    digitalWrite(i, HIGH);
  }
  delay(1000);
  for (int i=2; i<4; ++i) 
  {
    digitalWrite(i, LOW);
  }
  delay(1000);
}
```

## Opdracht

De zes lampjes zitten op pinnen 2 tot en met 7. 
Laat de for loops lopen van 2 tot 8. 
Als het goed is, gaan alle lampjes aan, dan alle lampjes uit.

## Oplossing

```c++
void setup()
{
  for (int i=2; i<8; ++i) 
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for (int i=2; i<8; ++i) 
  {
    digitalWrite(i, HIGH);
  }
  delay(1000);
  for (int i=2; i<8; ++i) 
  {
    digitalWrite(i, LOW);
  }
  delay(1000);
}
```

## Opdracht

Laat nu de lampjes omstebeurt aan en uit gaan, van links naar rechts.
Je hebt hiervoor een for loop nodig.

## Oplossing

```c++
void setup()
{
  for (int i=2; i<8; ++i) 
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for (int i=2; i<8; ++i) 
  {
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
    delay(1000);
  }
}
```

## Opdracht

Laat nu de lampjes omstebeurt aan en uit gaan, van rechts naar links.

Tip: gebruik niet `i`, maar `7 - i`.

## Oplossing

```c++
void setup()
{
  for (int i=2; i<8; ++i) 
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  for (int i=2; i<8; ++i) 
  {
    digitalWrite(7 - i, HIGH);
    delay(1000);
    digitalWrite(7 - i, LOW);
    delay(1000);
  }
}
```

## Eindopdracht

Maak nu een op-en-neer-gaand patroon in de LEDjes:

 * `*`
 * `**`
 * `***`
 * `****`
 * `*****`
 * `******`
 * `******`
 * `*****`
 * `****`
 * `***`
 * `**`
 * `*`
