#include <Servo.h>

Servo myservo;  // create a servo variable
const int buttonPin = 2;
int buttonVal;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonVal = digitalRead(buttonPin);

  if (buttonVal == HIGH) {
    // 180 for headless, 90 for pumpkin
    myservo.write(180);
  } else {
    myservo.write(0);
  }
}

