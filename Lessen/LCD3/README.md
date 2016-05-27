# LCD les 3

Met LCD schermpjes kun je veel dingen doen. In deze les gaan we programmeren.

![ArduinoInvaders is een spel dat werkt met een LCD](ArduinoInvaders.jpg)

## Programma 1: Een smiley programmeren

```
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

int kolom = 0;
int rij = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(1, smiley);
}

void loop() {
  lcd.setCursor(rij, kolom);
  lcd.write(1);
  delay(1000);
}
```

### Opdrachten

 * Sluit een LCD scherm aan, zoals in de vorige les
 * Voer de bovenstaande code in.
   * Wat zie je?
   * Wat betekent `#include <LiquidCrystal.h>`? Tip: haal deze regel maar eens weg
   * Wat betekent `byte`? Tip: wat is een bit? Hoe noem je acht bits?
   * Van `byte smiley[8]`, wat betekent `[8]`? Tip: hoeveel regels komen erna?
   * Van `byte smiley[8]`, wat betekent `smiley`? Tip: kun je dit veranderen naar `poppetje`?
   * Wat betekent `0b` in `0b00000`? Tip: na de `b`, welke getallen zie je wel en niet?
   * Wat betekenen die regels met `0b01010`? Tip: verander eens wat nullen in eentjes en andersom
   * Wat betekent `LiquidCrystal lcd(12, 11, 5, 4, 3, 2)`? Tip: naar welke pinnen gaan de draadjes?
   * Wat betekent `lcd.begin(16, 2)`? Tip: hoeveel tekens kunnen er op je LCD schermpje?
   * Wat betekent `lcd.createChar(1, smiley)`? Tip: waar komt het getal `1` nog meer voor?
   * Wat betekent `lcd.write(1)`? Tip: waar zie je het getal `1` vaker voorkomen?
   * Wat betekent `delay(1000)`? Tip: zie de eerste les!
   * Wat betekent `int kolom = 0`? Hoe lees je dit? Tip: het begint met 'Lieve computer', en een `int` betekent `heel getal`
   * Wat betekent `int rij = 0`? Hoe lees je dit?
   * Wat betekent `lcd.setCursor(rij, kolom)`? Wat vult de computer in bij `rij` en `kolom`? Tip: verander eens de getallen van `kolom` en `rij`


## Programma 2: Een bewegende smiley programmeren

```
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

int kolom = 0;
int rij = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(1, smiley);
}

void loop() {
  ++kolom;
  if (kolom == 17) kolom = 0;
  lcd.clear();
  lcd.setCursor(rij, kolom);
  lcd.write(1);
  delay(1000);
}
```

### Opdrachten

 * Sluit een LCD scherm aan, zoals in de vorige les
 * Upload de bovenstaande code
   * Wat zie je?
   * Wat betekent `++kolom`? Tip: haal deze regel maar eens weg
   * Wat betekent `if (kolom == 17) kolom = 0`? Tip: haal deze regel maar eens weg
   * Wat betekent `lcd.clear()`? Tip 1: haal deze regel maar eens weg. Tip 2: Wat betekent het Engelse woord 'clear'?
   * Wat gebeurt er als ik `if (kolom == 17) kolom = 0` verander naar `if (kolom == 9) kolom = 0`? Doen!
   * Wat gebeurt er als ik `if (kolom == 17) kolom = 0` verander naar `if (kolom == 17) kolom = 9`? Doen!
 * Laat nu de smiley naar rechts en omlaag gaan! Dit ziet er hetzelfde uit als dat de X op en neer gaat op een schermpje met twee rijen

```
1*3*5*7*9*1*3*
*2*4*6*8*0*2*5
```