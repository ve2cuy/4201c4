#include <Arduino.h>

void blink();
const int pin = 2;              // définir la broche d'interruption à 2
const int ledPin = 4;           // définir la broche de la LED à 4

volatile int state = LOW;      // Pour garantir que les variables partagées entre une ISR et le programme principal 
                               // soient mises à jour correctement, il faut les déclarer comme volatile.

void setup() {
   pinMode(ledPin, OUTPUT); // définir la broche 13 comme sortie
   attachInterrupt(digitalPinToInterrupt(pin), blink, CHANGE);
   // interruption à la broche 2, exécute l'ISR blink lorsque la broche change de valeur
} 

void loop() { 
  // digitalWrite(ledPin, state); // la broche 13 prend la valeur de 'state'
} 

void blink() { 
  // fonction ISR
  state = !state; // inverser l'état lorsque l'interruption se produit
  digitalWrite(ledPin, state); // la broche 13 prend la valeur de 'state'
}
