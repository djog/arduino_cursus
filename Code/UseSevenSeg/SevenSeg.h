/* 
    SevenSeg class for use with a 7 Segment LED featuring a common cathode or common anode pin
 */
 
#include <Arduino.h>
  
class SevenSeg {
  public:
    SevenSeg(const int pinSegA, const int pinSegB, const int pinSegC, const int pinSegD, const int pinSegE, const int pinSegF, const int pinSegG, const int pinDot, const bool isCathode = true);

    void writeDigit(const int digit) const;
    void writeDot(const bool on = true) const; // (1 = on, 0 = off)
    void clearDisplay(const int duration = 0) const;
    void writeError() const; // E.
 
  private:
    int commonCathodeOrAnode(const int input) const; // fixing common pin output
    const bool cathode;
    const int seven_seg_pins[8];
    static const int seven_seg_digits[16][7]; // http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
};

const int SevenSeg::seven_seg_digits[16][7] = {            { 1,1,1,1,1,1,0 },  // =  0
                                                           { 0,1,1,0,0,0,0 },  // =  1
                                                           { 1,1,0,1,1,0,1 },  // =  2
                                                           { 1,1,1,1,0,0,1 },  // =  3
                                                           { 0,1,1,0,0,1,1 },  // =  4
                                                           { 1,0,1,1,0,1,1 },  // =  5
                                                           { 1,0,1,1,1,1,1 },  // =  6
                                                           { 1,1,1,0,0,0,0 },  // =  7
                                                           { 1,1,1,1,1,1,1 },  // =  8
                                                           { 1,1,1,0,0,1,1 },  // =  9
                                                                               // hexadecimal support             
                                                           { 1,1,1,0,1,1,1 },  // = 10 = A
                                                           { 0,0,1,1,1,1,1 },  // = 11 = b
                                                           { 1,0,0,1,1,1,0 },  // = 12 = C
                                                           { 0,1,1,1,1,0,1 },  // = 13 = d
                                                           { 1,0,0,1,1,1,1 },  // = 14 = E
                                                           { 1,0,0,0,1,1,1 }   // = 15 = F
                                         };
                                         
SevenSeg::SevenSeg(const int pinSegA, const int pinSegB, const int pinSegC, const int pinSegD, const int pinSegE, const int pinSegF, const int pinSegG, const int pinDot, const bool isCathode)
  : seven_seg_pins{pinSegA,pinSegB,pinSegC,pinSegD,pinSegE,pinSegF,pinSegG,pinDot}, 
    cathode(isCathode) {
  for (int n = 0; n < 8; ++n) { pinMode(seven_seg_pins[n], OUTPUT); }
  clearDisplay();
} 

void SevenSeg::writeDigit(int digit) const {
  if (digit < 0 || digit > 16) { writeError(); } // error catch
  else {
    for (int n = 0; n != 8; ++n) {
      int output = commonCathodeOrAnode(seven_seg_digits[digit][n]);
      digitalWrite(seven_seg_pins[n], output); 
    } 
  }
}  

void SevenSeg::writeDot(bool dot) const {
  int output = commonCathodeOrAnode(dot);
  digitalWrite(seven_seg_pins[8], output);
}

void SevenSeg::clearDisplay(const int duration) const {
  for (int n = 0; n < 8; ++n) {
    int output = commonCathodeOrAnode(0);
    digitalWrite(seven_seg_pins[n], output); 
  }
  writeDot(0);
  delay(duration);
}
    
void SevenSeg::writeError() const { 
  writeDigit(14); 
  writeDot();
}

int SevenSeg::commonCathodeOrAnode(const int input) const {
  if (cathode) {
    return input;
  } else {
    return (input == 1) ? 0 : 1; // 1 to 0 and 0 to 1
  }
}
