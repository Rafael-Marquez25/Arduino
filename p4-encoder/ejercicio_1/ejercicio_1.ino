const byte encoder = 2;          
bool pulsado = false;            
int numeroPulsos = 0;            // Contador de los pulsos detectados
const int ranuras = 8;           // Número de ranuras o marcas del encoder por vuelta
const int factor = 60/5;         // Factor para convertir los pulsos en RPM (60 segundos / 5 segundos de medición)
unsigned long tiempoInicio;      // Variable para almacenar el tiempo inicial de la medición
unsigned long tiempoActual;      // Variable para calcular el tiempo transcurrido
double rpm;                      // Variable para almacenar las revoluciones por minuto calculadas

void setup() {
  pinMode(encoder, INPUT);                                       
  Serial.begin(9600);                                            
  attachInterrupt(digitalPinToInterrupt(encoder), interrupcionBoton, FALLING);  
}

void loop() {
  tiempoInicio = millis();                  // Guarda el tiempo actual (inicio del periodo de medición)
  tiempoActual = millis() - tiempoInicio;   // Inicializa el tiempo transcurrido en 0
  
  // Bucle que dura el tiempo de medicion deseado, en este caso 5 segundos
  while(tiempoActual < 5000){
    if (pulsado){                           
      numeroPulsos++;                       
      pulsado = false;                      
    }
    tiempoActual = millis() - tiempoInicio; // Actualiza el tiempo transcurrido
  }

  // Cálculo de las RPM:
  // (número de pulsos / ranuras) da el número de vueltas en 5 segundos
  // Multiplicamos por "factor" (60/5 = 12) para obtener RPM
  rpm = (numeroPulsos / ranuras) * factor;  

  Serial.println("los rpm son:");           
  Serial.println(rpm);                      

  tiempoInicio = tiempoActual;              // Reinicia el tiempo de inicio 
  numeroPulsos = 0;                         // Reinicia el contador de pulsos para la siguiente medición
}

void interrupcionBoton() {
  pulsado = true;                          
}
