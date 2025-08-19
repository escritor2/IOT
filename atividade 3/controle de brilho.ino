int led = 9; // Pino PWM (deve ter ~ no pino)
int brilho = 0;
int incremento = 5;

void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
  analogWrite(9, brilho);
  brilho += incremento;
  
  if(brilho <= 0 || brilho >= 255) {
    incremento = -incremento;
  }
  
  delay(30);
}