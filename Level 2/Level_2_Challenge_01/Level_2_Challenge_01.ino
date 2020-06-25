#include <UltraDistSensor.h>
#include <LiquidCrystal_I2C.h> // includes the LiquidCrystal Library
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);
UltraDistSensor scanner;

int InchDistance;
int CmDistance;

void setup() {

  lcd.init();
  lcd.backlight();
  
  scanner.attach(9, 10);
  
}

void loop() {

  lcd.scrollDisplayRight();
  
  InchDistance = scanner.distanceInInch();
  CmDistance = scanner.distanceInCm();

  lcd.setCursor(0, 0);
  lcd.print("Inches: ");
  lcd.print(InchDistance);

  lcd.setCursor(11, 0);
  lcd.print("Cm: ");
  lcd.print(CmDistance);

  lcd.setCursor(0, 1);
  lcd.print("Cm-Inches: ");
  lcd.print(CmDistance - InchDistance);
  
  delay(400);
  
}
