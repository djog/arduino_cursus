// Countdown timer
//
// (C) 2015 Arlette Reneman & Winand Slingenbergh
//
// Released under the GPLv3 license
//
// Adapted from NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      59

const unsigned long factor = (5 *60 * (unsigned long)1000) / 59;
const unsigned long factor2 = (60 * 5 * (unsigned long)1000) / 255;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}


void loop() {

  const int ledpower = millis() / factor2;
  const int n_lampjes = millis() / factor;
  pixels.setPixelColor(n_lampjes, pixels.Color(ledpower , 255 - ledpower, 0));
  pixels.show(); 
  delay(10);
}
