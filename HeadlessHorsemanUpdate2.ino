#include <Servo.h>

// create a servo variable
Servo carouselservo;
Servo horseservo;
Servo pumpservo;
Servo rideservo;

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

//slow down pumpkin man
int pos = 0;    // variable to store the servo position
int cpos = 180;
int rpos = 70;

void setup() {
  carouselservo.attach(8);
  horseservo.attach(9);  // attaches the horseman  on pin 9
  pumpservo.attach(10);
  rideservo.attach(11);
  pinMode(buttonAPin, INPUT);
  pinMode(buttonBPin, INPUT);
  carouselservo.write(180);
  horseservo.write(0);
  pumpservo.write(0);
  rideservo.write(70);
}

void loop() {
  buttonAState = digitalRead(buttonAPin);
  
  // Read button A (Eventually, read if cannonball is connecting circuit although
  // i'm not exactly sure how that works yet lol)
  if (buttonAState != lastButtonAState) {
    if (buttonAState == HIGH) {
      A = true;
      horseservo.write(180); // tells the servo what angle to turn 180
      delay(2000);
      while (cpos >= 90) {
        for (cpos = 180; cpos >= 90; cpos -= 1) { // goes from 180 degrees to 90 degrees in steps of 1 degree
        carouselservo.write(cpos);
        delay(15);
        }
      }
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
    while (pos <=95) {
    for (pos = 0; pos <= 95; pos += 1) { // goes from 0 degrees to 95 degrees in steps of 1 degree
      pumpservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                         // waits 15 ms for the servo to reach the position
    }
      if (pos == 95);
        while (cpos >= 0) {
          for (cpos = 90; cpos >= 0; cpos -= 1) { // goes from 180 degrees to 90 degrees in steps of 1 degree
          carouselservo.write(cpos);
          delay(15);
          }
       }
  }

// Trigger horse ride
  if (cpos == 0);
  //Insert timer for 15 seconds and turn pos back to 180.
    for (rpos = 70; rpos <= 115; rpos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rideservo.write(rpos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
    for (rpos = 115; rpos >= 70; rpos -= 1) { // goes from 180 degrees to 0 degrees
    rideservo.write(rpos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}

  lastButtonAState = buttonAState;
  lastButtonBState = buttonBState;
}
