#include <LiquidCrystal.h>


const int pin_relay_a =  2;
const int pin_relay_b =  3;
const int pin_relay_c =  4;
const int pin_relay_d =  5;

//OpenPCR defaults. Note: pin 16 and 17 don't exist!
//iLcd(6, 7, 8, A5, 16, 17),
const int pin_lcd_rs =  8; //Arduino pin that connects to R/S pin of LCD display
const int pin_lcd_e  =  9; //Arduino pin that connects to E   pin of LCD display
const int pin_lcd_d4 = 10; //Arduino pin that connects to D4  pin of LCD display
const int pin_lcd_d5 = 11; //Arduino pin that connects to D5  pin of LCD display
const int pin_lcd_d6 = 12; //Arduino pin that connects to D6  pin of LCD display
const int pin_lcd_d7 = 13; //Arduino pin that connects to D7  pin of LCD display

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
