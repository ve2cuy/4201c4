// -----------------------------------------------
// Projet: Introduction à Arduino - faire clignoter la DEL
// Notes de cours : Hello World, section 2
// -----------------------------------------------
// La DEL « L » de l'Arduino UNO, branchée sur la broche 13,
// s'allume une demi-seconde, puis s'éteint une demi-seconde.

#include <Arduino.h>   // nécessaire avec PlatformIO (fichier .cpp)

void setup() {
  pinMode(13, 1);       // la broche 13 en sortie (OUTPUT)
}

void loop() {
  digitalWrite(13, 1);  // allumer (HIGH)
  delay(500);
  digitalWrite(13, 0);  // éteindre (LOW)
  delay(500);
}
