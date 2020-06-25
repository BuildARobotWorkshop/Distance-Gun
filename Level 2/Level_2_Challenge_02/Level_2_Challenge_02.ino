#include <UltraDistSensor.h>
#include <LiquidCrystal_I2C.h> // includes the LiquidCrystal Library
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);
UltraDistSensor scanner;
float distance;

float largestDistance = 0;
float smallestDistance = 200;

void setup() {

  lcd.init();
  lcd.backlight();
  scanner.attach(9, 10);

}

void loop() {

  lcd.clear();

  distance = scanner.distanceInInch();

  if(distance > largestDistance){
    largestDistance = distance;
  }

  if(distance < smallestDistance){
    smallestDistance = distance;
  }

  lcd.setCursor(0, 0);
  lcd.print("Greatest: ");
  lcd.print(largestDistance);

  lcd.setCursor(0, 1);
  lcd.print("Smallest: ");
  lcd.print(smallestDistance);

  delay(500);
  
}
