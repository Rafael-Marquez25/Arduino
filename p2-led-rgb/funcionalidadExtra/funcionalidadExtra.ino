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
  gestionarIntensidadRGB("rojo", 255);
  gestionarIntensidadRGB("verde", 255);
  gestionarIntensidadRGB("azul", 255);

  // Configuracion del serial
  Serial.begin(9600);
  
}

void loop(){
  Serial.println("Escribe un color entre rojo, verde y azul: ");

  while (Serial.available() == 0) {
    // Esto sirve para esperar hasta que el usurio escriba algo.
  }

  String color = Serial.readStringUntil('\n');
  color.trim(); // quita espacios inecesarios
  Serial.println(color);

  Serial.println("Escribe la intensidad: ");

  while (Serial.available() == 0) {
    // Esperar aquí hasta que haya algo nuevo
  }

  
  String intensidad = Serial.readStringUntil('\n');
  intensidad.trim();
  Serial.println(intensidad);
  

  gestionarIntensidadRGB(color, intensidad.toInt());
  Serial.println(" ");

}


void gestionarIntensidadRGB(String color, int intensidad){ // Ahora la funcion recibe el color y la intensidad.
  if (color == "rojo"){
    analogWrite(ledRed, intensidad);
  }
  else if (color == "azul"){
    analogWrite(ledBlue, intensidad);
  }
  else if (color == "verde"){
    analogWrite(ledGreen, intensidad);
  }
}