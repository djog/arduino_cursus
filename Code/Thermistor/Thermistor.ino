#include <LiquidCrystal.h>

// 5V
// |
// thermistor
// |
// +---- pin
// |
// GND
const int pin_thermistor = A0;


//OpenPCR defaults. Note: pin 16 and 17 don't exist!
//iLcd(6, 7, 8, A5, 16, 17),
const int pin_lcd_rs =  2; //Arduino pin that connects to R/S pin of LCD display
const int pin_lcd_e  =  3; //Arduino pin that connects to E   pin of LCD display
const int pin_lcd_d4 =  4; //Arduino pin that connects to D4  pin of LCD display
const int pin_lcd_d5 =  5; //Arduino pin that connects to D5  pin of LCD display
const int pin_lcd_d6 =  6; //Arduino pin that connects to D6  pin of LCD display
const int pin_lcd_d7 =  7; //Arduino pin that connects to D7  pin of LCD display
/*  
PROGMEM const unsigned int DIY_RESISTANCE_TABLE[] = {  
  9795, 7617, 5970, 4713, 3747, 3000, 2417, 1959, 1598, 1310, 1080, 895, 746, 624, 525, 444, 377, 321, 275, 236, 204, 176, 153, 133, 116, 103, 90, 80, 70, 62, 56,};
//0,    5      10    15    20    25    30    35    40    45    50    55  60    65  70  75    80
*/
PROGMEM const unsigned int DIY_RESISTANCE_TABLE[] = {  
  14692, 11425, 8955, 7069.97, 5400.53, 3580.86, 3635, 2938, 2397, 1966, 1621, 1343, 1119, 937, 788, 666, 566, 482, 412, 354, 306, 265, 230, 200, 175, 154, 135, 119, 106, 94, 83 };
//0,    5      10    15    20    25

float TableLookup(const unsigned int lookupTable[], unsigned int tableSize, int startValue, unsigned long searchValue) {
  //simple linear search for now
  int i;
  for (i = 0; i < tableSize; i++) {
    if (searchValue >= pgm_read_word_near(lookupTable + i))
      break;
  }
  
  if (i > 0) {
    unsigned long high_val = pgm_read_word_near(lookupTable + i - 1);
    unsigned long low_val = pgm_read_word_near(lookupTable + i);
    return (i * 5) + startValue - (float)(searchValue - low_val) / (float)(high_val - low_val);
  } else {
    return startValue;
  }
}

double ReadTemp() 
{
  unsigned long voltage_mv = (unsigned long)analogRead(pin_thermistor) * 5000 / 1024;
  unsigned long resistance = (voltage_mv * 2200 / (5000 - voltage_mv));
  const double t = TableLookup(DIY_RESISTANCE_TABLE, sizeof(DIY_RESISTANCE_TABLE) / sizeof(DIY_RESISTANCE_TABLE[0]), 0, resistance);
  return t;
}


LiquidCrystal lcd(
  pin_lcd_rs,
  pin_lcd_e,
  pin_lcd_d4,
  pin_lcd_d5,
  pin_lcd_d6,
  pin_lcd_d7);


void setup ()
{
  pinMode(pin_thermistor,INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  //const int value = analogRead(pin_thermistor);
  //const double f = static_cast<double>(value) / 1024.0;
  //lcd.print(f * 5.0);
  lcd.print( ReadTemp());
  Serial.print(" resistance: ");
  Serial.print((((unsigned long)analogRead(pin_thermistor) * 5000 / 1024) * 2200 / (5000 - (unsigned long)analogRead(pin_thermistor) * 5000 / 1024)) );
  Serial.print("    -    ");
  Serial.println(ReadTemp());
  delay(100);
}
