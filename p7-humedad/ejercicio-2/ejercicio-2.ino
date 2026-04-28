const byte pinSensorHumedad = A0;
const byte ledred1 = 12;
const byte ledgreen = 11;
const byte ledred2 = 10;


void setup() {
  Serial.begin(9600);
  pinMode(ledred1, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(ledred2, OUTPUT);
}

void apagarleds(){
  digitalWrite(ledred1, LOW);
  digitalWrite(ledgreen, LOW);
  digitalWrite(ledred2, LOW);
}

void loop() {
  apagarleds();
  if (analogRead(pinSensorHumedad) < 624){
  digitalWrite(ledred1, HIGH);
  Serial.println("Nivel de Agua muy Alto");
  }
  else if (analogRead(pinSensorHumedad) < 824){
    digitalWrite(ledgreen, HIGH);
    Serial.println("Nivel de Agua Perfecto");
  }
  else{
    digitalWrite(ledred2, HIGH);
    Serial.println("Nivel de Agua muy Bajo");
  }
}

