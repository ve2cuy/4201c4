/*
    Utilisation du lcd_rgb avec un IO-Stream
*/

// Inclure les fonctions i2C
#include <Wire.h>
// Inclure les fonctions de le LCD
#include "rgb_lcd.h"

// #define DEBUG

#define ECRAN_NB_LIGNES       2
#define ECRAN_NB_COLONNES     16
#define POSITION_MILLISECONDE 07

// Définir une chaine de caractères
char ligneTexte[17];

// Définir un objet de type rgb_lcd
rgb_lcd ecran;

void setup() {
  ecran.begin(ECRAN_NB_COLONNES, ECRAN_NB_LIGNES);
}

void loop() {
  ecran.setCursor(POSITION_MILLISECONDE, 0);
  // %9 = 9 car minimun pour l'impression de la valeur
  // lu = entier long, non signé
  sprintf(ligneTexte, "%9lu", millis()); 
  ecran.print(ligneTexte);
  ecran.setCursor(POSITION_MILLISECONDE, 1);
  // %09 = 9 car minimun pour l'impression de la valeur, complété par des zéros à gauche.
  sprintf(ligneTexte, "%09lu", millis()); 
  ecran.print(ligneTexte);
}
