# Veelgestelde vragen

Dit zijn de veelgestelde vragen.

## Mag ik games maken?

Jazeker! Sterker nog, het programmeren van games is een van de leukste manieren om electronica en programmeren te leren.

## Mag ik gamen?

Nee. De vrijdagavond is een cursus avond, waarbij leren voorop staat. Gamen draagt niet bij aan het leren programmeren. Heb je *zelf* een spel geprogrammeerd, dan krijg je de ruimte om het spel te laten zien en te laten testen. Het grootste deel van het testen zal buiten de cursustijd gebeuren.

## Debian

### Probleem

In de Arduino IDE is de 'Serial Port' menu-optie grijs.

### Oplossing


Word super-user:

```
su
```

Type het root wachtwoord in. Dan:

```
chmod a+rw /dev/ttyACM0
```

## Linux Mint

### Probleem

In de Arduino IDE is de 'Serial Port' menu-optie grijs.

### Oplossing

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
