#define trigPin 9
#define echoPin 10
#define buzzerPin 6

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {
    tone(buzzerPin, 2000);   // very close
  } 
  else if (distance < 20) {
    tone(buzzerPin, 1000);   // warning
  } 
  else {
    noTone(buzzerPin);       // safe
  }

  delay(200);
}