// valores de los leds
const int ledRed = 9;
const int ledBlue = 10;
const int ledGreen = 11;

void setup(){
  // pines de los leds
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  
  // Apagamos los leds al principio poque al estar conectado a 5V se encienden automaticamente.
  gestionarRGB('R', 0);
  gestionarRGB('B', 0);
  gestionarRGB('G', 0);
}

void loop() {
  // Encendemos los diferentes colores para comprobar que funcionan.
  magenta(1);
  delay(500);
  magenta(0);
  delay(500);

  amarillo(1);
  delay(500);
  amarillo(0);
  delay(500);

  cyan(1);
  delay(500);
  cyan(0);
  delay(500);

  blanco(1);
  delay(500);
  blanco(0);
  delay(500);

  naranja(1);
  delay(500);
  naranja(0);
  delay(500);
}

void encenderColor(int pin){ 
  digitalWrite(pin, LOW);
}

void apagarColor(int pin){
  digitalWrite(pin, HIGH);
}

void gestionarRGB(char color, int estado){ // Funcion para endender o apagar los leds, recibe como argumento R, G o b y 0 o 1.
  switch (color) {
    case 'R':
      if(estado == 1){
        encenderColor(ledRed);
      }
      else{
        apagarColor(ledRed);
      }
      break;

    case 'G':
      if(estado == 1){
        encenderColor(ledGreen);
      }
      else{
        apagarColor(ledGreen);
      }
      break;

    case 'B':
    if(estado == 1){
        encenderColor(ledBlue);
      }
      else{
        apagarColor(ledBlue);
      }
      break;
        
    default:
      break;
  }
}

void magenta(int estado){
  if (estado == 1){
    gestionarRGB('R', 1);
    gestionarRGB('B', 1);
  }
  else{
    gestionarRGB('R', 0);
    gestionarRGB('B', 0);
  }
}

void amarillo(int estado){
  if (estado == 1){
    gestionarRGB('G', 1);
    gestionarRGB('R', 1);
  }
  else{
    gestionarRGB('G', 0);
    gestionarRGB('R', 0);
  }
}

void cyan(int estado){
  if (estado == 1){
    gestionarRGB('G', 1);
    gestionarRGB('B', 1);
  }
  else{
    gestionarRGB('G', 0);
    gestionarRGB('B', 0);
  }
}

void blanco(int estado){
  if (estado == 1){
    gestionarRGB('R', 1);
    gestionarRGB('G', 1);
    gestionarRGB('B', 1);
  }
  else{
    gestionarRGB('R', 0);
    gestionarRGB('G', 0);
    gestionarRGB('B', 0);
  }
}

void naranja(int estado){
  if (estado == 1){
    analogWrite(ledRed, 55);
    analogWrite(ledGreen, 200);
  }
  else{
    gestionarRGB('R', 0);
    gestionarRGB('G', 0);
  }
}


