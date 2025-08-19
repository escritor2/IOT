int leds[] = {2, 3, 4, 5, 6, 7, 8};
int numLeds = 7;

void setup() {
  for(int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW);
  }
  
  for(int i = numLeds - 2; i > 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW);
  }
}