const int ledRojo = 2;
const int ledVerde = 3;
const int pulsadorReinicio = 4;
const int pulsadorAbrir = 5;

const String contrasenaCorrecta = "ucb.2024";

String contrasenaIngresada = "";
unsigned long tiempoInicio = 0;

unsigned long ultimoRebote = 0;
unsigned long tiempoAntirebote = 200;
bool estadoPulsadorAnterior = false;

bool accesoConcedido = false;

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  pinMode(pulsadorReinicio, INPUT_PULLUP);
  pinMode(pulsadorAbrir, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Ingrese la contraseña (15 segundos para ingresarla):");
}

void loop() {
  if (leerPulsador(pulsadorReinicio)) { //reviso estado del pulsador para su reicinio
    contrasenaIngresada = "";
    accesoConcedido = false;
    Serial.println("Ingrese la contraseña (15 segundos para ingresarla):");
    tiempoInicio = millis();
  }

  if (Serial.available() > 0) {
    char caracter = Serial.read();

    if (caracter == '\n') {
      if (contrasenaIngresada == contrasenaCorrecta) {
        accesoConcedido = true;
        Serial.println("Contraseña correcta");
      } else {
        accesoConcedido = false;
        contrasenaIngresada = "";
        Serial.println("Contraseña incorrecta");
      }
    } else {
      contrasenaIngresada += caracter;
    }

    tiempoInicio = millis(); //reinicio el tiempo si se ha ya ingresado el caracter
  }

  if (millis() - tiempoInicio > 15000) {
    contrasenaIngresada = "";
    accesoConcedido = false;
    Serial.println("Tiempo agotado. Ingrese la contraseña nuevamente:");
    tiempoInicio = millis();
  }

  if (leerPulsador(pulsadorAbrir) && accesoConcedido) { //reviso pulsador de apertura
    Serial.println("Cerradura abierta");
    accesoConcedido = false;
  }

  if (accesoConcedido) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledRojo, LOW);
  } else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledRojo, HIGH);
  }
}

bool leerPulsador(int pin) {
  bool estadoPulsador = digitalRead(pin) == LOW;
  if (estadoPulsador != estadoPulsadorAnterior) {
    ultimoRebote = millis();
  }
  if ((millis() - ultimoRebote) > tiempoAntirebote) {
    if (estadoPulsador != estadoPulsadorAnterior) {
      estadoPulsadorAnterior = estadoPulsador;
      if (estadoPulsador) {
        return true;
      }
    }
  }
  return false;
}