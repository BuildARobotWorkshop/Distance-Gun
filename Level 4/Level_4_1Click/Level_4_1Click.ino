#include <UltraDistSensor.h>
#include <LiquidCrystal_I2C.h> // includes the LiquidCrystal Library
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F, 20, 4);
UltraDistSensor scanner;

int buttonPin = 2;
int val = 0;

int numClicks = 0;

float distance;

byte customCharOne[] = {
  B11111,
  B11111,
  B01010,
  B01010,
  B00100,
  B10101,
  B10001,
  B11111
};

byte customCharTwo[] = {
  B11111,
  B01110,
  B00100,
  B01110,
  B01110,
  B00100,
  B01110,
  B11111
};


void setup() {

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);

  lcd.createChar(0, customCharOne);
  lcd.createChar(1, customCharTwo);

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

  Serial.println(numClicks);

  if(numClicks == 0){

      lcd.write(0);
      lcd.print(" FirstName");
      lcd.setCursor(0, 1);
      lcd.write(1);
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
