#include <LiquidCrystal.h>


//OpenPCR defaults. Note: pin 16 and 17 don't exist!
//iLcd(6, 7, 8, A5, 16, 17),
const int pin_lcd_rs =  2; //Arduino pin that connects to R/S pin of LCD display
const int pin_lcd_e  =  3; //Arduino pin that connects to E   pin of LCD display
const int pin_lcd_d4 =  4; //Arduino pin that connects to D4  pin of LCD display
const int pin_lcd_d5 =  5; //Arduino pin that connects to D5  pin of LCD display
const int pin_lcd_d6 =  6; //Arduino pin that connects to D6  pin of LCD display
const int pin_lcd_d7 =  7; //Arduino pin that connects to D7  pin of LCD display

LiquidCrystal lcd(
  pin_lcd_rs,
  pin_lcd_e,
  pin_lcd_d4,
  pin_lcd_d5,
  pin_lcd_d6,
  pin_lcd_d7);


void setup ()
{
  lcd.begin(16,1);
  Serial.begin(9600);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(millis());
  Serial.print(millis());
  Serial.print("\n");
  delay(100);
}
