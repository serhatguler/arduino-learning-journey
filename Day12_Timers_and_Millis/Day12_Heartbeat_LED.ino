#define ledPin 6

unsigned long previousMillis = 0;
const unsigned long interval = 1000; // 1 second

bool ledState = false;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}