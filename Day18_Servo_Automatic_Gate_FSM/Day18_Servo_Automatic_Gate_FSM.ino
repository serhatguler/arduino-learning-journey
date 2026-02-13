#include <Servo.h>

// -------- PINS --------
#define TRIG_PIN 9
#define ECHO_PIN 8
#define SERVO_PIN 6

// -------- SERVO --------
Servo gateServo;
int servoPosition = 0;

// -------- FSM STATES --------
enum State {
  IDLE,
  OPENING,
  OPEN,
  CLOSING
};

State currentState = IDLE;

// -------- TIMING --------
unsigned long previousMillis = 0;
const unsigned long servoInterval = 15;   // speed control
const unsigned long openDelay = 3000;     // stay open 3 seconds

unsigned long openStartTime = 0;

// -------- DISTANCE --------
const int triggerDistance = 20; // cm

// -------- SETUP --------
void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  gateServo.attach(SERVO_PIN);
  gateServo.write(0);

  Serial.begin(9600);
  Serial.println("Day 18 - Automatic Gate Started");
}

// -------- LOOP --------
void loop() {
  long distance = readDistance();
  updateState(distance);
  handleServo();
}

// -------- ULTRASONIC --------
long readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return -1;

  long distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  return distance;
}

// -------- FSM LOGIC --------
void updateState(long distance) {

  switch (currentState) {

    case IDLE:
      if (distance > 0 && distance <= triggerDistance) {
        currentState = OPENING;
      }
      break;

    case OPENING:
      if (servoPosition >= 90) {
        currentState = OPEN;
        openStartTime = millis();
      }
      break;

    case OPEN:
      if (millis() - openStartTime >= openDelay) {
        currentState = CLOSING;
      }
      break;

    case CLOSING:
      if (servoPosition <= 0) {
        currentState = IDLE;
      }
      break;
  }
}

// -------- SERVO HANDLER --------
void handleServo() {

  unsigned long currentMillis = millis();

  switch (currentState) {

    case OPENING:
      if (currentMillis - previousMillis >= servoInterval) {
        previousMillis = currentMillis;
        servoPosition++;
        gateServo.write(servoPosition);
      }
      break;

    case CLOSING:
      if (currentMillis - previousMillis >= servoInterval) {
        previousMillis = currentMillis;
        servoPosition--;
        gateServo.write(servoPosition);
      }
      break;

    default:
      break;
  }
}