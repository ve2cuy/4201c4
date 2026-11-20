#include <Arduino.h>
/*
  Fichier:      lire-switch.ino
  Auteur:       Alain Boudreault
  Date:         2021.09.07
  Description:  Allumer la LED sur GPIO-03 à partir de l'état de la switch sur GPIO-02.

  Note:         ON = 1, OFF = 0
*/

// Les MACROs
#define LED       3 
#define SWITCH    2    

// Les variables globales
int etatBouton      = 0;

// Renseigner les GPIO
void setup() {
  pinMode(LED, OUTPUT);     // OUTPUT et INPUT sont des macros de l'IDE Arduino
  pinMode(SWITCH, INPUT);   // Renseigner la broche 'SWITCH' en mode d'entrée (INPUT)
} // setup()


void loop() {
  etatBouton = digitalRead(SWITCH);  // Lire l'état du bouton.  
                                     // digitalRead() retourne '1' si bouton appuyé, sinon '0'
  digitalWrite(LED, etatBouton);     // Utiliser l'état du bouton (1|0) pour Allumer/Éteindre la DEL
} // loop()
