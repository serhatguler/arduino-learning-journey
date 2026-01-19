#include <Servo.h>

#define trigPin 9
#define echoPin 10
#define servoPin 6

Servo myServo;

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
  // Look left
  myServo.write(0);
  delay(400);
  leftDistance = measureDistance();

  // Look right
  myServo.write(180);
  delay(400);
  rightDistance = measureDistance();

  // Decide
  if (leftDistance > rightDistance) {
    myServo.write(0);   // turn left
  } else {
    myServo.write(180); // turn right
  }

  Serial.print("Left: ");
  Serial.print(leftDistance);
  Serial.print(" cm | Right: ");
  Serial.print(rightDistance);
  Serial.println(" cm");

  delay(1000);
}