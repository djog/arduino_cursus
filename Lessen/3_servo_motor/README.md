# 3. Servo motor

In de les gaan we een servo aansturen met een potmeter.
Dit is eigenlijk vooral herhaling

# Aansluiten

![Stroomschema](3_servo_motor_blink.png)

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

 * Wat is de laagste en hoogste waarde die jouw servo kan hebben?

## Oplossingen

 * 1. Dit is afhankelijk van de servo

## Potmeter

Sluit nu ook een potmeter aan. De middelste pin moet naar `A0`.

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
```

void loop()
{
  mijn_servo.write(
    map(analogRead(A0),0,1024,45,135)
  );
  delay(100);
}
```

In deze code zit iets nieuws: de `map` functie!


## Eindopdracht

Stuur een servo motor aan met een potmeter.
