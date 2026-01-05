
/*
 * Day 01 : Blink LED
 * Board: Arduino UNO	
 */
// C++ code
//
void setup()
{
  pinMode(7, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  digitalWrite(7, HIGH);
  delay(2000);// Wait for 1000 millisecond(s)
  digitalWrite(7, LOW);
  delay(2000);// Wait for 1000 millisecond(s)
  
  digitalWrite(2,HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  delay(1000);
  
  digitalWrite(3, HIGH);
  delay(2000);
  digitalWrite(3, LOW);
  delay(2000);
  
  
  
}