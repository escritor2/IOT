void setup() {
    pinMode(13, OUTPUT); // define o pino 13 como saída
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(2, INPUT_PULLUP); // define o pino 2 como entrada com resistor de pull-up interno
}

void loop() {
    // Verifica se o botão foi pressionado (LOW porque usamos PULLUP)
    if(digitalRead(2) == LOW) {
        // Executa a sequência de LEDs quando o botão é pressionado
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        delay(1000);
        digitalWrite(8, HIGH);
        delay(2000);
        digitalWrite(8, LOW);
        delay(2000);
        digitalWrite(9, HIGH);
        delay(3000);
        digitalWrite(9, LOW);
        delay(3000);
    }
}