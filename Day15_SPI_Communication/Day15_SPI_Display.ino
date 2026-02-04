#include <SPI.h>

#define CS_PIN 10

void sendCommand(byte reg, byte data) {
  digitalWrite(CS_PIN, LOW);
  SPI.transfer(reg);
  SPI.transfer(data);
  digitalWrite(CS_PIN, HIGH);
}

void setup() {
  pinMode(CS_PIN, OUTPUT);
  SPI.begin();

  sendCommand(0x09, 0x00); // no decode
  sendCommand(0x0A, 0x03); // brightness
  sendCommand(0x0B, 0x07); // scan limit
  sendCommand(0x0C, 0x01); // normal mode
}

void loop() {
  sendCommand(0x01, B10101010);
  delay(500);
}

