const byte botonPin = 2;   
volatile bool pulsado = false;
int contador = 0;
unsigned long ini_time;

void setup() {
  Serial.begin(9600);
  pinMode(botonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(botonPin), interrupcionBoton, FALLING);
}

void loop() {
  if (pulsado && millis() - ini_time > 200) {
    contador++;
    Serial.println(contador);
    pulsado = false;
    Serial.println(millis() - ini_time);
    ini_time = millis();
  }
  
  
}

// Función llamada por la interrupción
void interrupcionBoton() {
  pulsado = true;
}
