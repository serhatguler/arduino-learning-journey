/*****************
 * Day 20 - Smart Parking System
 * Ultrasonic + Servo + I2C LCD + FSM + millis()
 *****************/

#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// -------- LCD --------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// -------- PINS --------
#define TRIG_PIN  9
#define ECHO_PIN  8
#define SERVO_PIN 6

// -------- SERVO --------
Servo gateServo;
int servoPos = 0;

// -------- FSM STATES --------
enum State {
  IDLE,
  CAR_DETECTED,
  GATE_OPEN,
  GATE_CLOSING
};

State currentState = IDLE;

// -------- TIMING --------
unsigned long previousMillis = 0;
unsigned long gateOpenTime  = 0;

const unsigned long servoInterval = 15;    // ms
const unsigned long gateDelay     = 3000;  // ms

// -------- LOGIC --------
const int detectDistance = 15; // cm
int carCount = 0;

// -------- SETUP --------
void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  gateServo.attach(SERVO_PIN);
  gateServo.write(0);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Parking");

  Serial.begin(9600);
}

// -------- LOOP --------
void loop() {
  long distance = readDistance();
  updateState(distance);
  handleGate();
  updateLCD();
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

  return duration * 0.034 / 2;
}

// -------- FSM LOGIC --------
void updateState(long distance) {

  switch (currentState) {

    case IDLE:
      if (distance > 0 && distance <= detectDistance) {
        currentState = CAR_DETECTED;
        carCount++;
      }
      break;

    case CAR_DETECTED:
      currentState = GATE_OPEN;
      gateOpenTime = millis();
      break;

    case GATE_OPEN:
      if (millis() - gateOpenTime >= gateDelay) {
        currentState = GATE_CLOSING;
      }
      break;

    case GATE_CLOSING:
      if (servoPos <= 0) {
        currentState = IDLE;
      }
      break;
  }
}

// -------- SERVO HANDLER --------
void handleGate() {
  unsigned long now = millis();

  switch (currentState) {

    case GATE_OPEN:
      if (servoPos < 90 && now - previousMillis >= servoInterval) {
        previousMillis = now;
        servoPos++;
        gateServo.write(servoPos);
      }
      break;

    case GATE_CLOSING:
      if (servoPos > 0 && now - previousMillis >= servoInterval) {
        previousMillis = now;
        servoPos--;
        gateServo.write(servoPos);
      }
      break;

    default:
      break;
  }
}

// -------- LCD --------
void updateLCD() {
  lcd.setCursor(0, 1);
  lcd.print("Cars: ");
  lcd.print(carCount);
  lcd.print("   ");
}