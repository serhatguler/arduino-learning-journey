#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define potPin A0

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  int value = analogRead(potPin);

  lcd.setCursor(0, 0);
  lcd.print("Pot Value:");
  lcd.setCursor(0, 1);
  lcd.print(value);
  lcd.print("   ");

  delay(300);
}