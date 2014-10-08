#include "SevenSeg.h"

// Initializes 7 seg display SevenSeg(int pinSegA, int pinSegB, int pinSegC, int pinSegD, int pinSegE, int pinSegF, int pinSegG, int pinDot, boolean isCathode)
SevenSeg MySevenSeg = SevenSeg(1,2,3,4,5,6,7,8, true); // Enter correct pin numbers. Default: isCathode = true

void setup() {}

void loop() {
  MySevenSeg.writeDigit(1); // Usage: (0..9)
  MySevenSeg.clearDisplay();
  
  MySevenSeg.writeDigit(8);
  MySevenSeg.clearDisplay();
  
  MySevenSeg.countFromTo(9,2,500); // Usage: (firstDigit, lastDigit, delayTime). Default: delayTime = 1000 (ms) 
  MySevenSeg.clearDisplay(3000); // Usage: (delayTime). Default: delayTime = 1000 (ms) 
}
