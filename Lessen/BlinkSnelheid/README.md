# Blink snelheid

Anko had z'n oscilloscoop bij en gemeten hoe snel de volgende versies van `blink` zijn.

## Knipperen, `int led`

```
int led = 12;
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, !digitalRead(led));   // geeft 52.1 kHz
}
```

![52 kHz](DS1Z_52kHz.png)

## Knipperen, `const int led`

```
const int led = 12;
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, !digitalRead(led));   // geeft 52.1 kHz
}
```

![52 kHz](DS1Z_52kHz.png)

## Aanzetten, uitzetten, `int led`

```
int led = 12;
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);               // geeft 86.2 kHz 
  digitalWrite(led, LOW);     
}
```

![86 kHz](DS1Z_86kHz.png)

## Aanzetten, uitzetten, `const int led`

```
const int led = 12;
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);               // geeft 96.1 kHz 
  digitalWrite(led, LOW);     
}
```

![86 kHz](DS1Z_96kHz.png)
