int botao = 2;
int led = 13;
int estadoBotao = 0;
int estadoAnterior = 0;
int estadoLed = LOW;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  estadoBotao = digitalRead(botao);
  
  if(estadoBotao == LOW && estadoAnterior == HIGH) {
    estadoLed = !estadoLed;
    digitalWrite(13, estadoLed);
    delay(200); // Debounce
  }
  
  estadoAnterior = estadoBotao;
}