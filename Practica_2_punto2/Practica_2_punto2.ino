// Pines
#define BOTONPIN 2
#define LEDPIN 3

// Contador  
volatile unsigned int contador = 0;

void setup() {

  // Configuración de pines
  pinMode(LEDPIN, OUTPUT);
  pinMode(BOTONPIN, INPUT_PULLUP);

  // Interrupción en flanco de subida
  attachInterrupt(digitalPinToInterrupt(BOTONPIN), handleButton, CHANGE);  //RISING 0v a 5v //FALLING de 5v a 0v //CHANGE en ambos casos
  Serial.begin(9600);

}

void loop() {

    digitalWrite(LEDPIN, 1);
  delay(300);
  digitalWrite(LEDPIN, 0);
  delay(300);
  
    Serial.println(contador); 
  
}

void handleButton() {

  // Incrementa contador al presionar 
  contador++;
  
}
