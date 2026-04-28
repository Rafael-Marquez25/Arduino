const byte StrengthSensor = A0;

void setup() {
  Serial.begin(9600);
  pinMode(StrengthSensor, INPUT);
}

void loop() {
  Serial.println(analogRead(StrengthSensor));
}