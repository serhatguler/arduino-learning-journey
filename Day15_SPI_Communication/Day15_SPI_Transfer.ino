#include <SPI.h>

#define CS_PIN 10

void setup() {
  Serial.begin(9600);
  pinMode(CS_PIN, OUTPUT);
  SPI.begin();
}

void loop() {
  digitalWrite(CS_PIN, LOW);
  byte received = SPI.transfer(0x55);
  digitalWrite(CS_PIN, HIGH);

  Serial.print("Sent: 0x55, Received: ");
  Serial.println(received, HEX);
  delay(1000);
}