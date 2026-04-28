const byte PresenceSensor = 2;

void setup() {
  Serial.begin(9600);
  pinMode(PresenceSensor, INPUT);
}

void loop() {
  Serial.println(digitalRead(PresenceSensor));
}

