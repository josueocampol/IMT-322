#define PIN_TRIG 9
#define PIN_ECHO 8
#define PIN_BOTON 2

#define DISTANCIA_MAXIMA 200 
#define INTERVALO_MEDICION 5000 
#define RETARDO_ANTIREBOTE 50 

volatile bool disparar_medicion = false; 
volatile unsigned long ultima_medicion = 0; 
volatile unsigned long ultimo_presionado = 0; 
volatile bool estado_boton = false; 

unsigned long ancho_pulso;
float distancia;

void interrupcion_boton() {
  unsigned long tiempo_actual = millis();
  if (tiempo_actual - ultimo_presionado > RETARDO_ANTIREBOTE) {
    estado_boton = !estado_boton; 
    ultimo_presionado = tiempo_actual; 
  }
}

void interrupcion_echo() {
  static unsigned long tiempo_inicio; 
  unsigned long tiempo_actual = micros();

  if (digitalRead(PIN_ECHO) == HIGH) {
    tiempo_inicio = tiempo_actual; 
  } else {
    ancho_pulso = tiempo_actual - tiempo_inicio; 
    distancia = ancho_pulso * 0.034 / 2; 
    disparar_medicion = false; 
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(PIN_BOTON, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(PIN_ECHO), interrupcion_echo, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_BOTON), interrupcion_boton, FALLING);
}

void loop() {
  unsigned long tiempo_actual = millis();

  // Verificar si ha transcurrido el intervalo de medición y el botón está presionado
  if (tiempo_actual - ultima_medicion >= INTERVALO_MEDICION && estado_boton) {
    disparar_medicion = true; 
    ultima_medicion = tiempo_actual; 

    digitalWrite(PIN_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, LOW);
  }

  if (!disparar_medicion && distancia <= DISTANCIA_MAXIMA) {
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");
  }
}