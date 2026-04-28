const byte botonInicio = 2;       
const byte encoder = 3;           
bool pulsado = false;             
int numeroPulsos = 0;             
const int ranuras = 8;            // Número de ranuras del encoder por vuelta
const int factor = 60 / 5;        // Factor de conversión a RPM (60 segundos / 5 segundos de medición)
unsigned long tiempoInicio;       // Tiempo inicial de la medición
unsigned long tiempoActual;       // Tiempo transcurrido
double rpm;                       // Valor de RPM calculado

void setup() {
  pinMode(botonInicio, INPUT_PULLUP);                         
  pinMode(encoder, INPUT);                                    
  Serial.begin(9600);                                         
  attachInterrupt(digitalPinToInterrupt(encoder), interrupcionBoton, FALLING);
}

void loop() {
  // Espera hasta que se pulse el botón (el pin pasa de HIGH a LOW)
  Serial.println("Pulsa el botón para iniciar la medición...");
  while (digitalRead(botonInicio) == HIGH) {
    // Espera activa (no hace nada hasta que se pulse el botón)
  }

  Serial.println("Medición iniciada...");
  numeroPulsos = 0;                     // Reinicia el contador
  tiempoInicio = millis();              // Guarda el tiempo inicial
  tiempoActual = millis() - tiempoInicio;

  // Mide durante 5 segundos
  while (tiempoActual < 5000) {
    if (pulsado) {                      // Si se detectó un pulso
      numeroPulsos++;                   // Incrementa el contador
      pulsado = false;                  // Resetea la bandera
    }
    tiempoActual = millis() - tiempoInicio;  // Actualiza el tiempo transcurrido
  }

  // Cálculo de las RPM
  rpm = (numeroPulsos / (double)ranuras) * factor;

  // Muestra el resultado
  Serial.println("Los RPM son:");
  Serial.println(rpm);

  // Espera a que se suelte el botón antes de poder medir de nuevo
  while (digitalRead(botonInicio) == LOW);
  delay(500); // Pequeño retardo para evitar rebotes del botón
}

void interrupcionBoton() {
  pulsado = true;  
}
