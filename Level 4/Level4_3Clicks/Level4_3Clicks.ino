#include <UltraDistSensor.h>
#include <LiquidCrystal_I2C.h> // includes the LiquidCrystal Library
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);
UltraDistSensor scanner;

int buttonPin = 2;
int val = 0;

int numClicks = 0;

float distance;

void setup() {

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);

  pinMode(buttonPin, INPUT);
  
  scanner.attach(9, 10);

}

void loop() {

  lcd.setCursor(0, 0);

  val = digitalRead(buttonPin);

  if(val == HIGH){
    
      numClicks++;
      if(numClicks >= 4){
          numClicks = 0;
      }
      
  }

  if(numClicks == 0){

      lcd.print(" FirstName");
      lcd.setCursor(0, 1);
      lcd.print(" LastName");
    
  } else if(numClicks == 1){
    
      lcd.clear();
      lcd.print("Distance: ");

      int distance = findDistance();
      
      if(distance == 0 || distance == -1){
          lcd.setCursor(0, 1);
          lcd.print("Object Not Found");
      } else {
          lcd.print(distance);
      }
    
  } else if(numClicks == 2){
      
      int firstVal = findDistance();
      delay(200);
      int secondVal = findDistance();
      lcd.clear();
      
      lcd.setCursor(0, 0);
      lcd.print("Object"); 
      
      if(secondVal > firstVal){
          lcd.setCursor(0, 1);
          lcd.print("Outgoing");
      } else if(secondVal < firstVal){
          lcd.setCursor(0, 1);
          lcd.print("Incoming");
      } else if(secondVal == firstVal){
          lcd.setCursor(0, 1);
          lcd.print("Stationary");
      }
    
  } else if(numClicks == 3){
    
      int firstVal = findDistance();
      delay(500);
      int secondVal = findDistance();
      lcd.clear();
      int speedC = (firstVal - secondVal)*2;
      
      lcd.setCursor(0, 0);
      lcd.print("Speed:");
      lcd.setCursor(0, 1);
      lcd.print(speedC);
      lcd.print(" inch/sec");
    
  }

  delay(400);

}

int findDistance(){

    int distances = 0;
    int numTimes = 0;
  
    for(int i = 0; i < 10; i++){
    
      distance = scanner.distanceInInch();

      if(distance != 0.0){
          distances += distance;
          numTimes++;
      }
    
    }

    int averageDistance = distances/numTimes;
    
    return averageDistance;
  
}
