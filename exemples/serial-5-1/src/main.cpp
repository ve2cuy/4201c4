#include <Arduino.h>
/*
    Fichier:  bouton-permutation.ino
    Auteur:   Alain Boudreault
    Date:     2021.09.17
    --------------------------------------------------------------------------
    Description: Exemple d'un projet qui tient compte de l'état précédent
                 du bouton momentané.

                 L'application allume la DEL à la première utilisation 
                 du bouton puis l'éteint à la suivante ...

    --------------------------------------------------------------------------
    M-A-J:    2022.09.12 - Ajout de code pour le relâchement du bouton.
                           Gestion du bruit du bouton
    --------------------------------------------------------------------------    
*/

// -----------------------------
// Les Macros
#define ON              HIGH
#define OFF             LOW
#define BROCHE_BOUTON   4
#define BROCHE_DEL      3
#define OUI             true
#define NON             false

// -----------------------------
// Les variables globales
bool etatDuBoutonAChange  = NON;
bool etatDeLaDEL          = OFF;         // État courant de la DEL (ON/OFF)


// -----------------------------
void setup()
{
  pinMode(BROCHE_BOUTON, INPUT);    
  pinMode(BROCHE_DEL, OUTPUT);
}

// -----------------------------
void loop()
{
  if (digitalRead(BROCHE_BOUTON))       // Lire le bouton
  {
    if (etatDuBoutonAChange == OUI)     // Si l'état du bouton a changé alors
    {
      etatDuBoutonAChange = NON;        // Réinitialiser l'état du bouton
      etatDeLaDEL = !etatDeLaDEL;       // Inverser l'état de la DEL (ON/OFF)
    }
    while(digitalRead(BROCHE_BOUTON));  // Attendre le relâchement du bouton
    delay(50);                          // Éliminer le bruit du bouton.
  
  }                                  
  else etatDuBoutonAChange = OUI;       // Sinon, indiquer que l'état du bouton a changé

  // Allumer ou éteindre la DEL
  digitalWrite(BROCHE_DEL, etatDeLaDEL); 
 
} // loop()
