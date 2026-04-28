#include <Servo.h>  // Incluye la librería Servo para controlar servomotores

Servo miServo;          // Crea un objeto Servo llamado "miServo"
const int PIN_CONTROL = 9;  // Pin PWM al que está conectado el servo

// Variable para almacenar el valor del pulso que se enviará al servo
float PULSO;

// Variable para almacenar los comandos recibidos por Serial
String comando = " ";

void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial a 9600 baudios
  
  // Inicialización del servo
  miServo.attach(PIN_CONTROL);       // Conecta el objeto servo al pin definido
  miServo.writeMicroseconds(1500);   // Inicia el servo en posición "parado" (1500 µs = punto medio)
  
  // Mensaje inicial para indicar cómo enviar comandos
  Serial.println("Comandos: ingrese una velocidad entre -100 y 100");
}

void loop() {
  // Verifica si hay datos disponibles en el puerto serial
  if (Serial.available() > 0) {
    // Lee la línea completa recibida por Serial hasta un salto de línea
    comando = Serial.readStringUntil('\n');
    
    // Convierte el comando recibido a un valor numérico de tipo float
    float c = comando.toFloat();
  
    // Verifica si el valor está dentro del rango válido de -100 a 100
    if (c >= -100 && c <= 100) {

      if (c == 0){
        // Velocidad cero: servo parado
        PULSO = 1500;
      }
      else if(c < 0){
        // Velocidad negativa: movimiento en sentido horario
        // La fórmula ajusta el pulso desde el mínimo 1280 µs hasta 1500 µs
        PULSO = 1280 + (c + 100) * 1.73;
      }
      else if(c > 0)
      {
        // Velocidad positiva: movimiento en sentido antihorario
        // La fórmula ajusta el pulso desde 1720 µs hasta el máximo 1740 µs
        PULSO = 1720 + (c - 100) * 1.94;
      }
      
      Serial.println(c);  // Muestra en Serial la velocidad recibida

      miServo.writeMicroseconds(PULSO);  // Envía el pulso calculado al servo
    }
    // Si el valor está fuera del rango permitido
    else if(c < -100 || c > 100){
      Serial.println("Número fuera de rango.");
    }
    // Ignora saltos de línea
    else if (comando == "\n" || comando == "\r") {
        // Nada
    } 
    // Cualquier otro comando no reconocido
    else {
      Serial.println("Error: Comando desconocido.");
    }
  }
}

// Función para parar el motor enviando el pulso neutro (1500 µs)
void pararMotor() {
  miServo.writeMicroseconds(1500); 
}
