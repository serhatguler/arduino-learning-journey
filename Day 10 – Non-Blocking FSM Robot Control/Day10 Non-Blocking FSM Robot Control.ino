#include <Servo.h>

#define trigPin 9
#define echoPin 10
#define servoPin 6

Servo myServo;

enum RobotState {
  SCAN,
  TURN_LEFT,
  TURN_RIGHT
};

RobotState currentState = SCAN;

unsigned long previousMillis = 0;
const long scanInterval = 500;

long duration;
int leftDistance;
int rightDistance;

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return 300; // no echo
  return duration * 0.034 / 2;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  myServo.attach(servoPin);
  myServo.write(90);
}

void loop() {
  unsigned long currentMillis = millis();

  switch (currentState) {

    case SCAN:
      if (currentMillis - previousMillis >= scanInterval) {
        previousMillis = currentMillis;

        myServo.write(0);
        delay(200);
        leftDistance = measureDistance();

        myServo.write(180);
        delay(200);
        rightDistance = measureDistance();

        if (leftDistance > rightDistance) {
          currentState = TURN_LEFT;
        } else {
          currentState = TURN_RIGHT;
        }

        Serial.print("Left: ");
        Serial.print(leftDistance);
        Serial.print(" | Right: ");
        Serial.println(rightDistance);
      }
      break;

    case TURN_LEFT:
      myServo.write(0);
      delay(300);
      currentState = SCAN;
      break;

    case TURN_RIGHT:
      myServo.write(180);
      delay(300);
      currentState = SCAN;
      break;
  }
}