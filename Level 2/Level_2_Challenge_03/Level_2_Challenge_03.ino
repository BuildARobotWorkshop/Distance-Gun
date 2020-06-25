#include <UltraDistSensor.h>
#include <LiquidCrystal_I2C.h> // includes the LiquidCrystal Library
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);
UltraDistSensor scanner;

float distance;
int messageNum = 0;
int newMessageNum = 0;

void setup() {

  lcd.init();
  lcd.backlight();
  scanner.attach(9, 10);

}

void loop() {

  distance = scanner.distanceInInch();

  if(distance <= 20){
      newMessageNum = 1;
  } else if(distance <= 40){
      newMessageNum = 2;
  } else if(distance <= 75){
      newMessageNum = 3;
  } else {
      newMessageNum = 4;
  }

    if(newMessageNum != messageNum){
        messageNum = newMessageNum;
        lcd.setCursor(0, 0);
        if(messageNum == 1){
            lcd.print("Object is Very Close By");
        } else if(messageNum == 2){
            lcd.print("Object is not Too Close");
        } else if(messageNum == 3){
            lcd.print("Object is not Too Far");
        } else {
            lcd.print("Object is Far Away");
        }
    
    
  } else {
    lcd.scrollDisplayLeft();
  }
  
  delay(200);
  
}
