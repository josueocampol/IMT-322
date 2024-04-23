#define VELOCIDAD_BAUD 9600

enum Piso {
  PRIMER_PISO,
  SEGUNDO_PISO,
  TERCER_PISO
};

Piso pisoActual = PRIMER_PISO;

void setup() {
  Serial.begin(VELOCIDAD_BAUD);
  Serial.println("Simulador de Ascensor");
  Serial.println("Ingrese '1' para Primer Piso, '2' para Segundo Piso, '3' para Tercer Piso");
}

void loop() {
  if (Serial.available() > 0) {
    char entrada = Serial.read();
    switch (entrada) {
      case '1':
        moverAscensor(PRIMER_PISO);
        break;
      case '2':
        moverAscensor(SEGUNDO_PISO);
        break;
      case '3':
        moverAscensor(TERCER_PISO);
        break;
      default:
        Serial.println("Entrada inválida. Por favor, inténtelo de nuevo.");
    }
  }
}

void moverAscensor(Piso destino) {
  if (pisoActual!= destino) {
    Serial.print("Moviendo desde ");
    imprimirPiso(pisoActual);
    Serial.print(" a ");
    imprimirPiso(destino);
    Serial.println("...");
    delay(2000); // simular movimiento del ascensor
    pisoActual = destino;
    Serial.print("Llegada al ");
    imprimirPiso(pisoActual);
    Serial.println();
  } else {
    Serial.println("Ya estoy en ese piso.");
  }
}

void imprimirPiso(Piso piso) {
  switch (piso) {
    case PRIMER_PISO:
      Serial.print("Primer Piso");
      break;
    case SEGUNDO_PISO:
      Serial.print("Segundo Piso");
      break;
    case TERCER_PISO:
      Serial.print("Tercer Piso");
      break;
  }
}