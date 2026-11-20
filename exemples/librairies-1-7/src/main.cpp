#include <Arduino.h>
#include <Streaming.h>

void setup() {
  Serial.begin(9600);
  Serial << "Bonjour le Monde!" << endl;
}

void loop() {
}
