#define LED1 2
#define LED2 3
#define LED3 4
#define BUTTON 7
#define VELOCIDAD 200

int currentSequence = 1;
bool buttonState = false;
bool lastButtonState = false;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(BUTTON);

  if (buttonState != lastButtonState && buttonState == HIGH) {
    currentSequence = (currentSequence == 1) ? 2 : 1;
  }

  switch (currentSequence) {
    case 1:
      digitalWrite(LED1, HIGH);
      delay(VELOCIDAD);
      digitalWrite(LED1, LOW);
      delay(VELOCIDAD);
      digitalWrite(LED2, HIGH);
      delay(VELOCIDAD);
      digitalWrite(LED2, LOW);
      delay(VELOCIDAD);
      digitalWrite(LED3, HIGH);
      delay(VELOCIDAD);
      digitalWrite(LED3, LOW);
      delay(VELOCIDAD);
      break;
    case 2:
      digitalWrite(LED1, HIGH);
      delay(VELOCIDAD);
      digitalWrite(LED1, LOW);
      delay(VELOCIDAD);
      digitalWrite(LED3, HIGH);
      delay(VELOCIDAD);
      digitalWrite(LED3, LOW);
      delay(VELOCIDAD);
      digitalWrite(LED2, HIGH);
      delay(VELOCIDAD);
      digitalWrite(LED2, LOW);
      delay(VELOCIDAD);
      break;
  }

  lastButtonState = buttonState;
}