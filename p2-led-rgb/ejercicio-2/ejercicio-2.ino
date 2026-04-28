// Valores de los leds
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
  gestionarRGB('G', 0);
  gestionarRGB('B', 0);

  // Configuracion del serial
  Serial.begin(9600);

  // Mensaje de inicio.
  Serial.println("Elige un color: rojo, verde, azul, magenta, amarillo, cyan, blanco, naranja seguidos de 0 o 1 en funcion de si quieres apagar o encender el color, solo se contempla la combinacion de colores primarios:");
}

void loop(){
  if(Serial.available() > 0){
    String input = Serial.readStringUntil('\n');
    Serial.println(input);

    // Comprobamos la cadena recibida y en funcio del caso encendemos unos leds u otros.
    if(input == "rojo1"){
      gestionarRGB('R', 1);
    }
    else if(input == "rojo0"){
      gestionarRGB('R', 0);
    }
    else if(input == "verde1"){
      gestionarRGB('G', 1);
    }
    else if(input == "verde0"){
      gestionarRGB('G', 0);
    }
    else if(input == "azul1"){
      gestionarRGB('B', 1);
    }
    else if(input == "azul0"){
      gestionarRGB('B', 0);
    }
    else if(input == "magenta1"){
      magenta(1);
    }
    else if(input == "amarillo1"){
      amarillo(1);
    }
    else if(input == "cyan1"){
      cyan(1);
    }
    else if(input == "blanco1"){
      blanco(1);
    }
    else if(input == "naranja1"){
      naranja(1);
    }
    else{
      gestionarRGB('R', 0);
      gestionarRGB('G', 0);
      gestionarRGB('B', 0);
    }
  }
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
