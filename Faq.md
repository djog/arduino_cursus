# Veelgestelde vragen

Dit zijn de veelgestelde vragen.

## Ik ben jonger dan acht jaar oud, ben ik welkom?

Ja. We zien wel dat leerlingen veel jonger dan 8 jaar oud electronica en programmeren erg moeilijk vinden. Maar je mag het altijd komen proberen.

## Ik ben ouder dan 28 jaar oud, ben ik welkom?

Ja. Nieuwe volwassenen zullen door de jongeren opgeleid worden (van 18:15-20:00). Dit is het meest leerzaam voor de *jongeren*. Voel je dus vooral welkom. Volwassenen zal daarna vriendelijk gevraagd worden om minstens een van de volgende dingen te gaan doen:
  (1) gave dingen te bouwen om de leerlingen te inspireren 
  (2) assisteren bij de lessen door de leerlingen met hun vragen te helpen
  (3) lessen te geven

Hierbij geldt de regel is dat de kinderen altijd voor gaan. Na 21:00 gaan de kinderen weg, dus er is ook tijd voor onderwijs speciaal voor de volwassenen.

## Ik heb geen [...]. Is dat erg?

Nee, wij hebben wel reserve laptops, Arduino's, electronica, etc.

We zien wel dat het handiger voor de leerlingen is een eigen laptop te hebben. Ook merken we dat leerlingen na zes lessen hun ouders gaan vragen om een Arduino om thuis mee te werken. Wij verkopen een startersetje voor 35 euro voor inkoopsprijs.

## Mag ik games maken?

Jazeker! Sterker nog, het programmeren van games is een van de leukste manieren om electronica en programmeren te leren.

## Mag ik gamen?

Nee. Gamen vinden we nooit goed: niet tijdens de les, niet voor de les, niet in de pauze, niet na de pauze.
De vrijdagavond is een cursus avond, waarbij leren voorop staat. Gamen draagt niet bij aan het leren programmeren. Heb je *zelf* een spel geprogrammeerd, dan krijg je de ruimte om het spel te laten zien en te laten testen. 

## Hoe kan het dat de cursus zo goedkoop is?

Omdat we enkel met vrijwilligers werken.

## Kan zo een goedkope cursus wel goed zijn?

Volgens de leerlingen wel. In de twee enquetes per jaar scoort de cursus gemiddeld een 9 op 10. Misschien omdat de vrijwilligers constant bezig zijn met de cursus te verbeteren...

## Wat is de missie van de cursus?

De missie van De Jonge Onderzoekers is: '[Het] exploiteren van een activiteitencentrum met als doel kinderen op een uitdagende en creatieve manier met techniek en wetenschap in aanraking te laten komen'. De missie van de Arduino cursus heeft veel overlap hiermee. We vinden het belangrijk dat de kinderen iets leren, uitgedaagd worden en hun creativiteit gebruiken om iets te maken. Leerlingen krijgen kort uitleg, werken in het begin een boek door, maar worden ook gestimuleerd elkaar te helpen, zelf les te geven en mee te beslissen.

## Staan jullie ook op festivals?

Jazeker! Klik [hier](Publiciteit/README.md) voor de plaatsen waar we zijn geweest (en foto's van hebben)

## Ik wil een onderdeel kopen. Kan dat?

Jazeker, dat kan bij Peter. Dit zijn de prijzen:

Naam|Verkoopprijs (euro
---|---
Arduino Uno + snoer|15,00
Breadboard|3,50
Set soepele snoertjes male-male|3,00
10 weerstandjes|0,10
Led rood|0,07
led groen|0,07
led geel|0,07
led RGB|0,70
led wit helder|0,25
Drukschakelaar (buttonswitch)|0,30
instelpotmeter (Insteldraaiknopje)|0,30
Servo|4,00
Transistor|0,15
Relais|1,80
Electromotor|1,00
Scheepsschroef|0,20
Luidspreker|0,60
Lichtsensor (LDR)|0,70
Temperatuursensor (NTC)|0,70
Werkboek|4,00
Druksensor|9,50
Set snoertjes male - female|2,00 

Op deze prijzen maken we geen winst. We bieden dit enkel aan als service om leerlingen ook thuis aan de slag te kunnen laten gaan.

## In de Arduino IDE is de 'Serial Port' menu-optie grijs. Ik heb Debian

Word super-user:

```
su
```

Type het root wachtwoord in. Dan:

```
chmod a+rw /dev/ttyACM0
```

## In de Arduino IDE is de 'Serial Port' menu-optie grijs. Ik heb Linux Mint

Zorg dat je komt te behoren to de groep `dialout`:

```
sudo usermod -aG dialout <jouwgebruikersnaam>
```

of, korter:

```
sudo usermod -aG dialout $(whoami) 
```

Bijvoorbeeld:

```
sudo usermod -aG dialout richel
```

Mocht je nu je code niet kunnen uploaden, door onderstaande error, druk dan op de Arduino reset knop voor het uploaden.

```
avrdude: stk500_getsync(): not in sync: resp=0x00
avrdude: stk500_disable(): protocol error, expect=0x14, resp=0x51
```





