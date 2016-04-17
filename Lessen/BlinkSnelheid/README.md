# Blink snelheid

## Opdracht

Laat een LEDje zo snel mogelijk knipperen.
Meet met een oscilloscoop de snelheid

## Vragen

 * Waarom heb je een oscilloscoop nodig?
 * Maakt het gebruik van `const` uit? Is `#define` sneller ja/nee?
 * Wat is de snelste versie die je kunt maken?

Als je dit hebt geprobeerd, kijk dan hieronder bij de antwoorden.

 * Welke truuks worden er gedaan?

## Antwoorden

Dit zijn de antwoorden gemeten door Anko.

### Knipperen, `int led`

```
int led = 12;
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, !digitalRead(led)); // geeft 52.1 kHz
}
```

![52 kHz](DS1Z_52kHz.png)

### Knipperen, `const int led`

```
const int led = 12;
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, !digitalRead(led)); // geeft 52.1 kHz
}
```

![52 kHz](DS1Z_52kHz.png)

### Knipperen, `#define`

```
#define led 12
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, !digitalRead(led));
}
```

Snelheid onbekend

### Aanzetten, uitzetten, `int led`

```
int led = 12;
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH); // geeft 86.2 kHz 
  digitalWrite(led, LOW);     
}
```

![86 kHz](DS1Z_86kHz.png)

### Aanzetten, uitzetten, `const int led`

```
const int led = 12;
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH); // geeft 96.1 kHz 
  digitalWrite(led, LOW);     
}
```

![86 kHz](DS1Z_96kHz.png)

### Aanzetten, uitzetten, `#define`

```
#define led 12

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  digitalWrite(led, LOW);     
}
```

Snelheid: onbekend

### Direct schrijven naar geheugen

```
void setup() {
  DDRB = B00000100;
  while (1)
  {
    PORTB = B00000100;
    PORTB = B00000000;
  }
}

void loop() {}
```

Snelheid: onbekend