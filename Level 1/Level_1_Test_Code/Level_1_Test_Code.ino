#include <UltraDistSensor.h>

UltraDistSensor scanner;

float reading;

void setup() {

    Serial.begin(9600);
    scanner.attach(9, 10);
    Serial.println("Test Code Uploaded");
    Serial.println("Place and object in front of the sensor!");
    
}

void loop() {

    reading = scanner.distanceInInch();

    if(reading == 0.0){
      
        Serial.println("Sensor not connected properly!");
        
    } else {
      
        Serial.println("Sensor connected successfully!");
      
    }

    delay(2000);

}
