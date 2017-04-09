# Capacitatieve sensoren les 2

Als je meerdere capacitatieve sensoren aan wilt sluiten,
kun je twee pinnen per sensor gebruiken.

In deze les gaan we dat doen.

## Stroomschema

![Stroomschema](CapacitatieveSensoren.png)

Dit is bijna hetzelfde als de vorige les,
alleen nu met twee capacitatieve sensoren.

## Code

Als de bibliotheek is geinstalleerd, kunnen we een capacitatieve sensor maken:

```
#include <CapacitiveSensor.h>

/*
  2                             4 
  |  +--------+     +--------+  |
  +--+ R1     +--+--+ R2     +--+
     +--------+  |  +--------+ 
                 X          

  
  2: Arduino pin 2, de sensor pin
  4: Arduino pin 4, de hulp pin
  R1: weerstand van duizend Ohm (bruin-zwart-rood-goud)
  R2: weerstand van minstens een miljoen Ohm (bruin-zwart-groen-goud)
  X: Hier kun je de draad aanraken

  6                             8
  |  +--------+     +--------+  |
  +--+ R1     +--+--+ R2     +--+
     +--------+  |  +--------+ 
                 X          

  
  6: Arduino pin 6, de sensor pin
  8: Arduino pin 8, de hulp pin
  R1: weerstand van duizend Ohm (bruin-zwart-rood-goud)
  R2: weerstand van minstens een miljoen Ohm (bruin-zwart-groen-goud)
  X: Hier kun je de draad aanraken
 
*/

const int pin_sensor_1 = 2;
const int pin_hulp_1   = 4;
const int pin_sensor_2 = 6;
const int pin_hulp_2   = 8;
const int pin_led      = 13;

CapacitiveSensor mijn_cap_sensor_1 = CapacitiveSensor(pin_hulp_1,pin_sensor_1);        
CapacitiveSensor mijn_cap_sensor_2 = CapacitiveSensor(pin_hulp_2,pin_sensor_2);        

void setup()                    
{
  pinMode(pin_led,OUTPUT);
  Serial.begin(9600);
}

void loop()                    
{
  //Hoe hoger 'samples', hoe nauwkeuriger de sensor meet
  const int samples = 30;

  //Meet de waarde van de sensors
  const int waarde_1 = mijn_cap_sensor_1.capacitiveSensor(samples);
  const int waarde_2 = mijn_cap_sensor_2.capacitiveSensor(samples);

  //Laat de waarde zien in de Serial Monitor
  Serial.println(waarde_1);
  Serial.println(waarde_2);

  //De drempelwaarde bepaalt wanneer het programma denkt dat je de sensor aanraakt
  // - te laag: dan zal het programma vaker denken dat je de sensor aanraakt, terwijl je dat niet doet
  // - te hoog: dan zal het programma minder vaak denken dat je de sensor aanraakt, terwijl je dat wel doet
  const int drempelwaarde = 100;
  
  //Als je de sensor aanraakt, gaat het LEDje op pin 'pin_led' branden
  const bool is_hoog_1 = waarde_1 >= drempelwaarde; 
  const bool is_hoog_2 = waarde_2 >= drempelwaarde; 
  digitalWrite(pin_led,is_hoog_1 && is_hoog_2 ? HIGH : LOW);

  delay(100);
}
```

