#define buttonPin 2
#define ledPin 6

unsigned long previousMillis = 0;
bool ledEnabled = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  static bool lastButton = HIGH;
  bool currentButton = digitalRead(buttonPin);

  if (lastButton == HIGH && currentButton == LOW) {
    ledEnabled = !ledEnabled;
  }
  lastButton = currentButton;

  if (ledEnabled) {
    if (millis() - previousMillis >= 1000) {
      previousMillis = millis();
      digitalWrite(ledPin, !digitalRead(ledPin));
    }
  } else {
    digitalWrite(ledPin, LOW);
  }
}