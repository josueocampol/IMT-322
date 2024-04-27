#include "funciones.h"
#define BOTON 2

int Monto;
int Bebida;
int Periodo = 100;
int Cambio;
unsigned long tiempoAnterior = 0;

bool Bandera = true;
bool Bandera2 = true;
bool Bandera3 = true;

typedef enum{
  Estado1,
  Estado2,
  Estado3
}maquina;
maquina Estado = Estado1;



void setup() {
  pinMode(BOTON, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Bienvenido");
}

void loop() {
  
  switch (Estado){
    case Estado1:
      if(Bandera){
        Serial.println("Porfavor ingrese su monto de dinero: ");
        Bandera = false;
        Bandera3 = true;
      }
      delay(500);
      if(Serial.available() > 0){
        Monto = Serial.parseInt();
        if(Monto >= 2){
          Estado = Estado2;
          Serial.println("Cargando Menú.");
          delay(1000);
        }else if(Monto > 0){
          Serial.println("No tienes suficiente dinero.");
        }
      }
    break;
    case Estado2:
      if(Bandera2){
        Serial.println("Menú");
        Serial.println("1. Bebida 2bs");
        Serial.println("2. Bebida 5bs");
        Serial.println("3. Bebida 7bs");
        Bandera2 = false;
      }
      if(Serial.available() > 0){
        Bebida = Serial.read();
        switch (Bebida){
          case '1':
            Serial.print("Tu Cambio es de: ");
            Serial.print(Monto-2);
            Serial.println("Bs");
            mostrarBarraDeCarga(1000);
            Serial.println("Bebida lista.");
            Estado = Estado3;
          break;
          case '2':
            Serial.print("Tu Cambio es de: ");
            Serial.print(Monto-5);
            Serial.println("Bs");
            mostrarBarraDeCarga(2000);
            Serial.println("Bebida lista.");
            Estado = Estado3;
          break;
          case '3':
            Serial.print("Tu Cambio es de: ");
            Serial.print(Monto-7);
            Serial.println("Bs");
            mostrarBarraDeCarga(3000);
            Serial.println("Bebida lista.");
            Estado = Estado3;
          break;
        }
        
      }
    break;
    case Estado3:
    if(Bandera3){
      Serial.println("Puede retirar el vaso.");
      Bandera3 = false;
    }
      if(digitalRead(BOTON) == 0){
        unsigned long tiempoActual = millis();
          if (tiempoActual - tiempoAnterior > Periodo){
              Bandera = true;
              Bandera2 = true;
              Estado = Estado1;
            tiempoAnterior = tiempoActual;
          }
      }
    break;
  }
}