Dit is wat alles betekent:

 * `const int pin_sensor_1 = 2`: Hiermee zeg je: 'Lieve Arduino, onthoudt een heel getal (`int`). Ik noem dat hele getal `pin_sensor_1`. De begin waarde van `pin_sensor_1` is twee. `pin_sensor_1` kan niet veranderen (`const`)'
 * `const int pin_hulp_1 = 4`: Hiermee zeg je: 'Lieve Arduino, onthoudt een heel getal (`int`). Ik noem dat hele getal `pin_hulp_1`. De begin waarde van `pin_hulp_1` is vier. `pin_hulp_1` kan niet veranderen (`const`)'
 * `const int pin_sensor_2 = 6`: Hiermee zeg je: 'Lieve Arduino, onthoudt een heel getal (`int`). Ik noem dat hele getal `pin_sensor_2`. De begin waarde van `pin_sensor_2` is zes. `pin_sensor_2` kan niet veranderen (`const`)'
 * `const int pin_hulp_2 = 4`: Hiermee zeg je: 'Lieve Arduino, onthoudt een heel getal (`int`). Ik noem dat hele getal `pin_hulp_2`. De begin waarde van `pin_hulp_2` is acht. `pin_hulp_2` kan niet veranderen (`const`)'
 * `const int pin_led = 13`: Hiermee zeg je: 'Lieve Arduino, onthoudt een heel getal (`int`). Ik noem dat hele getal `pin_led`. De begin waarde van `pin_led` is dertien. `pin_led` kan niet veranderen (`const`)'
 * `CapacitiveSensor mijn_cap_sensor_1 = CapacitiveSensor(pin_hulp_1,pin_sensor_1)`: Hiermee zeg je: 'Lieve Arduino, onthoudt een CapacitiveSensor. Ik noem die CapacitiveSensor `mijn_cap_sensor_1`. De begin waarde van `mijn_cap_sensor` is `CapacitiveSensor(pin_hulp_1,pin_sensor_1)`'.
 * `CapacitiveSensor mijn_cap_sensor_2 = CapacitiveSensor(pin_hulp_2,pin_sensor_2)`: Hiermee zeg je: 'Lieve Arduino, onthoudt een CapacitiveSensor. Ik noem die CapacitiveSensor `mijn_cap_sensor_2`. De begin waarde van `mijn_cap_sensor_2` is `CapacitiveSensor(pin_hulp_2,pin_sensor_2)`'.
 * `void setup() {}`: de `setup` function zorgt ervoor dat alles tussen de accolades (`{` en `}`) een keer gedaan wordt
 * `pinMode(pin_led, OUTPUT)`: 'Lieve Arduino, het soort pin (`pinMode`) dat `pin_led` is, is een uitgang (`OUTPUT`)'	
 * `Serial.begin(9600)`: 'Lieve Arduino, praat met een snelheid van 9600 tekens per seconde met de seriele monitor'
 * `void loop() {}`: de `function` function zorgt ervoor dat alles tussen de accolades (`{` en `}`) de rest van de tijd herhaald wordt
 * `const int samples = 30`: Hiermee zeg je: 'Lieve Arduino, onthoudt een heel getal (`int`). Ik noem dat hele getal `samples`. De begin waarde van `samples` is dertig. `samples` kan niet veranderen (`const`)'
 * `const int waarde_1 = mijn_cap_sensor_1.capacitiveSensor(samples)`: Hiermee zeg je: 'Lieve Arduino, onthoudt een heel getal (`int`). Ik noem dat hele getal `waarde_1`. De begin waarde van `waarde_1` is wat je leest uit de eerste capacitatieve sensor (`mijn_cap_sensor_1.capacitiveSensor(samples)`). `waarde_1` kan niet veranderen (`const`)'
 * `const int waarde_2 = mijn_cap_sensor_2.capacitiveSensor(samples)`: Hiermee zeg je: 'Lieve Arduino, onthoudt een heel getal (`int`). Ik noem dat hele getal `waarde_2`. De begin waarde van `waarde_2` is wat je leest uit de tweede capacitatieve sensor (`mijn_cap_sensor_2.capacitiveSensor(samples)`). `waarde_2` kan niet veranderen (`const`)'
 * `Serial.println(waarde_1)`: 'Lieve Arduino, laat de waarde van `waarde_1` op de seriele monitor zien'
 * `Serial.println(waarde_2)`: 'Lieve Arduino, laat de waarde van `waarde_2` op de seriele monitor zien'
 * `const int drempelwaarde = 100`: Hiermee zeg je: 'Lieve Arduino, onthoudt een heel getal (`int`). Ik noem dat hele getal `drempelwaarde`. De begin waarde van `drempelwaarde` is honderd. `drempelwaarde` kan niet veranderen (`const`)'
 * `const bool is_hoog_1 = waarde_1 >= drempelwaarde`: 'Lieve Arduino, onthoudt een boolean (`bool`). Ik noem die boolean `is_hoog_1`. De beginwaarde van `is_hoog_1` is de uitkomst van de test `waarde_1 >= drempelwaarde`'. `is_hoog_1` kan niet veranderen (`const`)'
 * `const bool is_hoog_2 = waarde_2 >= drempelwaarde`: 'Lieve Arduino, onthoudt een boolean (`bool`). Ik noem die boolean `is_hoog_2`. De beginwaarde van `is_hoog_2` is de uitkomst van de test `waarde_2 >= drempelwaarde`'. `is_hoog_2` kan niet veranderen (`const`)'
 * `digitalWrite(pin_led,is_hoog_1 && is_hoog_2 ? HIGH : LOW)`: 'Lieve Arduino, schrijf een `HIGH` of `LOW` (`digitalWrite`) naar de pin `pin_led`. Als beide `is_hoog_1` en `is_hoog_2 waar zijn (`is_hoog_1 && is_hoog_2`), dan is dat `HIGH`, anders is het `LOW`'
 * `delay(100)`: 'Lieve Arduino, je mag honderd milliseconden wachten'

## Vragen

 * Bouw het schema en opload de code. Test de machine. Wat doet de machine?
 * In de code, verander de waarde van `drempelwaarde`. Wat gebeurt er?
 * In de code, verander de waarde van `samples`. Wat gebeurt er?
 * Vervang de weerstand van een miljoen Ohm door een weerstand van tien miljoen Ohm (bruin, zwart, blauw, goud). Wat doet de machine anders? Wat is nu een goede waarde voor `drempelwaarde` en `samples`?
 * Haal de adapter uit je laptop. Wat doet de machine?

## Eindopdracht

 * Gebruik twee capacitatieve sensoren om twee LEDjes aan te sturen
 * De eerste LED gaat aan als je de eerste capacitatieve sensor aanraakt
 * De tweede LED gaat uit als je de tweede capacitatieve sensor aanraakt
