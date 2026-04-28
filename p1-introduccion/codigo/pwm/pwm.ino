const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  analogWrite(ledPin, 255);  // max
  delay(1000);
  analogWrite(ledPin, 127);  // medium
  delay(1000);
  analogWrite(ledPin, 90);  // low
  delay(1000);
}