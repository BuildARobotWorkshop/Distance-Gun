#include <LiquidCrystal_I2C.h> // includes the LiquidCrystal Library
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);

void setup() {

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Message 1");

}

void loop() {

  lcd.setCursor(0, 1);
  lcd.print("Message 2");
  lcd.scrollDisplayRight();
  delay(500);
  
}
