/* 
   --------------------------------------------------------------------------
   Projet:         Introduction à Arduino, la broche analogique.
   Nom du fichier: digitalRead.ino
   Auteur:         Alain Boudreault
   Date:           2022.09.10
   ---------------------------------------------------------------------------
   Description:    Petit programme qui lit la valeur d'un module analogique
                   (potentiomètre) et affiche la valeur dans la console série
   ---------------------------------------------------------------------------
   M-A-J:          2022.09.14 - Nom des constantes en caractères majuscules.
                   2025.03.03 - Ajout de Arduino.h + délai d'affichage
   ---------------------------------------------------------------------------
*/
#include <Arduino.h>

//**********************************
// Les constantes
//**********************************
const int BROCHE_DU_SENSEUR     = A0;    // La broche du potentiomètre
const int BROCHE_DE_LA_DEL      = 3;     // La broche de la DEL.
const int VITESSE_UART          = 9600;  // Vitesse de la console série
const int DELAI_AFFICHAGE       = 150;  

//**********************************
void setup() {
  pinMode(BROCHE_DE_LA_DEL, OUTPUT);
  Serial.begin(VITESSE_UART);
} // setup()

//**********************************
void loop() {
  int valeurDuPotentiometre = 0;     
  // Lire et afficher la valeur du potentiomètre
  // NOTE: Les broches analogiques n'ont pas à être initialisées.
  valeurDuPotentiometre = analogRead(BROCHE_DU_SENSEUR);
  Serial.print("Valeur du pot: ");
  Serial.println(valeurDuPotentiometre);
  // Ajout d'un délai pour ne pas saturer le moniteur série
  delay(DELAI_AFFICHAGE);
} // loop()

//****** FIN DU FICHIER
