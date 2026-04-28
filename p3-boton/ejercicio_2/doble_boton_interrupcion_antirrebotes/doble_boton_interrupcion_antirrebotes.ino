// Pines de los botones
const byte botonPinRed = 2;
const byte botonPinYellow = 3;   

// Estados de los botones
volatile bool pulsadoRed = false;
volatile bool pulsadoYellow = false;

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

  // Interrupciones con la opccion CHANGE para detectar cuando se pulsa y se deja de pulsar el boton
  attachInterrupt(digitalPinToInterrupt(botonPinRed), InterrupcionBotonRed, CHANGE);
  attachInterrupt(digitalPinToInterrupt(botonPinYellow), interrupcionBotonYellow, CHANGE);
}

void loop() {
  
  if (pulsadoRed) {
    digitalWrite(ledRed, HIGH);
  }
  else
  {
    digitalWrite(ledRed, LOW);
  }

  if (pulsadoYellow) {
    digitalWrite(ledYellow, HIGH);
  }
  else
  {
    digitalWrite(ledYellow, LOW);
  } 
}

// Función llamada por la interrupción
void InterrupcionBotonRed(){
  if(millis() - iniTimeRed > 250){ // Condicion para eliminar rebotes
    pulsadoRed = !pulsadoRed;
    if (pulsadoRed)
    {
      Serial.println("[interrupcionBoton] Changed var pulsadoYellow from false to true");
    }
    else if (!pulsadoRed)
    {
      Serial.println("[interrupcionBoton] Changed var pulsadoYellow from true to false");
    }
    iniTimeRed = millis();
  }
}

void interrupcionBotonYellow() {
  if(millis() - iniTimeYellow > 250){ / Condicion para eliminar rebotes
    pulsadoYellow = !pulsadoYellow;
    if (pulsadoYellow)
    {
      Serial.println("[interrupcionBoton] Changed var pulsadoYellow from false to true");
    }
    else if (!pulsadoYellow)
    {
      Serial.println("[interrupcionBoton] Changed var pulsadoYellow from true to false");
    }
    iniTimeYellow = millis();
  }
}
