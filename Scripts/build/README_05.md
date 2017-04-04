# Les 1d: For nog een keer

## For loop nog een keer

For loops zijn handig om code korter op te schrijven:

```c++
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
```

Hier staat een for-loop die hetzelfde doet:

```c++
for (int pin=2; pin<8; ++pin)
{
  pinMode(pin, OUTPUT);
}
```

## Bouwen

Bouw eerst dit stroomschema:

![1d_ForNogEenKeer](1d_ForNogEenKeer.png)

Nu kun je de opdrachten gaan doen!

## Nadenken

Denk na over de volgende stukjes code.

### Opdracht 1

Maak deze code korter met een for-loop:

```c++
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
```

### Oplossing 1

Er moet een getal gaan lopen van twee tot en met zeven. Of:
van twee tot acht. Dit getal moet lopen van twee tot acht
in stapjes van een. Laten we dit getal `i` noemen.

Pin `i` moet `HIGH` gezet worden met `digitalWrite`.

Dat gaat zo:

```c++
for (int i=2; i<8; ++i)
{
  digitalWrite(i, HIGH);
}
```

### Opdracht 2

Maak deze code korter met een for-loop:

```c++
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
```

### Oplossing 2

Er moet een getal gaan lopen van twee tot en met zeven. Of:
van twee tot acht. Dit getal moet lopen van twee tot acht
in stapjes van een. Laten we dit getal `i` noemen.

Pin `i` moet `LOW` gezet worden met `digitalWrite`.

Dat gaat zo:

```c++
for (int i=2; i<8; ++i)
{
  digitalWrite(i, LOW);
}
```

### Opdracht 3

Maak deze code korter met een for-loop:

```c++
digitalWrite(2, LOW);
delay(100);
digitalWrite(3, LOW);
delay(100);
digitalWrite(4, LOW);
delay(100);
digitalWrite(5, LOW);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(7, LOW);
delay(100);
```

### Oplossing 3

Er moet een getal gaan lopen van twee tot en met zeven. Of:
van twee tot acht. Dit getal moet lopen van twee tot acht
in stapjes van een. Laten we dit getal `i` noemen.

Pin `i` moet `LOW` gezet worden met `digitalWrite`. Daarna
moet er altijd honderd milliseconden gewacht worden.

Dat gaat zo:

```c++
for (int i=2; i<8; ++i)
{
  digitalWrite(i, LOW);
  delay(100);
}
```

## Omlaag tellen

Meestal gaan `for` loops omhoog.
Maar soms wil je dat deze *omlaag* telt.
Dat kan op meer manieren.
Wij gebruiken de manier waarbij een `for`
loop omhoog blijft tellen. 
De `for` loop telt omhoog, maar we gebruiken
de `i` in een min som.

Bijvoorbeeld deze code:

```c++
digitalWrite(3, HIGH);
digitalWrite(2, HIGH);
digitalWrite(1, HIGH);
digitalWrite(0, HIGH);
```

Hiervan maken we:

```c++
for (int i=0; i<4; ++i)
{
  digitalWrite(3 - i, HIGH);
}
```

We laten `i` lopen van nul tot vier in stapjes van een.
De pin die we aan doen is `3 - i`. De uitkomsten zijn dan:

 * `3 - 0 = 3`
 * `3 - 1 = 2`
 * `3 - 2 = 1`
 * `3 - 3 = 0`

En dat is precies wat we wilden!

### Opdracht 4

Maak deze code korter met een for-loop:

```c++
digitalWrite(7, LOW);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(5, LOW);
delay(100);
digitalWrite(4, LOW);
delay(100);
digitalWrite(3, LOW);
delay(100);
digitalWrite(2, LOW);
delay(100);
```

### Oplossing 3

Er moet een getal gaan lopen van zeven tot en met twee. 
Dit kunnen we doen door eerst `7 - 0`, dan `7 - 1`, dan `7 - 2` te doen.
Het getal dat eraf moet loopt van nul tot zes, in stapjes van een. 
Laten we dit getal `7 - i` noemen.

Pin `i` moet `LOW` gezet worden met `digitalWrite`. Daarna
moet er altijd honderd milliseconden gewacht worden.

Dat gaat zo:

```c++
for (int i=0; i<6; ++i)
{
  digitalWrite(7 - i, LOW);
  delay(100);
}
```

### Opdracht 5

Maak deze code korter met twee for-loops:

```c++
digitalWrite(2, HIGH);
delay(100);
digitalWrite(3, HIGH);
delay(100);
digitalWrite(4, HIGH);
delay(100);
digitalWrite(5, HIGH);
delay(100);
digitalWrite(6, HIGH);
delay(100);
digitalWrite(7, HIGH);
delay(100);
digitalWrite(7, LOW);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(5, LOW);
delay(100);
digitalWrite(4, LOW);
delay(100);
digitalWrite(3, LOW);
delay(100);
digitalWrite(2, LOW);
delay(100);
```

### Oplossing 5

Nu moeten er twee `for` loops na elkaar komen.

```c++
for (int i=2; i<8; ++i)
{
  digitalWrite(i, HIGH);
  delay(100);
}
for (int i=0; i<6; ++i)
{
  digitalWrite(8-i, HIGH);
  delay(100);
}
```

## Programmeren

Een leerling heeft deze code geschreven:

```c++
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(100);
  digitalWrite(3, HIGH);
  delay(100);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(5, HIGH);
  delay(100);
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(3, LOW);
  delay(100);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(5, LOW);
  delay(100);
  digitalWrite(6, LOW);
  delay(100);
  digitalWrite(7, LOW);
  delay(100);
}
```

 * Kopieer deze code en kijk wat er gebeurt
 * Maak de code korter. Tip: gebruik drie for-loops

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
