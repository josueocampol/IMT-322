#define TIEMPO_INICIAL 5 
#define CANCION_INICIAL 0
#define TOTAL_CANCIONES 10

volatile int contador = TIEMPO_INICIAL;
bool modoAleatorio = true;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (contador > 0) {
    Serial.print("Tiempo restante: ");
    Serial.print(contador);
    Serial.println(" segundos");
    delay(1000);
    contador--;
  } else {
    Serial.println("siguiente canción", CANCION_INICIAL);


    contador = TIEMPO_INICIAL; 
  }
}
