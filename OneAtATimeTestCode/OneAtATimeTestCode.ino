#include <Servo.h>

Servo myservo;  // create a servo variable
const int buttonPin = 2;
int buttonVal;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9
  pinMode(buttonPin, INPUT);
  myservo.write(0);
}

void loop() {
  buttonVal = digitalRead(buttonPin);

  if (buttonVal == HIGH) {
    // 180 for headless, 90 for pumpkin
    myservo.write(90);
  } 
  
  // Else is if we decide it's easier to just release and go to 0 instead of 
  // resetting altogether although pressing once and having it stay turned is more
  // true to how it should actually perform

  //  else {
  //    myservo.write(0);
  //  }
}
