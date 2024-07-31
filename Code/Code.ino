#include <Servo.h>
#include <Keypad.h>
#include <pitches.h>

const int rows = 4;
const int cols = 4;
const char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
const byte rowPins[rows] = {11, 10, 8, 9};
const byte colPins[cols] = {7, 6, 4, 2};
Keypad keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

const int ledPin = 13;
const int buzzerPin = 12;
const int servoPin = 5;

Servo servo;

String code = "1234";
String enteredCode = "";

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(servoPin, OUTPUT);
  servo.attach(servoPin);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key == '*') {
      if (enteredCode == code) {
        servo.write(60);
        digitalWrite(ledPin, HIGH);
        tone(buzzerPin, 500, 200);
        delay(200);
        tone(buzzerPin, 600, 500);
        delay(800);
      } else {
        servo.write(0);
        digitalWrite(ledPin, LOW);
        tone(buzzerPin, 50, 200);
        delay(230);
        tone(buzzerPin, 50, 200);
        delay(770);
      }
      enteredCode = "";
    } else {
      enteredCode += key;
      tone(buzzerPin, 3000, 100);
      delay(100);
    }
  }
}
