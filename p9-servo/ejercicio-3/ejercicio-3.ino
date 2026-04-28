#include <Servo.h>  // Incluye la librería Servo para controlar servomotores

Servo miServo;       // Crea un objeto Servo llamado "miServo"

const int PIN_CONTROL = 9;   // Pin PWM al que está conectado el servo
const int pinFeedback = 2;   // Pin donde se conecta la señal de feedback del servo

float PULSO;  // Variable para almacenar el pulso en microsegundos que se enviará al servo

void setup() {
  Serial.begin(9600);          // Inicializa la comunicación serial a 9600 baudios

  miServo.attach(PIN_CONTROL); // Conecta el objeto servo al pin definido
  pinMode(pinFeedback, INPUT); // Configura el pin de feedback como entrada

  miServo.writeMicroseconds(1500); // Inicializa el servo en posición "parado" (1500 µs)
  Serial.println("Ingrese velocidad entre -100 y 100"); // Mensaje inicial
}

void loop() {
  // Verifica si hay datos disponibles en el puerto serial
  if (Serial.available()) {
    // Lee el valor recibido y lo convierte a float
    float c = Serial.readStringUntil('\n').toFloat();

    // Solo actúa si el valor está dentro del rango -100 a 100 y no es 0
    if (c >= -100 && c <= 100 && c != 0) {

      // Leer la posición inicial del servo
      int anguloInicial = leerAngulo();

      // Convertir la velocidad ingresada a pulso en microsegundos
      if (c < 0)
        PULSO = 1280 + (c + 100) * 1.73;  // Velocidad negativa: sentido horario
      else
        PULSO = 1720 + (c - 100) * 1.94;  // Velocidad positiva: sentido antihorario

      // Mover el servo durante un tiempo fijo
      miServo.writeMicroseconds(PULSO);
      delay(200);   // Tiempo de movimiento en milisegundos

      // Detener el servo enviando pulso neutro
      miServo.writeMicroseconds(1500);
      delay(50);    // Pequeña pausa para estabilizar

      // Leer la posición final del servo
      int anguloFinal = leerAngulo();

      // Calcular la variación de ángulo
      int delta = anguloFinal - anguloInicial;

      // Imprimir el ángulo final
      Serial.print("Ángulo final: ");
      Serial.println(anguloFinal);
    }
  }
}

// Función para leer la posición del servo mediante feedback PWM
int leerAngulo() {
  unsigned long tHigh, tLow, tCycle;

  // Medir el ciclo de pulso hasta que esté dentro de un rango válido (1000 a 1200 µs)
  do {
    tHigh = pulseIn(pinFeedback, HIGH); // Tiempo en HIGH
    tLow  = pulseIn(pinFeedback, LOW);  // Tiempo en LOW
    tCycle = tHigh + tLow;              // Ciclo total
  } while (tCycle < 1000 || tCycle > 1200);

  // Calcular el duty cycle (%)
  float duty = 100.0 * tHigh / tCycle;

  // Convertir duty cycle a ángulo (0 a 359)
  int theta = (duty - 2.9) * 360.0 / (91.7 - 2.9);

  // Asegurar que el ángulo esté dentro de 0 a 359
  return constrain(theta, 0, 359);
}
