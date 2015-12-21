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
