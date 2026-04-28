// Pin del boton
const byte botonPin = 2; 

// Estado del boton
volatile bool pulsado = false;

// contador
int contador = 0;
unsigned long ini_time;

void setup() {
  Serial.begin(9600);
  pinMode(botonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(botonPin), interrupcionBoton, FALLING);
}

void loop() {
  if (pulsado && millis() - ini_time > 200) { // Condicion para el antirebote 
    contador++;
    Serial.println(contador);
    pulsado = false;
  }
  
  
}

// Función llamada por la interrupción
void interrupcionBoton() {
  pulsado = true;
}