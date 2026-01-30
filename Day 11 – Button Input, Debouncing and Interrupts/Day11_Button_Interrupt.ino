#define buttonPin 2
#define ledPin 6

volatile bool ledState = false;

void handleButtonPress() {
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, FALLING);
}

void loop() {
  // main loop stays free
}