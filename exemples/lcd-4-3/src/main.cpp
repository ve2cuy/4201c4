#include <Arduino.h>
/*
    Utilisation du lcd_rgb avec un IO-Stream
*/

// Inclure les fonctions de le LCD
#include "rgb_lcd.h"
#include <Streaming.h> 

#define ECRAN_NB_LIGNES     2
#define ECRAN_NB_COLONNES   16

// Définir une chaine de caractères
char message[17] = "Bonjour Le Monde";

// Définir un objet de type rgb_lcd
rgb_lcd ecran;

void setup() {
  ecran.begin(ECRAN_NB_COLONNES, ECRAN_NB_LIGNES);
  ecran << message;

}

void loop() {}
