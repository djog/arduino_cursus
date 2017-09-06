# 7. DC Motor Met Relais

![LED met transistor](7_dc_motor_met_relais_led.png)

Haal het USB snoer uit de computer. 
Sluit figuur 'LED met transistor' aan.
Doe op het eind het USB snoer weer in de computer.

![Sunglasses](EmojiSunglasses.png) | Haal deze les *altijd* het USB snoer uit je computer als je een schakeling aan sluit.
:-------------:|:----------------------------------------: 

Upload de code van 'Blink' op de Arduino.

![Bowtie](EmojiBowtie.png) | Vergeten hoe dit werkt? Zie les `5. DC motor met transistor`
:-------------:|:----------------------------------------: 

### Vragen 1

 1. Wat doet deze schakeling?
 2. Welke Arduino pin levert de elektriciteit voor het LEDje: pin 13 of 5V? Waarom?
 3. Hoe werkt de schakeling?

\pagebreak

### Oplossingen 1

 1. Als de Arduino spanning op pin 13 zet, gaat het lampje branden
 2. De 5V levert de elektriciteit voor het lampje: deze gaat de linker pin van de transistor in,
    verder door de rechter pin en dan door het lampje. Pin 13 zorgt er enkel voor dat dat kan.
 3. Als de Arduino spanning zet op de middelste pin van de transistor, 
    kan er stroom gaan lopen door de transistor (van linker naar rechterpin) en het LEDje. 
    Daardoor gaat het LEDje branden

## Relais

Een relais (spreek uit: 'relleh') is, net als een transistor, een soort drukknop, die elektronisch
ingedrukt kan worden. Het verschil met de transistor is dat de twee elektronische
stromen elkaar nergens tegen komen.

![Een relais](7_dc_motor_met_relais_relais_echt.png)

![Sunglasses](EmojiSunglasses.png) | Een relais is een drukknop die je elektronisch in kunt drukken
:-------------:|:----------------------------------------: 

![Bowtie](EmojiBowtie.png) | Een relais kan gebruikt worden om meer stroom en spanning te schakelen
:-------------:|:----------------------------------------: 

\pagebreak

![Een eenzaam relais](7_dc_motor_met_relais_relais.png)

Haal het USB snoer uit de computer. 
Sluit figuur 'Een eenzaam relais' aan.
Doe op het eind het USB snoer weer in de computer.

Upload de code van 'Blink' op de Arduino.

### Vragen 2

 1. Wat hoor je? Als je niks hoort, heb je de schakeling fout aangesloten!
 2. Welke Arduino pin levert de elektriciteit voor het relais: pin 13 of 5V? Waarom?

\pagebreak

### Oplossingen 2

 1. Elke second hoor je een tik
 2. De 5V levert de elektriciteit voor het relais: deze gaat de linker pin van de transistor in,
    verder door de rechter pin en dan door het lampje. Pin 13 zorgt er enkel voor dat dat kan.

## Relais met LEDjes

We gaan nu kijken, wat een relais doet.

![Relais met LEDs](7_dc_motor_met_relais_relais_leds.png)

Haal het USB snoer uit de computer. 
Sluit figuur 'Relais met LEDs' aan.
Doe op het eind het USB snoer weer in de computer.

Upload de code van 'Blink' op de Arduino.

### Vragen 3

 1. Wat zie je?
 2. Welke Arduino pin levert de elektriciteit voor het LEDs: pin 13 of 5V? Waarom?
 3. Hoe kan het dat er maar een weerstand nodig is voor twee LEDjes?

\pagebreak

### Oplossingen 3

 1. Elke second hoor je een tik en gaat een andere kleur LED branden
 2. De 5V levert de elektriciteit voor de LEDs: deze gaat de tweede pin van het relais in,
    en komt dan uit de derde of vierde pin
 3. Omdat er stroom komt uit *of* de derde *of* de vierde pin, gaat er altijd precies een LEDje
    branden. Dan is een weerstand genoeg

## Relais met DC motor

Nu komt de magie!

![Relais met DC motor](7_dc_motor_met_relais_relais_dc_motor.png)

Haal het USB snoer uit de computer. 
Sluit figuur 'Relais met DC motor' aan.
Doe op het eind het USB snoer weer in de computer.

Upload de code van 'Blink' op de Arduino.

### Vragen 4

 1. Wat zie je?
 
\pagebreak

### Oplossingen 4

 1. De motor gaat een seconde de eene kant op, dan een seconde de andere kant

### Vragen 5

![Werking](7_dc_motor_met_relais_DPDT-relay.png)

 1. Figuur 'Werking' laat zien hoe het kan dat de motor steeds een andere
    kant op gaat. Probeer jezelf uit te leggen hoe het werkt

![Sunglasses](EmojiSunglasses.png) | Denk hier niet langer dan 5 minuten over na! Dit is een erg moeilijke vraag
:-------------:|:----------------------------------------: 

\pagebreak

### Oplossingen 5

 1. Als de relais aan staat, zijn de relaispinnen 2-3 en 6-7 verbonden. Is de relais
    uit, dan is 2-4 en 6-8 verbonden. Als je de draden volgt, zie je hierdoor dat de eene
    keer de linker kant van de motor op de plus komt, de andere keer op de min kant

## Eindopdracht

 * Laat de motor reageren op een LDR: als er geen licht is, moet de motor linksom draaien, anders rechtsom

![Bowtie](EmojiBowtie.png) | Vergeten hoe je een LDR aansluit? Zie les `9. LDR`
:-------------:|:----------------------------------------: 
