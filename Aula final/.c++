#include <math.h>
#include "DHT.h"
#define DHTPIN A5
#define DHT DHT11


DHT  dht(DHTPIN, DHT);
const int leds[] = {3 ,5 ,6};


int r, g, b{0};



void setup(){
  for(int i{0}; i< 3; i++){
    pinMode(leds[i], OUTPUT);
  }
  dht.begin();
  Serial.begin(9600);
}
int t{0};
void loop(){
  t = dht.readTemperature();
  r = map(t, 0, 50, 0, 255);
  b = map(t, 0, 50, 255, 0);

  analogWrite(leds[0], r);
  analogWrite(leds[2], b);
  Serial.println(t);
  delay(2000);


 
}
