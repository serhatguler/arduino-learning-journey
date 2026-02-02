#define led1 6
#define led2 7

unsigned long t1 = 0;
unsigned long t2 = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  unsigned long now = millis();

  if (now - t1 >= 500) {
    t1 = now;
    digitalWrite(led1, !digitalRead(led1));
  }

  if (now - t2 >= 200) {
    t2 = now;
    digitalWrite(led2, !digitalRead(led2));
  }
}
