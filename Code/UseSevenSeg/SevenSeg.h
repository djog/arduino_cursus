/* 
    SevenSeg class for use with a 7 Segment LED
 */
 
#include <Arduino.h>
  
class SevenSeg {
  public:
    //class constructor
    SevenSeg(const int pinSegA, const int pinSegB, const int pinSegC, const int pinSegD, const int pinSegE, const int pinSegF, const int pinSegG, const int pinDot, const bool isCathode = true);

    //class features
    void writeDigit(const int digit) const;
    void writeDot(const bool on = true) const; // (1 = on, 0 = off)
    void clearDisplay(const int delayTime = 1000) const;
    void countFromTo(const int firstDigit, const int lastDigit, const int delayTime = 1000) const;
  
  private:
    const bool cathode;
    const int seven_seg_pins[8];
    /*const*/ static int seven_seg_digits[10][7]; // http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
    //const int seven_seg_abc[][];
};

int SevenSeg::seven_seg_digits[10][7] = {                  { 1,1,1,1,1,1,0 },  // = 0
                                                           { 0,1,1,0,0,0,0 },  // = 1
                                                           { 1,1,0,1,1,0,1 },  // = 2
                                                           { 1,1,1,1,0,0,1 },  // = 3
                                                           { 0,1,1,0,0,1,1 },  // = 4
                                                           { 1,0,1,1,0,1,1 },  // = 5
                                                           { 1,0,1,1,1,1,1 },  // = 6
                                                           { 1,1,1,0,0,0,0 },  // = 7
                                                           { 1,1,1,1,1,1,1 },  // = 8
                                                           { 1,1,1,0,0,1,1 },  // = 9
                                         };
                                         
SevenSeg::SevenSeg(const int pinSegA, const int pinSegB, const int pinSegC, const int pinSegD, const int pinSegE, const int pinSegF, const int pinSegG, const int pinDot, const bool isCathode)
  : seven_seg_pins{pinSegA,pinSegB,pinSegC,pinSegD,pinSegE,pinSegF,pinSegG,pinDot}, 
    cathode(isCathode) {
  if (!cathode) { // is display a common anode?
    for (int r = 0; r != 10; ++r) {
      for (int c = 0; c != 7; ++c) { // converting display from common cathode to common anode
        if (seven_seg_digits[r][c] == 1) { seven_seg_digits[r][c] = 0; }
          else { seven_seg_digits[r][c] = 1; }
      }
    }
  }
  for (int n = 0; n < 8; ++n) { pinMode(seven_seg_pins[n], OUTPUT); }
  writeDot(0);
} 

void SevenSeg::writeDigit(int digit) const {
  if (digit < 0 && digit > 9) { /*report error*/ } // error catch
  for (int n = 0; n != 7; ++n) { digitalWrite(seven_seg_pins[n], seven_seg_digits[digit][n]); }
}  

void SevenSeg::writeDot(bool dot) const {
  if (!cathode && dot == true) { dot = false; } else if (!cathode && dot == false) { dot = true; } // common anode fix
  digitalWrite(seven_seg_pins[8], dot);
}

void SevenSeg::clearDisplay(const int delayTime) const {
  int output = cathode ? 0 : 1;
  for (int n = 0; n < 8; ++n) { digitalWrite(seven_seg_pins[n], output); }
  writeDot(0);
  delay(delayTime);
}
    
void SevenSeg::countFromTo(const int startDigit, const int endDigit, const int delayTime) const {
  if (startDigit < endDigit) {
    for (int n = startDigit; n <= endDigit; ++n) { // count forwards
      writeDigit(n);
      delay(delayTime);
    }  
  } else {
      for (int n = startDigit; n > endDigit; --n) { // count backwards
        writeDigit(n - 1);
        delay(delayTime);
      }
  }
}
