#define BOTON_CONTAR 2
#define BOTON_RESETEAR 3
#define VELOCIDAD_BAUDIOS 9600
#define LED 13

volatile unsigned long ultima_vez_boton_contar = 0;
volatile unsigned long ultima_vez_boton_resetear = 0;
volatile unsigned long retraso_rebote = 10;
volatile bool reinicio_solicitado = false;
volatile int contador = 0;

void setup() {
    pinMode(BOTON_CONTAR, INPUT_PULLUP);
    pinMode(BOTON_RESETEAR, INPUT_PULLUP);
    pinMode(LED, OUTPUT);

    attachInterrupt(digitalPinToInterrupt(BOTON_CONTAR), Contar, RISING);
    attachInterrupt(digitalPinToInterrupt(BOTON_RESETEAR), Resetear, RISING);

    Serial.begin(VELOCIDAD_BAUDIOS);
}

void loop() {
    digitalWrite(LED, 1);
    delay(200);
    digitalWrite(LED, 0);
    delay(200);
}

void Contar() {
    unsigned long tiempo_actual = millis();

    if (tiempo_actual - ultima_vez_boton_contar > retraso_rebote) {
        if (digitalRead(BOTON_CONTAR) == HIGH) {
            contador++;
            Serial.println(contador);
        } else {
            if (tiempo_actual - ultima_vez_boton_contar >= 3000) {
                contador = 0;
                Serial.println("RESETEADO");
            }
        }
        ultima_vez_boton_contar = tiempo_actual;
    }
}

void Resetear() {
    if (millis() - ultima_vez_boton_resetear > retraso_rebote) {
        contador -= 1;
        ultima_vez_boton_resetear = millis();
        Serial.println(contador);
    }
}