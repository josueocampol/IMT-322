#include <Arduino.h>

#define BTN1 2
#define BTN2 3
#define LED 12   

int count = 0;
unsigned long debounceDelay = 200; 
unsigned long lastTime1 = 0;
unsigned long lastTime2 = 0;
unsigned long delayTimes[] = {500, 1000, 1500};  
int numDelayTimes = 3;

void incCount() {
  if (millis() - lastTime1 >= debounceDelay) {
    count++;
    lastTime1 = millis();
    Serial.print(count);
  }
}

void changeDelay() {
  if (millis() - lastTime2 >= debounceDelay) {
    count++;
    if (count >= numDelayTimes) {
      count = 0;
    }
    lastTime2 = millis();
  }
}

void setup() {
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BTN1), incCount, FALLING);
  attachInterrupt(digitalPinToInterrupt(BTN2), changeDelay, FALLING);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(delayTimes[count]);
  digitalWrite(LED, LOW);
  delay(delayTimes[count]);
}