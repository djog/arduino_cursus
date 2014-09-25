/* 
    New class SevenSeg{}; added to file with setup() and loop() at the bottom.
    Author: remer (remernl at Github)
    License: Creative-commons http://creativecommons.org/licenses/by-sa/4.0/
 */
 
 #include <Arduino.h>
  
class SevenSeg {
  private:
    int first_pin;
    int last_pin;
    const bool cathode;
    static int seven_seg_digits[10][7]; // http://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
 
  public:
    //constructor initializes display
    SevenSeg(const int firstPin, const int lastPin, const bool isCathode = true);
    SevenSeg() : SevenSeg(2,9) {} // delegating constructor

    int getFirstPin() const { return first_pin; }
    int getLastPin() const { return last_pin; }
    void setFirstPin(const int pin) { first_pin = pin; }
    void setLastPin(const int pin) { last_pin = pin; }
    
    //class features
    void writeDigit(const int digit) const;
    void writeDot(const bool on = true) const;
    void countBackwards(const int startDigit = 9, const int endDigit = 0, const int delayTime = 1000) const;    
    void countForwards(const int startDigit = 0, const int endDigit = 9, const int delayTime = 1000) const;
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
SevenSeg::SevenSeg(const int firstPin, const int lastPin, bool isCathode) 
  : first_pin(firstPin),
    last_pin(lastPin),
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

  
  for (int pin = getFirstPin(); pin <= getLastPin(); ++pin) 
  {
      pinMode(pin, OUTPUT);
  } 
  writeDot(0); // turn dot off (1 = on, 0 = off)
} 

void SevenSeg::writeDigit(int digit) const
{
  if (digit > 9) { digit = 9; }
  int pin = getFirstPin();
  for (int counter = 0; counter != 7; ++counter) 
  {
    digitalWrite(pin, seven_seg_digits[digit][counter]);
    ++pin;
  }
}  

void SevenSeg::writeDot(bool dot) const
{
  if (!cathode && dot == true) { dot = false; } else if (!cathode && dot == false) { dot = true; } // common anode fix
  digitalWrite(getLastPin(), dot);
}

void SevenSeg::countBackwards(int startDigit, const int endDigit, const int delayTime) const 
{
  startDigit += 1; // preventing int n to turn negative
  for (int n = startDigit; n > endDigit; n--) {
    writeDigit(n - 1); // correction
    delay(delayTime);
  }
}
    
void SevenSeg::countForwards(const int startDigit, const int endDigit, const int delayTime) const 
{
  for (int n = startDigit; n <= endDigit; n++) {
    writeDigit(n);
    delay(delayTime);
  }  
}

void SevenSeg::countRange(const int startDigit, const int endDigit, const int delayTime) const 
{
  if (startDigit < endDigit) {
    countForwards(startDigit, endDigit, delayTime);
  } else {
        countBackwards(startDigit, endDigit, delayTime);
  }
}
