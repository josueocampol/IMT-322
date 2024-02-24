
#define   LED  2
#define   LED1  3
#define   LED2  4
#define   VELOCIDAD 200

void setup() {
  
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  
  digitalWrite(LED, HIGH);
  delay(VELOCIDAD); 
  digitalWrite(LED, LOW);


  digitalWrite(LED1, HIGH);
  delay(VELOCIDAD); 
  digitalWrite(LED1, LOW);

  
  digitalWrite(LED2, HIGH);
  delay(VELOCIDAD); 
  digitalWrite(LED2, LOW);
}