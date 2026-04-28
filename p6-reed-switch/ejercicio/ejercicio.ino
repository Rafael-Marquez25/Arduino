const byte reedSwitch = 2;
const byte pinLed = 3;

void setup() {
  Serial.begin(9600);
  pinMode(reedSwitch, INPUT);
  pinMode(pinLed, OUTPUT);
}

void loop() {
  if(digitalRead(reedSwitch) == 1)
  {
    digitalWrite(pinLed, HIGH);
  }
  else
  {
    digitalWrite(pinLed, LOW);
  }
}
