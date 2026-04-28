const byte pinSensorHumedad = 2;
volatile bool cambioDetectado = false;

void setup() {
  Serial.begin(9600);
  pinMode(pinSensorHumedad, INPUT);
  
  // Adjuntar interrupción al pin 2
  // CHANGE: se dispara cuando el pin cambia de estado (HIGH a LOW o LOW a HIGH)
  attachInterrupt(digitalPinToInterrupt(pinSensorHumedad), cambioHumedad, CHANGE);
  
  // Imprimir estado inicial
  imprimirEstado();
}

void loop() {
  // Si hubo un cambio, imprimir el nuevo estado
  if(cambioDetectado){
    cambioDetectado = false;
    imprimirEstado();
  }
}

// Función de interrupción (ISR)
void cambioHumedad() {
  cambioDetectado = true;
}

// Función para imprimir el estado actual
void imprimirEstado() {
  if(digitalRead(pinSensorHumedad)){
    Serial.println("Nivel de humedad Insuficiente");
  }
  else{
    Serial.println("Nivel de humedad Suficiente");
  }
}