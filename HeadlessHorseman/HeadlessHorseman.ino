#include <Servo.h>

Servo horseservo;
Servo pumpservo;
  // create a servo variable

//setup horseman man
const int buttonAPin = 2;
int buttonAState = 0;
int lastButtonAState = 0;
bool A = false;

//setup pumpkin head
const int buttonBPin = 4;
int buttonBState = 0;
int lastButtonBState = 0;
bool B = false;

void setup() {
  horseservo.attach(9);  // attaches the horseman  on pin 9
  pumpservo.attach(10);
  pinMode(buttonAPin, INPUT);
  pinMode(buttonBPin, INPUT);
  horseservo.write(0);
  pumpservo.write(0);
}

void loop() {
  buttonAState = digitalRead(buttonAPin);
  
  // Read button A (Eventually, read if cannonball is connecting circuit although
  // i'm not exactly sure how that works yet lol)
  if (buttonAState != lastButtonAState) {
    if (buttonAState == HIGH) {
      A = true;
      horseservo.write(180); // tells the servo what angle to turn 180
    }  
  }

  // If horseman is triggered, read for pumpkin head trigger 
  if (A == true) {
    buttonBState = digitalRead(buttonBPin);
    if (buttonBState != lastButtonBState) {
      if (buttonBState == HIGH) {
        B = true;
      }
    }
  }

  // Trigger pumpkin man
  if (B == true)  {
    pumpservo.write(90);
}

  lastButtonAState = buttonAState;
  lastButtonBState = buttonBState;
}
