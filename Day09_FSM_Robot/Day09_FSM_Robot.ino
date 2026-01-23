#include <Servo.h>

#define trigPin 9
#define echoPin 10
#define servoPin 6

Servo myServo;

enum RobotState {
  SCAN,
  TURN_LEFT,
  TURN_RIGHT,
  STOP
};

RobotState currentState = SCAN;

long duration;
int distance;
int leftDistance;
int rightDistance;

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
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
  switch (currentState) {

    case SCAN:
      myServo.write(0);
      delay(400);
      leftDistance = measureDistance();

      myServo.write(180);
      delay(400);
      rightDistance = measureDistance();

      if (leftDistance > rightDistance) {
        currentState = TURN_LEFT;
      } else {
        currentState = TURN_RIGHT;
      }
      break;

    case TURN_LEFT:
      myServo.write(0);
      delay(500);
      currentState = SCAN;
      break;

    case TURN_RIGHT:
      myServo.write(180);
      delay(500);
      currentState = SCAN;
      break;

    case STOP:
      myServo.write(90);
      break;
  }

  Serial.print("State: ");
  Serial.println(currentState);
}