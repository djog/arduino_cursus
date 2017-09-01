# 3. Servo motor

Een servo is een motortje die je in een bepaalde hoek kunt zetten.
De meeste servo's kunnen niet rond.
Welke hoeken een servo kan, kun je niet van tevoren weten.
In deze les gaan we de servo motor met de seriele monitor aansturen.
Hiermee kunnen we bepalen welke hoeken een servo aankan.

## Aansluiten

Op het plaatje zie je hoe je een servo aansluit:

![Servo Serial aansluiten](ServoSerial.png)

De draden van de servo motor hebben misschien een andere kleur dan op het plaatje.
In de tabel kun je zien welke kleur wat is.

Kleur|Moet naar
---|---
Zwart|`GND`
Bruin|`GND`
Rood|`5V`

## Code

Gebruik deze code:

```c++
#include <Servo.h>

Servo mijn_servo;

void setup()
{
  Serial.begin(9600);
  mijn_servo.attach(9);
}

void loop()
{
  if (Serial.available())
  {
    const int getal = Serial.parseInt();
    Serial.print("Ik zet de servo op ");
    Serial.println(getal);
    mijn_servo.write(getal);
    delay(1000);
  }
}
```

In deze code zitten veel nieuwe dingen:

 * `Servo mijn_servo`: we maken een variabele met naam `mijn_servo` van het 
   data type `Servo`
 * `mijn_servo.attach(9)`: de servo staat aangeloten op pin 9
 * `if (Serial.available())`: is er een getal ingetypt?
 * `Serial.parseInt()`: lees het getal dat is ingetypt
 * `const int getal`: de variabele met naam `getal` is een heel getal (`int`) dat
   niet meer veranderd kan worden (`const`)
 * `mijn_servo.write(getal)`: zet de servo op een hoek van `getal` graden

## Getallen naar de Arduino sturen

Als je de code op de Arduino hebben gezet, kun je via de `Serial Monitor`
getallen naar de Arduino sturen. Dit kun je zien op het plaatje

![Getallen naar de Arduino sturen](ServoSerialSerial.png)

## Eindopdracht

 * Bepaal het laagste en hoogste getal van een servo motor
 * Bereken het verschil tussen het laagste en hoogste getal


# 3. Servo motor

In de les gaan we een servo aansturen met een potmeter.
Dit is eigenlijk vooral herhaling

![Servo motor](3_servo_motor.jpg)

## Aansluiten

Zie figuur 'Servo motor aansluiten'.

![Servo motor aansluiten](3_servo_motor_blink.png)

De draadjes van de servo hebben misschien andere kleuren:

 * Zwart of bruin: naar `GND`
 * Rood: naar `5V`
 * Geel of oranje: naar `9`

## Code

Hier is code om de servo aan te sturen met de seriele monitor:

```c++
#include <Servo.h>

Servo mijn_servo;

void setup()
{
  Serial.begin(9600);
  mijn_servo.attach(9);
}

void loop()
{
  if (Serial.available())
  {
    const int getal = Serial.parseInt();
    Serial.print("Ik zet de servo op ");
    Serial.println(getal);
    mijn_servo.write(getal);
    delay(1000);
  }
}
```

## Opdracht

 1. Wat is de laagste en hoogste waarde die jouw servo kan hebben?

## Oplossingen

 1. Dit is afhankelijk van de servo

## Potmeter

Sluit nu ook een potmeter aan. De middelste pin moet naar `A0`. Zie figuur 'Servo motor en potmeter'

![Servo motor en potmeter](3_servo_motor_met_potmeter.png)

Gebruik deze code:

```c++
#include <Servo.h>

Servo mijn_servo;

void setup() 
{
  Serial.begin(9600);
  mijn_servo.attach(9);
  pinMode(A0, INPUT);
}

void loop()
{
  mijn_servo.write(
    map(analogRead(A0),0,1024,45,135)
  );
  delay(100);
}
```

In deze code zit iets nieuws: de `map` functie!

```
map(analogRead(A0),0,1024,45,135)
```

In mensentaal is dit:

```
Lieve Arduino,

Uit het eerste stukje ('analogRead(A0)') 
komt een waarde van 0 tot 1024.
Ik wil dat je deze waarde ombouwt, 
zodat deze minstens 45 wordt en maximaal 135.
```

![Mensentaal voor map(analogRead(A0),0,1024,45,135)](3_servo_motor_praatwolkje.png)

## Eindopdracht

Stuur een servo motor perfect aan met een potmeter. 
Gebruik hiervoor de minimum en maximum waarde die je hebt gevonden bij jouw servo motor.


