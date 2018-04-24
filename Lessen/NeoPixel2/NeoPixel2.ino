#include <Adafruit_NeoPixel.h>

const int pin_ledstrip = 6;
const int aantal_neopixels = 60;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(
  aantal_neopixels, 
  pin_ledstrip, 
  NEO_GRB + NEO_KHZ800
);

void setup() 
{
  pixels.begin();
}

void loop() 
{
  for(int i=0;i != aantal_neopixels; ++i)
  {
    const int rood_waarde = random(64);
    const int groen_waarde = random(64);
    const int blauw_waarde = random(64);
    pixels.setPixelColor(i, pixels.Color(rood_waarde,groen_waarde,blauw_waarde));
    
    pixels.show();
    delay(10);

  }
}
