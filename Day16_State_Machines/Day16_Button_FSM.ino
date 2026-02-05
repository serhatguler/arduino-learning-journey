enum State { OFF, ON };
State state = OFF;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(6, OUTPUT);
}

void loop() {
  static bool lastBtn = HIGH;
  bool btn = digitalRead(2);

  if (lastBtn == HIGH && btn == LOW) {
    state = (state == OFF) ? ON : OFF;
  }
  lastBtn = btn;

  digitalWrite(6, state == ON);
}


