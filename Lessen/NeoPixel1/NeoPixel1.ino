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

int welk_ledje = 0;
int roodwaarde = 0;
int groenwaarde = 0;
int blauwwaarde = 0;

void loop() 
{
  pixels.setPixelColor(welk_ledje, pixels.Color(roodwaarde, groenwaarde, blauwwaarde));
  pixels.show();
  delay(100);
  welk_ledje = welk_ledje + 1; 
  roodwaarde = roodwaarde + 2;
  groenwaarde = groenwaarde + 4;
  blauwwaarde = blauwwaarde + 3;
  if (roodwaarde > 64)
  {
    roodwaarde = 0;
  }
  if (groenwaarde > 64)
  {
    groenwaarde = 0;
  }
  if (blauwwaarde > 64)
  {
    blauwwaarde = 0;
  }
  if (welk_ledje >= aantal_neopixels)
  {
    welk_ledje = 0;
  }
}

