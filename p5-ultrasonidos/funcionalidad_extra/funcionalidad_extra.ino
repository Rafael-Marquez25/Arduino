const byte PIN_TRIGGER = 3;
const byte PIN_ECHO = 4;
const int pinGreen = 5;
const int pinYellow = 6;
const int pinRed = 7;
const int buzzer = 2;


const float V_SOUND_AIR = 0.0343f; // cm/us

float distance = 0.0f;   
long duration  = 0;      

void setup() {
  Serial.begin(9600);  // Start serial communication
  pinMode(PIN_TRIGGER, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinYellow, OUTPUT);  
  pinMode(pinRed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Ensure LOW in trigger at start 
  digitalWrite(PIN_TRIGGER, LOW);
  Serial.println("Waiting 2 seconds to stabilize ultrasonic sensor...");
  delay(2000);
}

void loop() {
  // Pulse generation in trigger
  digitalWrite(PIN_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER, LOW);

  // Read pulse duration and compute distance
  duration = pulseIn(PIN_ECHO, HIGH);
  distance = (duration * V_SOUND_AIR) / 2.0f;

  if (distance >= 20 && distance < 40)
  {
    ApagarTodos();
    digitalWrite(pinYellow, 1);
    digitalWrite(buzzer, 1);
    delay(100);
    digitalWrite(buzzer, 0);
  }

  else if (distance >= 40 && distance <= 60)
  {
    ApagarTodos();
    digitalWrite(pinGreen, 1);
    digitalWrite(buzzer, 1);
    delay(100);
    digitalWrite(buzzer, 0);
    delay(200);
  }

  else if (distance < 20 && distance >= 4)
  {
    ApagarTodos();
    digitalWrite(pinRed, 1);
    digitalWrite(buzzer, 1);
  }

  else{
    ApagarTodos();
    digitalWrite(buzzer, 0);
  }

  Serial.print("Distance: ");
  Serial.print(distance, 2);  // show 2 decimals
  Serial.println(" cm");

  delay(500);  // small delay between readings
}

void ApagarTodos (){
  digitalWrite(pinYellow, 0);
  digitalWrite(pinGreen, 0);
  digitalWrite(pinRed, 0);
}
