/*
    Fichier:  fn-map-println.ino
    Auteur:   Alain Boudreault
    Date:     2021.09.17
    --------------------------------------------------------------------------
    Description: Exemple d'une conversion des valeurs d'une entrée digitale
                 comprises entre 0..1023 vers une plage de valeurs
                 comprises entre 0..255.

                 Les valeurs converties sont affichées dans le terminal série
                 en utilisant Serial.print()
    --------------------------------------------------------------------------
    M-A-J:       2025.03.03 - Ajout de Arduino.h
    --------------------------------------------------------------------------    
*/

#include <Arduino.h>

// Définition des constantes
const int brocheDuSenseur  = A0;      // Sélection de la broche du potentiomètre
const int vitesseUART      = 19200;   // Vitesse du port de communication série

// Les variables globales
int valeurDuPotentiometre = 0;

// ---------------------------------------
// Initialisation des paramètres de départ
// ---------------------------------------
void setup() {
  Serial.begin(vitesseUART);
  Serial.print("Programme: fn-map-print.ino\n");
  Serial.print("Auteur:    Alain Boudreault\n");
  Serial.print("----------------------------\n");
  Serial.print("---- Début du programme ----\n");
  Serial.print("----------------------------\n\n");
} // setup()

// -------------------------------------
// Fonction principale de l'application
// -------------------------------------
void loop() {

  // Boucler sur la prochaine ligne tant que la valeur du Pot n'aura pas changé de plus de 1/1023. 
  while (abs(valeurDuPotentiometre - analogRead(brocheDuSenseur)) < 2);
  
  // Lire et stocker la valeur du potentiomètre
  // NOTE: Les broches analogiques n'ont pas à être initialisées.
  valeurDuPotentiometre = analogRead(brocheDuSenseur);
  
  // Convertir la plage des valeurs
  int valeurConvertieDuPotentiometre = map(valeurDuPotentiometre, 0, 1023, 0, 255);
  
  // Afficher les résultats en utilisant Serial.print()
  Serial.print("Valeur du pot avant conversion: ");
  Serial.print(valeurDuPotentiometre);
  Serial.print(" après conversion: ");
  Serial.println(valeurConvertieDuPotentiometre);
   
  // Ajout d'un délai pour ne pas saturer le moniteur série
  delay(500);
} // loop()
