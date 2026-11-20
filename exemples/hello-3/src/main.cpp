#include <Arduino.h>
// Projet: Introduction à Arduino
// Auteur: Alain Boudreault
// Date: 2021.07.17

void setup() {
  pinMode(13, 1); // OUTPUT
}

void loop() {
  digitalWrite(13, 1); // ON
  delay(500);
  digitalWrite(13, 0); // OFF
  delay(500);
}
