#include <Arduino.h>
int leds[] = {2, 3, 4, 5};
int numLeds = 4;

void setup() {
  for(int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for(int numero = 0; numero < 16; numero++) {
    mostrarBinario(numero);
    delay(1000);
  }
}

void mostrarBinario(int numero) {
  for(int i = 0; i < numLeds; i++) {
    int bit = bitRead(numero, i);
    digitalWrite(leds[i], bit);
  }
}