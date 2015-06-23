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