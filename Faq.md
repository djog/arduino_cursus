# Veelgestelde vragen

Dit zijn de veelgestelde vragen.

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

Mocht je nu je code niet kunnen uploaden, door onderstaande error, druk dan op de Arduino reset knop voor het uploaden.

```
avrdude: stk500_getsync(): not in sync: resp=0x00
avrdude: stk500_disable(): protocol error, expect=0x14, resp=0x51
```
