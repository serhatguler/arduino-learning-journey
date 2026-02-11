/*****************
 * Day 17 - Ultrasonic Sensor FSM (Non-Blocking)
 * Board: Arduino Mega / Uno
 * Sensor: HC-SR04
 * Features:
 *  - Finite State Machine (FSM)
 *  - Non-blocking timing using millis()
 *  - LED + Buzzer feedback
 *****************/

// ----------- PIN DEFINITIONS -----------
#define TRIG_PIN    9
#define ECHO_PIN    8
#define LED_PIN     7
#define BUZZER_PIN  6

// ----------- FSM STATES -----------
enum State {
  IDLE,
  OBJECT_DETECTED,
  WARNING
};

State currentState = IDLE;

// ----------- TIMING VARIABLES -----------
unsigned long previousMillis = 0;
bool ledState = LOW;

const unsigned long detectedInterval = 500; // ms
const unsigned long warningInterval  = 200; // ms

// ----------- DISTANCE THRESHOLDS -----------
const int detectedDistance = 30; // cm
const int warningDistance  = 15; // cm

// ----------- SETUP -----------
void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Day 17 FSM Ultrasonic Started");
}

// ----------- MAIN LOOP -----------
void loop() {
  long distance = readDistance();
  updateState(distance);
  handleOutputs();
}

// ----------- ULTRASONIC FUNCTION -----------
long readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) return -1; // no echo

  long distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  return distance;
}

// ----------- FSM LOGIC -----------
void updateState(long distance) {
  switch (currentState) {

    case IDLE:
      if (distance > 0 && distance <= detectedDistance) {
        currentState = OBJECT_DETECTED;
      }
      break;

    case OBJECT_DETECTED:
      if (distance <= warningDistance) {
        currentState = WARNING;
      } else if (distance > detectedDistance) {
        currentState = IDLE;
      }
      break;

    case WARNING:
      if (distance > detectedDistance) {
        currentState = IDLE;
      }
      break;
  }
}

// ----------- OUTPUT HANDLER -----------
void handleOutputs() {
  unsigned long currentMillis = millis();

  switch (currentState) {

    case IDLE:
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      break;

    case OBJECT_DETECTED:
      if (currentMillis - previousMillis >= detectedInterval) {
        previousMillis = currentMillis;
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
      }
      digitalWrite(BUZZER_PIN, LOW);
      break;

    case WARNING:
      if (currentMillis - previousMillis >= warningInterval) {
        previousMillis = currentMillis;
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
        digitalWrite(BUZZER_PIN, ledState);
      }
      break;
  }
}