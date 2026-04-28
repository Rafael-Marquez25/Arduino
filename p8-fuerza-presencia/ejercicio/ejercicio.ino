const byte PresenceSensor = 2;
const byte StrengthSensor = A0;
const byte led = 3;
unsigned long time;
void setup() {
  Serial.begin(9600);
  pinMode(PresenceSensor, INPUT);
  pinMode(StrengthSensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  if(analogRead(StrengthSensor) > 50)
  {
    time = millis();
    while(millis() < time + 30000)
    {
      if(digitalRead(PresenceSensor) == 1)
      {
        digitalWrite(led, HIGH);
      }
      else
      {
        digitalWrite(led, LOW);
      }
    }
  }
}

