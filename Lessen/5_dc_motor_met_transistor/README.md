# 5. DC Motor met Transistor

![Pas op! Zie 'Waarschuwing'](5_dc_motor_met_transistor_waarschuwing.png)

![Sunglasses](EmojiSunglasses.png) | Haal deze les *altijd* de USB snoer uit je computer als je een schakeling aan sluit.
:-------------:|:----------------------------------------: 

![Bowtie](EmojiBowtie.png) | Anders gaat de computer misschien stuk!
:-------------:|:----------------------------------------: 

## LED met drukknop

![LED met drukknop](5_dc_motor_met_transistor_led_drukknop.png)

Haal de USB uit de computer. 
Sluit dan figuur 'LED met drukknop' aan. 
Doe op het eind de USB weer in de computer.

### Vragen 1

 1. Wat doet deze schakeling?
 2. Wie levert de electriciteit voor het LEDje: de batterijen of de Arduino? Waarom?
 3. Hoe moet je de Arduino programmeren?
 4. Hoe werkt de schakeling?

\pagebreak

### Oplossingen 1

 1. Als je het knopje indrukt, gaat het lampje branden
 2. De batterijen, omdat de plus van de batterijen aangesloten is op de plus van het LEDje
 3. Hoe je de Arduino ook programmeert, de schakeling gedraagt zich altijd hetzelfde
 4. Als je de knop indrukt, kan er stroom gaan lopen door de knop en het LEDje. Daardoor gaat het LEDje branden

## LED met transistor

Een transistor is een soort drukknop.
In plaats dat je een transistor met je vinger indrukt,
zet je er electrische spanning op.
Als er spanning op staat, dan kan er stroom door de transistor.

![Sunglasses](EmojiSunglasses.png) | Een transistor is een soort drukknop, die je met electriciteit in kunt drukken
:-------------:|:----------------------------------------: 

![Bowtie](EmojiBowtie.png) | Met een transistor kun je componenten aansluiten die meer stroom nodig hebben
:-------------:|:----------------------------------------: 

![LED met transistor](5_dc_motor_met_transistor_led_transistor.png)

Haal de USB uit de computer. 
Sluit figuur 'LED met transistor' aan.
Doe op het eind de USB weer in de computer.

Upload de code van 'Blink' op de Arduino.

### Vragen 2

 1. Wat doet deze schakeling?
 2. Wie levert de electriciteit voor het LEDje: de batterijen of de Arduino? Waarom?
 3. Hoe werkt de schakeling?

\pagebreak

### Oplossingen 2

 1. Als de Arduino spanning op pin 13 zet, gaat het lampje branden
 2. De batterijen, omdat de plus van de batterijen aangesloten is op de plus van het LEDje
 3. Als de Arduino spanning zet op de middelste pin van de transistor, 
    kan er stroom gaan lopen door de transistor (van linker naar rechterpin) en het LEDje. 
    Daardoor gaat het LEDje branden

## DC motor met drukknop

Een DC motor is een motor die beide kanten rond kan draaien. De Arduino, maar ook batterijen, leveren
gelijkspanning.

![Sunglasses](EmojiSunglasses.png) | DC is een Engelse afkorting voor 'Direct Current': gelijkspanning. 
:-------------:|:----------------------------------------: 

![Bowtie](EmojiBowtie.png) | Een DC motor wordt ook een gelijkspanningsmotor genoemd
:-------------:|:----------------------------------------: 

![DC motor met drukknop](5_dc_motor_met_transistor_motor_drukknop.png)

\pagebreak

We gebruiken twee nieuwe componenten: een diode en een condensator. 
Deze zijn nodig omdat een DC motor ook electriciteit kan maken (!).
Deze electriciteit kan je computer stukmaken. 

![Computer](EmojiComputer.png) | ![Smiley](EmojiSmiley.png)
:-------------:|:----------------------------------------: 
![Diode](5_dc_motor_met_transistor_diode.png) | Diode, een eenrichtingsweg voor electriciteit
![Condensator](5_dc_motor_met_transistor_condensator.png) | Condensator, een soort batterij die snel op- en ontlaad

![Sunglasses](EmojiSunglasses.png) | De diode en condensator zijn nodig omdat een DC motor ook electriciteit kan maken (!).
:-------------:|:----------------------------------------: 

Haal de USB uit de computer. 
Sluit figuur 'DC motor met drukknop' aan.
Doe op het eind de USB weer in de computer.

### Vragen 3

 1. Wat doet deze schakeling?
 2. Wie levert de electriciteit voor het LEDje: de batterijen of de Arduino? Waarom?
 3. Hoe moet je de Arduino programmeren?
 4. Hoe werkt de schakeling?

\pagebreak

### Oplossingen 3

 1. Als je het knopje indrukt, gaat het motortje draaien
 2. De batterijen, omdat de plus van de batterijen aangesloten is op de plus van het LEDje
 3. Hoe je de Arduino ook programmeert, de schakeling gedraagt zich altijd hetzelfde
 4. Als je de knop indrukt, kan er stroom gaan lopen door de knop en het motortje. Daardoor gaat het motortje draaien

## DC motor met transistor

![DC motor met transistor](5_dc_motor_met_transistor_motor_transistor.png)

Haal de USB uit de computer. 
Sluit figuur 'DC motor met transistor' aan.
Doe op het eind de USB weer in de computer.

Upload de code van 'Blink' op de Arduino.

### Vragen 4

 1. Wat doet deze schakeling?
 2. Wie levert de electriciteit voor het LEDje: de batterijen of de Arduino? Waarom?
 3. Hoe werkt de schakeling?

\pagebreak

### Oplossingen 4

 1. Als de Arduino spanning op pin 13 zet, gaat het motortje draaien
 2. De batterijen, omdat de plus van de batterijen aangesloten is op de plus van het LEDje
 3. Als de Arduino spanning zet op de middelste pin van de transistor, 
    kan er stroom gaan lopen door de transistor (van linker naar rechterpin) en het motortje. 
    Daardoor gaat het motortje draaien

## Eindopdracht

Laat de motor reageren op een LDR: als er geen licht is, moet de motor gaan draaien

![Bowtie](EmojiBowtie.png) | Vergeten hoe je een LDR aansluit? Zie les `9. LDR`
:-------------:|:----------------------------------------: 
