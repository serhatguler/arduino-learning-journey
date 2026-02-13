#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// -------- LCD --------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// -------- PINS --------
#define TRIG_PIN 9
#define ECHO_PIN 8

// -------- FSM STATES --------
enum State {
  NO_CAR,
  CAR_DETECTED
};

State currentState = NO_CAR;

// -------- VARIABLES --------
int carCount = 0;
unsigned long stateTimer = 0;
const unsigned long debounceTime = 1500; // ms
const int detectDistance = 15; // cm

// -------- SETUP --------
void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Parking System");

  Serial.begin(9600);
  delay(1000);
}

// -------- LOOP --------
void loop() {
  long distance = readDistance();
  updateState(distance);
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
  unsigned long now = millis();

  switch (currentState) {

    case NO_CAR:
      if (distance > 0 && distance <= detectDistance) {
        currentState = CAR_DETECTED;
        stateTimer = now;
        carCount++;
      }
      break;

    case CAR_DETECTED:
      if (distance > detectDistance && (now - stateTimer > debounceTime)) {
        currentState = NO_CAR;
      }
      break;
  }
}

// -------- LCD UPDATE --------
void updateLCD() {
  lcd.setCursor(0, 1);
  lcd.print("Cars: ");
  lcd.print(carCount);
  lcd.print("    ");
}