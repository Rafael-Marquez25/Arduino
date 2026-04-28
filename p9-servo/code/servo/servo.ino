#include <Servo.h>

Servo miServo;
const int PIN_CONTROL = 9;  // Pin PWM

// Ajustar según el servo para calibrar velocidades
constexpr int PULSO_MAX_ADELANTE = 1720;
constexpr int PULSO_MAX_ATRAS    = 1280;
constexpr int PULSO_PARADO       = 1500;

constexpr int PULSO_MID_ADELANTE = 1610;
constexpr int PULSO_MID_ATRAS    = 1390;

String comando = " ";
void setup() {
  Serial.begin(9600);
  
  // Inicialización del motor
  miServo.attach(PIN_CONTROL);
  miServo.writeMicroseconds(PULSO_PARADO);  // Iniciar parado
  
  Serial.println("Comandos: w (adelante), s (atras), x (parar)");
}

void loop() {
  if (Serial.available() > 0) {
    comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando == "wmax" || comando == "WMAX") {
      Serial.println("Moviendo hacia delante");
      moverAdelante();

    } else if (comando == "smax" || comando == "SMAX") {
        Serial.println("Moviendo hacia atras");
        moverAtras();

    } else if (comando == "wmid" || comando == "WMID") {
        Serial.println("Moviendo hacia delante");
        moverAdelanteMid();

    } else if (comando == "smid" || comando == "SMID") {
        Serial.println("Moviendo hacia atras");
        moverAtrasMid();

    } else if (comando == "x" || comando == "X") {
        Serial.println("Parando");
        pararMotor();

    } else if (comando == "\n" || comando == "\r") {
        // Ignorar saltos de línea
    } else {
        Serial.println("Error: Comando desconocido.");
    }
  }
}


void moverAdelante() {
  miServo.writeMicroseconds(PULSO_MAX_ADELANTE);
}

void moverAtras() {
  miServo.writeMicroseconds(PULSO_MAX_ATRAS);
}

void pararMotor() {
  miServo.writeMicroseconds(PULSO_PARADO); 
}

void moverAdelanteMid() {
  miServo.writeMicroseconds(PULSO_MID_ADELANTE);
}

void moverAtrasMid() {
  miServo.writeMicroseconds(PULSO_MID_ATRAS);
}
