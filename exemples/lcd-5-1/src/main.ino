/*
    Utilisation du lcd_rgb avec un IO-Stream
*/

// Inclure les fonctions i2C
#include <Wire.h>
// Inclure les fonctions de le LCD
#include "rgb_lcd.h"
#include <Streaming.h> 

#define DEBUG

#define ECRAN_NB_LIGNES     2
#define ECRAN_NB_COLONNES   16

// Définir une chaine de caractères
char message[80];
char ligne_lcd[17];

// Définir un objet de type rgb_lcd
rgb_lcd ecran;

void setup() {
  int   i   = 99;
  float pi  = 3.14;
  char  c   = '@';
  char  texte[] = "Une chaine";
  Serial.begin(9600);

  ecran.begin(ECRAN_NB_COLONNES, ECRAN_NB_LIGNES);
#ifdef DEBUG
  Serial << "Début du programme\n\n";
#endif
  ecran << "i=" << i;
  ecran << ", pi=" << pi;
  // Déplacer le curseur à la ligne 2, colonne 1
  ecran.setCursor(0, 1);
  ecran << "c=" << c;
  // Attendre 2 sec puis effacer l'écran
  delay(2000);
  ecran.clear();
  ecran << texte;
  // Déplacer le curseur à la ligne 2, colonne 1
  ecran.setCursor(0, 1);
#ifdef DEBUG
  // Sous Arduino, sprintf n'implémente pas les float.
  sprintf(message, "i = %d, pi = %f, c = %c, texte = %s", i, pi, c, texte);
  Serial << message;
#endif

  unsigned int entierNonSigne = 0b10101010101010;
  sprintf(message, "entierNonSigne : %u, hex : %x, HEX : %X, Octal = %o", entierNonSigne , entierNonSigne, entierNonSigne, entierNonSigne);
  Serial << endl << endl << message;

}

void loop() {}
