#include <Arduino.h>
#define BTN1 2
#define BTN2 3
int count = 0;
unsigned long debounceDelay = 4000;

void incCount() {
  unsigned long lastTime1 = 0;
  if (millis() - lastTime1 >= debounceDelay) {
    count++;
    lastTime1 = millis();
  }
}

void resetCount() {
  unsigned long lastTime1 = 0;
  if (millis() - lastTime1 >= debounceDelay) {
    count = 0;
    lastTime1 = millis();
  }
}

void setup() {
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BTN1), incCount, FALLING);
  attachInterrupt(digitalPinToInterrupt(BTN2), resetCount, FALLING);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Contador: ");
  Serial.println(count);
  delay(100);
}