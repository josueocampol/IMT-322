#define     ROJO         1
#define     AMARILLO     2
#define     VERDE        3
#define     TIME         2000

typedef enum{
  ROJO1,
  AMARILLO1,
  VERDE1
}semaforo;
int estado = 0;

semaforo FSM = ROJO1;


void setup() {
  pinMode (ROJO, OUTPUT);
  pinMode (AMARILLO, OUTPUT);
  pinMode (VERDE, OUTPUT);
}

void loop() {
  switch(estado){
    case 0:
      digitalWrite(ROJO,HIGH); 
      digitalWrite(AMARILLO,LOW);
      digitalWrite(VERDE,LOW);
      delay(TIME);
      estado =1;
      FSM = ROJO1;
      break;
       
    case 1:
      digitalWrite(ROJO,LOW); 
      digitalWrite(AMARILLO,HIGH);
      digitalWrite(VERDE,LOW);
      delay(TIME);
      estado =2;
      FSM = AMARILLO1;
      break;
    case 2: 
      digitalWrite(ROJO,LOW); 
      digitalWrite(AMARILLO,LOW);
      digitalWrite(VERDE,HIGH);
      delay(TIME);
      estado =0;
      FSM=VERDE1;
      break;
  }
}
