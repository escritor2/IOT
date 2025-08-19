int vermelho = 2;
int amarelo = 3;
int verde = 4;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // Verde
  digitalWrite(7, HIGH);
  delay(5000);
  digitalWrite(7, LOW);
  
  // Amarelo
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(8, LOW);
  
  // Vermelho
  digitalWrite(9, HIGH);
  delay(5000);
  digitalWrite(9, LOW);
}