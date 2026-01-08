/*
 * Day 03 - Analog Input to PWM Output
 */

const int potPin = A0;
const int ledPin = 9;

int potValue = 0;
int pwmValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);        // 0–1023
  pwmValue = map(potValue, 0, 1023, 0, 255);

  analogWrite(ledPin, pwmValue);

  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | PWM: ");
  Serial.println(pwmValue);

  delay(100);
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}