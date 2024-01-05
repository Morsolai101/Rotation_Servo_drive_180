#include <Servo.h>
Servo myServo;
int buttonPin = 2; // The pin on which the button is located
int buttonState;   // A variable to save the state of the button
int lastButtonState = LOW; // A variable to save the previous state of the button
long lastDebounceTime = 0; // Time for an anti-rattle button
long debounceDelay = 50;   // Spacing for anti-rattle buttons
int servoPosition = 0; // Starting position of the servo motor

void setup() {
  myServo.attach(9); // The pin on which the servo motor is connected
  pinMode(buttonPin, INPUT);
  myServo.write(servoPosition); // Setting the starting position of the servo motor
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
        // If the button is pressed, rotate the servo motor 180 degrees
        myServo.write(180);
      } else {
        // If the button is not pressed, return the servo motor to its initial position (0 degrees)
        myServo.write(servoPosition);
      }
    }
  }

  lastButtonState = reading;
}
Servo drive Rotation
