# Veelgestelde vragen

Dit zijn de veelgestelde vragen.

## Hoe ziet de cursus eruit?

Voor een sfeerimpressie, zie [foto's van onze leerlingen, lessen en festivalbezoeken](Fotos/README.md)

## Ik ben jonger dan acht jaar oud, ben ik welkom?

Ja. We zien wel dat leerlingen veel jonger dan 8 jaar oud electronica en programmeren erg moeilijk vinden. 
Maar je mag het altijd komen proberen.

## Ik ben ouder dan 18 jaar oud, ben ik welkom?

Ja. Nieuwe volwassenen zullen door de jongeren opgeleid worden (van 18:15-20:00). 
Dit is het meest leerzaam voor de *jongeren*. 
Voel je dus vooral welkom. 
Volwassenen zal daarna vriendelijk gevraagd worden om minstens een van de volgende dingen te gaan doen:

  1. gave dingen te bouwen om de leerlingen te inspireren 
  2. assisteren bij de lessen door de leerlingen met hun vragen te helpen
  3. lessen te geven

Hierbij geldt de regel is dat de kinderen altijd voor gaan. 
Na 21:00 gaan de kinderen weg, dus er is ook tijd voor onderwijs speciaal voor de volwassenen.

## Ik heb geen [...]. Is dat erg?

Nee, wij hebben wel reserve laptops, Arduino's, electronica, etc.

We zien wel dat het handiger voor de leerlingen is een eigen laptop te hebben. 
Ook merken we dat leerlingen na zes lessen hun ouders gaan vragen om een Arduino om thuis mee te werken. 

## Mag ik games maken?

Jazeker! Sterker nog, het programmeren van games is een van de leukste manieren om electronica en programmeren te leren.

## Mag ik gamen?

Nee. Gamen vinden we nooit goed: niet tijdens de les, niet voor de les, niet in de pauze, niet na de pauze.
De vrijdagavond is een cursus avond, waarbij leren voorop staat. 
Gamen draagt niet bij aan het leren programmeren. 

Heb je *zelf* een spel geprogrammeerd, dan krijg je de ruimte om het spel te laten zien en te laten testen. 

## Waar ga ik zitten?

In de kantine, zoals iedereen.

Nieuwere leerlingen zitten vaker bij het schoolbord in de buurt, maar ook dat hoeft niet.

## Wie stel ik een vraag?

  * Zit er een leerling naast je? Zo ja, dan hij/zij.
  * Zit er een leerling aan je tafel? Zo ja, dan hij/zij
  * Als er niemand is of niemand is die het weet, vraag het dan een volwassene

## Waar staan de lessen?

[In de map Lessen](Lessen/README.md).

## Wat als er een nieuwe leerling binnenkomt?

 * De gastheer/gastvrouw vangt hem/haar op:
    * Jas ophangen
    * Naam op de lijst zetten
    * Koppelen aan een leerling die hem/haar op wilt starten: ze gaan dan aan de grote tafel zitten

## Welke vrijwilligers zijn er?

### Anko

`[Hier een foto van Anko]`

Anko zit vooral met de Nano's in de kantine.
Anko helpt je als je zelf of met anderen aan een project wilt werken

### Anton

`[Hier een foto van Anton]`

Anton helpt ons met Arduino, maar ook is hij handig met Lego Mindstorms.
Hij is meestal in de kantine te vinden, en helpt je graag met je vragen.

### [Richel](https://github.com/richelbilderbeek)

![Richel](Raw/Richel.png)

Richel programmeert sinds zijn achtste. Hij is de meest ervaren en belezen programmeur, vooral in C++.
Richel is vooral geinteresseerd in onderwijs en heeft de lerarenopleiding aan de universiteit afgerond.
Zijn werk is te zien op [zijn website met meer dan 3900 pagina's](http://richelbilderbeek.nl) 
en [meer dan 750 GitHub repositories](https://github.com/richelbilderbeek?tab=repositories).

Richel is eindverantwoordelijk voor de Arduino cursus. Richel geeft vooral les aan de Uno's en Mega's.

### [Martin](https://github.com/martinpaulissen)

![Martin](Raw/Martin.jpg)

Martin is begonnen met programmeren tijdens zijn studie aan de Technische Universiteit van Delft. 
Dat was 40 jaar geleden. Bij de KPN heeft hij een landelijk dekkend 
computernetwerk gebouwd en was een van de medeoprichters van het 
Telematica Lab van de KPN, zeg maar een soort Jonge Onderzoekers, 
maar dan voor volwassenen. Daarna hielp hij KPN en andere bedrijven hun ICT 
op orde te krijgen. Nu bouwt hij interactieve websites, waar gebruikers kunnen 
inloggen en zaken als vacatures en activiteiten kunnen bekijken en boeken. 
En sinds kort ook actief met Arduino. 

Martin houdt ervan nieuwe dingen te ontdekken en anderen daarin te 
stimuleren en te begeleiden. En Arduino biedt daarvoor heel veel mogelijkheden.
Martin's lijfspreuk is: Maak alles zo eenvoudig mogelijk, 
maar niet eenvoudiger. (naar Einstein)

Martin leidt de Nano's.

## Hoe kan het dat de cursus zo goedkoop is?

Omdat we enkel met vrijwilligers werken.

## Kan zo een goedkope cursus wel goed zijn?

Volgens de leerlingen wel. In de twee enquetes per jaar scoort de cursus gemiddeld een 9 op 10. 
Misschien omdat de vrijwilligers constant bezig zijn met de cursus te verbeteren...

## Wat is de missie van de cursus?

De missie van De Jonge Onderzoekers is: '[Het] exploiteren van een activiteitencentrum met als doel kinderen op een uitdagende en creatieve manier met techniek en wetenschap in aanraking te laten komen'. De missie van de Arduino cursus heeft veel overlap hiermee. We vinden het belangrijk dat de kinderen iets leren, uitgedaagd worden en hun creativiteit gebruiken om iets te maken. Leerlingen krijgen kort uitleg, werken in het begin een boek door, maar worden ook gestimuleerd elkaar te helpen, zelf les te geven en mee te beslissen.

## Staan jullie ook op festivals?

Jazeker! Klik [hier](Publiciteit/README.md) voor de plaatsen waar we zijn geweest en foto's van hebben.

## In de Arduino IDE is de 'Serial Port' menu-optie grijs. Ik heb Lubuntu Bionic Beaver

```
sudo add-apt-repository ppa:webupd8team/java
sudo apt update
sudo apt install oracle-java8-set-default
```

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
