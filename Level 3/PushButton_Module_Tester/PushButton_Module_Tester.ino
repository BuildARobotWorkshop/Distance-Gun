int buttonpin = 2; //Define the push button pin
//boolean val = LOW; //Define a numeric variable
int val = 0;

void setup(){
  
  pinMode(buttonpin, INPUT);
  Serial.begin(9600);
  
}

void loop(){
  
  val = digitalRead(buttonpin); // check the state of the button
  
  if(val == HIGH) {
    Serial.println("Pressed");
  } else {
    Serial.println("Not Pressed");
  }

  delay(1000);
  
}
