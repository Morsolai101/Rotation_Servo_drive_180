#include <Servo.h>
Servo myServo;
int buttonPin = 2; // Пін, на якому знаходиться кнопка
int buttonState;   // Змінна для збереження стану кнопки
int lastButtonState = LOW; // Змінна для збереження попереднього стану кнопки
long lastDebounceTime = 0; // Час для антидребізгу кнопки
long debounceDelay = 50;   // Інтервал для антидребізгу кнопки
int servoPosition = 0; // Початкове положення сервомотора

void setup() {
  myServo.attach(9); // Пін, на якому підключений сервомотор
  pinMode(buttonPin, INPUT);
  myServo.write(servoPosition); // Встановлення початкового положення сервомотора
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
        // Якщо кнопка натиснута, повернути сервомотор на 180 градусів
        myServo.write(180);
      } else {
        // Якщо кнопка не натиснута, повернути сервомотор на початкове положення (0 градусів)
        myServo.write(servoPosition);
      }
    }
  }

  lastButtonState = reading;
}
Servo drive Rotation
