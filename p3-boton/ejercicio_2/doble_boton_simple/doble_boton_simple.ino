// Pines de los botones
const byte botonPinRed = 2;
const byte botonPinYellow = 3;   

// Estados de los botones
bool pulsadoRed = false;
bool pulsadoYellow = false;

// Variables para medir el tiempo de las pulsaciones.
unsigned long iniTimeRed = 0;
unsigned long iniTimeYellow = 0;

// Pines de los LEDs
const int ledRed = 9;
const int ledYellow = 10;

void setup() {
  Serial.begin(9600);

  // Modos de los pines de los botones
  pinMode(botonPinRed, INPUT);
  pinMode(botonPinYellow, INPUT);

  // Modos de los pines de los LEDs
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
}

void loop() {

  if(digitalRead(botonPinRed) == LOW){ // condicion de boton para ledRed
    if (!pulsadoRed){
      digitalWrite(ledRed, HIGH);
      pulsadoRed = true;
    }
  }
  else{
    pulsadoRed = false;
    digitalWrite(ledRed, LOW);
  }

  if(digitalRead(botonPinYellow) == LOW){ // condicion de boton para ledYellow
    if (!pulsadoYellow){
      digitalWrite(ledYellow, HIGH);
      pulsadoYellow = true;
    }
  }
  else{
    pulsadoYellow = false;
    digitalWrite(ledYellow, LOW);
  }
}
 

