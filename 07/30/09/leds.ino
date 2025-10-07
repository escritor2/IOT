// Biblioteca para conexão LCD paralelo (sem I2C)
#include <LiquidCrystal.h>

// Configurando para o SEU display 16x2: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(13, 11, 5, 4, 3, 2);

// Definindo os pinos dos LEDs
const int ledVerde   = 8;
const int ledVermelho = 9;
const int ledAzul    = 10;

void setup() {
  // Inicializa o LCD
  lcd.begin(16, 2);
  lcd.print("Iniciando...");

  // Configura LEDs como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}

void loop() {
  // LED Verde
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAzul, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LED VERDE ON");
  delay(2000);

  // LED Vermelho
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledAzul, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LED VERMELHO ON");
  delay(2000);

  // LED Azul
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAzul, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LED AZUL ON");
  delay(2000);
}
