#define ledPin 6

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();

    if (cmd == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    } 
    else if (cmd == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
  }
}