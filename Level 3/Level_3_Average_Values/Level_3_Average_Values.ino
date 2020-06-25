#include <UltraDistSensor.h>
#include <LiquidCrystal_I2C.h> // includes the LiquidCrystal Library
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);
UltraDistSensor scanner;

float distance;

void setup() {

  lcd.init();
  lcd.backlight();
  
  scanner.attach(9, 10);

}

void loop() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Distance: ");

  float distances = 0;
  int numTimes = 0;

  for(int i = 0; i < 10; i++){
    
      distance = scanner.distanceInInch();

      if(distance != 0.0){
          distances += distance;
          numTimes++;
      }
    
  }

  int averageDistance = distances/numTimes;

  if(distance != 0.0){

      lcd.print(averageDistance);
    
  } else {
      lcd.setCursor(0, 1);
      lcd.print("Object not Found");
    
  }

  delay(500);
  
}
