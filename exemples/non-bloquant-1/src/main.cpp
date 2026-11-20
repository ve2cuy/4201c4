#include <Arduino.h>

/*
  Blink sans delay()
  Auteur: Alain Boudreault
  Date:   2025.02.19
  Pour:   420-1C4, Objets connectés 
*/

const int ledPin    = 2;    // Broche de la DEL
const long interval = 500;  // Intervale de clignotement de la DEL (milliseconds)
int ledState        = LOW;  // État de départ de la DEL

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();

  // Exécution de code non bloquant pour le clignotement de la LED
  if (currentMillis - previousMillis >= interval) {
    // Enregistrer le temps du dernier clignotement 
    previousMillis = currentMillis;

    ledState = !ledState;             // Permuter l'état de la DEL
    digitalWrite(ledPin, ledState);   // Appliquer de changement
  }
} // loop()
