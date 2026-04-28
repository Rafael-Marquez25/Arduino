#include <Servo.h> // Incluye la librería Servo, necesaria para controlar servomotores

Servo miServo;       // Crea un objeto Servo llamado "miServo"
const int PIN_CONTROL = 9;  // Pin PWM al que está conectado el servo

// Variable para almacenar el pulso que se enviará al servo
float PULSO;

String comando = " ";  // Variable para almacenar los comandos recibidos por Serial

void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial a 9600 baudios
  
  // Inicialización del servo
  miServo.attach(PIN_CONTROL);         // Conecta el objeto servo al pin definido
  miServo.writeMicroseconds(1500);    // Inicializa el servo en posición "parado" (1500 µs = punto medio)
}

void loop() {
  // Verifica si hay datos disponibles en el puerto serial
  if (Serial.available() > 0) {
    // Lee la línea completa recibida por Serial hasta un salto de línea
    String comando = Serial.readStringUntil('\n');
    
    // Convierte el comando recibido a un valor numérico de tipo float
    float PULSO = comando.toFloat();
    
    // Si el pulso está dentro del rango permitido para el servo, se envía
    if(PULSO >= 1280 && PULSO <= 1720)
    {
      miServo.writeMicroseconds(PULSO); // Envía el pulso al servo
    }
  }
}

// Comentarios adicionales sobre el comportamiento del servo
// 1526 µs es el mínimo para que funcione en sentido antihorario
// 1453 µs es el mínimo para que funcione en sentido horario
