#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // change address if needed

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Hello Embedded");
  lcd.setCursor(0, 1);
  lcd.print("Day 14 - I2C");
}

void loop() {
}