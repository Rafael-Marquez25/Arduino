const byte botonPin = 2;
bool pulsado = false;
int contador = 0;

void setup() {
  pinMode(botonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(botonPin) == LOW) {
    if (!pulsado) {
      contador++;
      Serial.println(contador);
      pulsado = true;
    }
  }
  else {
    pulsado = false;
    }
}
