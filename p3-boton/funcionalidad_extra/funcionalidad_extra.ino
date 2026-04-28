// Pin del botón
const byte botonPin = 2;

// Variables de estado
volatile bool pulsado = false;
unsigned long iniTime = 0;

// Pines del LED RGB
const int ledRed = 11;
const int ledGreen = 9;
const int ledBlue = 10;

int contador = 0;

void setup() {
  Serial.begin(9600);

  pinMode(botonPin, INPUT_PULLUP);

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);

  // Iniciar LEDs apagados
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, HIGH);

  attachInterrupt(digitalPinToInterrupt(botonPin), InterrupcionBoton, FALLING);
}

void loop() {
  if (pulsado) {
    pulsado = false;  // reinicia la bandera

    contador++;
    if (contador > 3) contador = 1; // vuelve a 1 después del azul

    // Apagar todos los LEDs antes de encender el nuevo color
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledBlue, HIGH);

    switch (contador) {
      case 1:
        digitalWrite(ledRed, LOW);   // Rojo
        Serial.println("Color: Rojo");
        break;
      case 2:
        digitalWrite(ledGreen, LOW); // Verde
        Serial.println("Color: Verde");
        break;
      case 3:
        digitalWrite(ledBlue, LOW);  // Azul
        Serial.println("Color: Azul");
        break;
    }
  }
}

void InterrupcionBoton() {
  if (millis() - iniTime > 250) { // evita rebotes
    pulsado = true;
    iniTime = millis();
  }
}
