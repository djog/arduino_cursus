# 4. FSR

Met een FSR kun je kracht meten. FSR betekent 'Force Sensitive Resitor'.
Dit is Engels voor 'kracht gevoelige weerstand'.

In deze les leer je:

 * Wat de seriele monitor is
 * Hoe je een FSR gebruikt

# Alleen Arduino aansluiten

Eerst sluiten we alleen een Arduino aan:

![](4_FSR_niks.png)

Ik denk dat dit wel moet lukken :-)

# Code: Seriele monitor

```
void setup() 
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Hallo");
  delay(1000);
}
```

Dit doet de code
 * In de `setup` functie gebeurt een ding:
   * `Serial.begin(9600)`: de seriele monitor 'praat' met een snelheid van 9600 (bits per seconde)
 * In de `loop` functie gebeuren twee dingen:
   * `Serial.println("Hallo")`: de tekst 'Hallo' wordt naar de seriele monitor gestuurd
   * `delay(1000)`: wacht duizend milliseconden

## Opdrachten

![De seriele monitor zit hier](4_FSR_SerialMonitor.png)

![De seriele monitor met getallen](4_FSR_SerialMonitorMetGetallen.png)

 * 1. Upload het programma. In de Arduino IDE, klik rechtsboven op 'Seriele Monitor'. Wat zie je?
 * 2. Kun je de tekst veranderen naar 'Hallo Richel' (of je eigen naam?)
 * 3. Verander `Serial.println` naar `Serial.print`. Wat zie je?
 * 4. Verander de tekst `Serial.begin(9600)` naar `Serial.begin(4800)`. Wat zie je? Waarom?

## Oplossingen

 * 1. De seriele monitor laat elke second een extra regel zien, met de tekst 'Hallo'
 * 2. Verander de regel `Serial.println("Hallo");` naar `Serial.println("Hallo Richel");`
 * 3. De woorden komen na elkaar, in plaats van onder elkaar
 * 4. Nu laat de seriele monitor onleesbare tekst zien. Dit komt omdat de Arduino langzamer tekst
      stuur naar je computer (4800), dan je computer de tekst leest (9600)

# Aansluiten FSR zonder LED

Eerst sluiten we alleen een FSR aan:

![Stroomschema](4_FSR.png)

Tip: is er geen FSR, gebruik dan een LDR

Let op, het weerstandje is tienduizend Ohm (bruin-zwart-oranje-goud).

## Code: lezen FSR met seriele monitor

Met deze code meten we de waarde van de FSR:

```
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

Dit doet de code

 * In de `setup` functie gebeuren twee dingen
   * `pinMode(A0, INPUT)`: de pin `A0` is een pin die leest, een input
   * `Serial.begin(9600)`: de seriele monitor
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

# Aansluiten FSR met LED

Nu sluiten we ook een LED aan:

![Stroomschema](4_FSR_met_LED.png)

Let op:

 * het weerstandje aan de LED is duizend Ohm (bruin-zwart-rood-goud).
 * het weerstandje aan de FSR is tienduizend Ohm (bruin-zwart-oranje-goud).

## Reageren op FSR

Nu gaan we het LEDje laten reageren op de LED:

```
void setup() 
{
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (analogRead(A0) < 512)
  {
    digitalWrite(13, HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
  delay(100);
}
```

Dit doet de code

 * In de `setup` functie gebeuren drie dingen
   * `pinMode(A0, INPUT)`: de pin `A0` is een pin die leest, een input
   * `Serial.begin(9600)`: de seriele monitor
 * In de `loop` functie gebeuren twee dingen
   * `Serial.println(analogRead(A0))`: lees de pin `A0` uit en schrijf deze naar de seriele monitor
   * `delay(100)`: wacht honderd milliseconden


## Opdracht

## Eindopdracht

TODO

