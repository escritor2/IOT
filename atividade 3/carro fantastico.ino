#include <Arduino.h>

int leds[] = {2, 3, 4, 5, 6, 7, 8};
int numLeds = 7;
int velocidade = 100; 

void setup() {

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);


  for(int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void loop() {

  for(int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], HIGH);
    delay(velocidade);
    digitalWrite(leds[i], LOW);
  }
  

  for(int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(velocidade);
    digitalWrite(leds[i], LOW);
  }
}

