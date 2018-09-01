# Les 20: 1-Pin-7-Weerstanden-In-Serie-Piano

...

\pagebreak

## Les 20: 1-Pin-7-Weerstanden-In-Serie-Piano: Opdracht 1

\pagebreak

## Les 20: 1-Pin-7-Weerstanden-In-Serie-Piano: Oplossing 1

```c++
void setup()
{
  Serial.begin(9600);  
  pinMode(A0, INPUT);
}

void loop()
{
  Serial.println(analogRead(A0));
  delay(1000);
}

// 0
// 213
// 382
// 523
// 650
// 769
// 889
```