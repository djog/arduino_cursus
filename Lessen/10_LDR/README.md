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

 * Als je de knop indrukt, gaat de lamp dan uit of aan?



# Aansluiten FSR zonder LED

Eerst sluiten we alleen een FSR aan:

![Stroomschema](4_FSR.png)

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

Vragen:
 * Als je de knop indrukt, gaat de lamp dan uit of aan?



## Opdracht


## Opdracht



## Eindopdracht



