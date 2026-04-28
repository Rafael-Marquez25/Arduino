// Declarcion de los puertos de los leds
const int ledPin1 = 9;
const int ledPin2 = 10;
const int ledPin3 = 11;
const int ledPin4 = 12;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}
void loop() {
  for (int i = 0; i < 250; i++) // Bucle para que los leds se enciendan prograsivamente de forma escalonada
  {
    analogWrite(ledPin1, i);
    if (i < 188)
    {
      analogWrite(ledPin2, i);
    }
    if (i < 125)
    {
      analogWrite(ledPin3, i);
    }
    if (i < 63)
    {
      analogWrite(ledPin4, i);
    }
    delay(10);
  }

  for (int i = 250; i > 0; i--) // Bucle para que los leds se apagen progresivamente forma escalonada
  {
    analogWrite(ledPin1, i);
    if(i < 188)
    {
      analogWrite(ledPin2, i);
    }
    if(i < 125)
    {
      analogWrite(ledPin3, i);
    }
    if(i < 63)
    {
      analogWrite(ledPin4, i);
    }
    delay(10);
  }
}