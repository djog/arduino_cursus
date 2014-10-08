#include "SevenSeg.h"

// Initializes 7 seg display SevenSeg(int pinSegA, int pinSegB, int pinSegC, int pinSegD, int pinSegE, int pinSegF, int pinSegG, int pinDot, boolean isCathode)
SevenSeg MySevenSeg = SevenSeg(1,2,3,4,5,6,7,8, true); // Enter correct pin numbers. Default: isCathode = true

void countFromTo(const int firstDigit, const int lastDigit, const int delayTime = 1000) {
  if (firstDigit < lastDigit) {
    for (int n = firstDigit; n <= lastDigit; ++n) { // count forwards
      MySevenSeg.writeDigit(n);
      delay(delayTime);
    }  
  } else {
      for (int n = firstDigit; n > lastDigit; --n) { // count backwards
        MySevenSeg.writeDigit(n - 1);
        delay(delayTime);
      }
  }
}

void setup() {}

void loop() {
  MySevenSeg.writeDigit(1); // Usage: (0..15)
  MySevenSeg.clearDisplay(); 
  
  MySevenSeg.writeDigit(8);
  MySevenSeg.clearDisplay(1000); // Usage: (delayTime). Default: delayTime = 0 (ms) 
  
  countFromTo(9,2,500); // Usage: (firstDigit, lastDigit, delayTime). Default: delayTime = 1000 (ms) 
  MySevenSeg.clearDisplay(3000);
  
  // a+b
  int a = 2;
  int b = 5;
  MySevenSeg.writeDigit(a);
  MySevenSeg.writeDigit(b);
  MySevenSeg.writeDigit(a+b); 
}
