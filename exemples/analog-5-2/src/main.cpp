// Varier l'intensité d'une DEL, connectée sur D3, en utilisant une boucle 'for'
#include <Arduino.h>

int ledPin = 3; 

void setup() {
  // Rien à faire ici
  Serial.begin(9600);
}

void loop() {
  // Allumer graduellement la DEL en pas de 5 
  Serial.println("Allumer graduellement la DEL en pas de 5");
  for (int intensite = 0; intensite < 255; intensite += 5) {
    analogWrite(ledPin, intensite);
    delay(30);
  }

  // Éteindre graduellement la DEL en pas de 5 
  Serial.println("Éteindre graduellement la DEL en pas de 5");
  for (int intensite = 255; intensite >= 0; intensite -= 5) {
    analogWrite(ledPin, intensite);
    delay(30);
  }

  // delay(500); // Maintenir la DEL éteinte 0,5 sec.
}
