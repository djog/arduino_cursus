/* 
    New class SevenSeg{}; added to file with setup() and loop() at the bottom.
    Author: remer (remernl at Github)
    License: Creative-commons http://creativecommons.org/licenses/by-sa/4.0/
 */
 
 #include <Arduino.h>
  
class SevenSeg {
  private:
    const bool cathode;
    static int seven_seg_digits[10][7]; // http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
    const int seven_seg_pins[9];
 
  public:
    SevenSeg(const int firstPin, const int secondPin, const int thirdPin, const int fourthPin, const int fifthPin, const int sixthPin, const int seventhPin, const int eightPin, const int ninthPin, const bool isCathode = true);
//    SevenSeg() : SevenSeg() {} // delegating constructor

    //class features
    void writeDigit(const int digit) const;
    void writeDot(const bool on = true) const;
    void clearScreen() const;
    void countRange(const int firstDigit, const int lastDigit, const int delayTime = 1000) const;
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
                                                           { 1,1,1,0,0,1,1 }   // = 9
                                         };
                                         
SevenSeg::SevenSeg(const int firstPin, const int secondPin, const int thirdPin, const int fourthPin, const int fifthPin, const int sixthPin, const int seventhPin, const int eightPin, const int ninthPin, const bool isCathode)
  : seven_seg_pins{firstPin,secondPin,thirdPin,fourthPin,fifthPin,sixthPin,seventhPin,eightPin,ninthPin}, 
    cathode(isCathode)
 {
    if (!cathode) { // is display a common anode?
        for (int r = 0; r != 10; ++r) {
          for (int c = 0; c != 7; ++c) { // converting display from common cathode to common anode
            if (seven_seg_digits[r][c] == 1) { seven_seg_digits[r][c] = 0; }
            else { seven_seg_digits[r][c] = 1; }
          }
        }
      }
  
  for (int n = 0; n < 8; ++n) 
  {
      pinMode(seven_seg_pins[n], OUTPUT);
  } 
  writeDot(0); // turn dot off (1 = on, 0 = off)
} 

void SevenSeg::writeDigit(int digit) const
{
  if (digit > 9) { digit = 9; }
  for (int counter = 0; counter != 7; ++counter) 
  {
    digitalWrite(seven_seg_pins[counter], seven_seg_digits[digit][counter]);
  }
}  

void SevenSeg::writeDot(bool dot) const
{
  if (!cathode && dot == true) { dot = false; } else if (!cathode && dot == false) { dot = true; } // common anode fix
  digitalWrite(seven_seg_pins[8], dot);
}

void SevenSeg::clearScreen() const
{

}
    
void SevenSeg::countRange(const int startDigit, const int endDigit, const int delayTime) const 
{
  if (startDigit < endDigit) {
    for (int n = startDigit; n <= endDigit; n++) {
      writeDigit(n);
      delay(delayTime);
    }  
  } else {
      int corrected = startDigit + 1; // preventing int n to turn negative
        for (int n = corrected; n > endDigit; n--) {
          writeDigit(n - 1); // correction
        delay(delayTime);
      }
  }
}
