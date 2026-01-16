#include <Servo.h>

#define trigPin 9
#define echoPin 10
#define servoPin 6

Servo myServo;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  myServo.attach(servoPin);
  myServo.write(90); // center position
}

void loop() {
  // Ultrasonic trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20) {
    myServo.write(0);    // turn left
  } else {
    myServo.write(90);   // center
  }

  delay(300);
}