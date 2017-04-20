# 4. FSR met servo

In deze les sturen we een servo aan met een FSR.

## Aansluiten FSR zonder servo

Eerst sluiten we alleen een FSR aan:

![FSR](4_FSR_met_servo_zonder_servo.png)

Tip: is er geen FSR, gebruik dan een LDR

Let op, het weerstandje is tienduizend Ohm (bruin-zwart-oranje-goud).

## Code: lezen FSR met seriele monitor

Met deze code meten we de waarde van de FSR:

```c++
void setup() 
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(analogRead(A0));
  delay(100);
}
```

Dit doet de code:

 * In de `setup` functie gebeuren twee dingen
   * `pinMode(A0, INPUT)`: de pin `A0` is een pin die leest, een input
   * `Serial.begin(9600)`: de seriele monitor stuurt 9600 bits ('nullen en enen') per seconde
 * In de `loop` functie gebeuren twee dingen
   * `Serial.println(analogRead(A0))`: lees de pin `A0` uit en schrijf deze naar de seriele monitor
   * `delay(100)`: wacht honderd milliseconden

## Opdrachten

 * 1. Upload het programma. In de Arduino IDE, klik rechtsboven op 'Seriele Monitor'. Wat zie je?
 * 2. Druk de FSR in met je vingers (of, met een LDR: houd je vinger boven de LDR) 
      terwijl je de seriele monitor bekijkt. Wat zie je?
 * 3. Verander `Serial.println` naar `Serial.print`. Wat zie je?
 * 4. Verander de tekst `Serial.begin(9600)` naar `Serial.begin(4800)`. Wat zie je? Waarom?
 * 5. Haal de draad naar `A0` weg. Ja, haal de draad tussen `A0` en de LDR weg. 
      Kijk op de seriele monitor. Wat zie je?

## Oplossingen

 * 1. Je ziet een getal van nul tot 1024, afhankelijk van de waarde van de FSR
 * 2. Je zit de getallen veranderen
 * 3. Alle getallen komen na elkaar
 * 4. Nu laat de seriele monitor onleesbare tekst zien. Dit komt omdat de Arduino langzamer tekst
      stuur naar je computer (4800), dan je computer de tekst leest (9600)
 * 5. Nu zie je het getal willekeurig veranderen. Dit wordt een zwevende input genoemd

## Aansluiten FSR met servo

Nu sluiten we ook een servo aan. Als je wilt spieken: zie figuur 'Aansluiten FSR met servo'.

![Aansluiten FSR met servo](4_FSR_met_servo.png)

De draadjes van de servo hebben misschien andere kleuren:

 * Zwart of bruin: naar `GND`
 * Rood: naar `5V`
 * Geel of oranje: naar `9`

### Reageren op FSR

Nu gaan we de servo laten reageren op de FSR:

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

### Eindopdracht

Zorg dat de servo perfect reageert op de FSR. Je zult zelf de minimum en maximumwaarde uit moeten vinden.