#include "SevenSeg.h"

// Initializes seven seg display (int startPin, int endPin, boolean isCathode)
SevenSeg MySevenSeg = SevenSeg(2, 9, true); // Enter correct values, default: (2, 9, true)

void setup() {}

void loop() {
  MySevenSeg.writeDigit(1);
  delay(1000);
  MySevenSeg.writeDigit(8);
  delay(3000);
  MySevenSeg.countBackwards();
  delay(1000);
  MySevenSeg.countForwards();
  delay(3000);
  MySevenSeg.countForwards(3);
  delay(1000);
  MySevenSeg.countBackwards(7);
  delay(1000);
  MySevenSeg.countRange(2,9,500);
  delay(4000);
}
