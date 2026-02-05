enum State {
  IDLE,
  BLINK_FAST,
  BLINK_SLOW
};

State currentState = IDLE;
unsigned long previousMillis = 0;

void setup() {
  pinMode(6, OUTPUT);
}

void loop() {
  unsigned long now = millis();

  switch (currentState) {
    case IDLE:
      digitalWrite(6, LOW);
      if (now > 3000) currentState = BLINK_FAST;
      break;

    case BLINK_FAST:
      if (now - previousMillis > 200) {
        previousMillis = now;
        digitalWrite(6, !digitalRead(6));
      }
      if (now > 8000) currentState = BLINK_SLOW;
      break;

    case BLINK_SLOW:
      if (now - previousMillis > 1000) {
        previousMillis = now;
        digitalWrite(6, !digitalRead(6));
      }
      break;
  }
}

