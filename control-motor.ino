// Definición de pines Motor 1
const int ENA = 11;    // PWM Motor 1
const int IN1 = 13;    // Control dirección Motor 1
const int IN2 = 12;    // Control dirección Motor 1
const int LED1 = 10;   // LED indicador adelante M1
const int LED2 = 9;   // LED indicador atrás M1

// Definición de pines Motor 2
const int ENB = 6;   // PWM Motor 2
const int IN3 = 8;   // Control dirección Motor 2
const int IN4 = 7;   // Control dirección Motor 2
const int LED3 = 5;   // LED indicador adelante M2
const int LED4 = 4;   // LED indicador atrás M2

// Tiempos en milisegundos
const int TIEMPO_ADELANTE = 2000;
const int TIEMPO_REPOSO = 3000;
const int TIEMPO_ATRAS = 2000;

// Valores PWM
const int VELOCIDAD_FULL = 255;    // 100% duty cycle
const int VELOCIDAD_75 = 191;      // 75% duty cycle
void setup() {
  // Configurar pines como salidas
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void adelante(){
  // Motor 1 adelante
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, VELOCIDAD_FULL);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);

  // Motor 2 adelante
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, VELOCIDAD_FULL);
  digitalWrite(LED3, HIGH);
  digitalWrite(LED4, LOW);
}

void reposo(){
 // Ambos motores en reposo
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  // Apagar todos los LEDs
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
}

void atras(){
  // Motor 1 atrás
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, VELOCIDAD_75);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);

  // Motor 2 atrás
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, VELOCIDAD_75);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, HIGH);
}

void loop() {
  adelante(); // Adelante 100%
  delay(TIEMPO_ADELANTE);     // Por 2 segundos

  reposo(); //reposo
  delay(TIEMPO_REPOSO); // Por 3 segundos

  atras();// Atrás 75%
  delay(TIEMPO_ATRAS);        // Por 2 segundos

  reposo();//reposo
  delay(TIEMPO_REPOSO); // Por 3 segundos
}
