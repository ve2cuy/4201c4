#include <Arduino.h>
#include <Wire.h>
#include "rgb_lcd.h"

#define TEXTE           "Bonjour 420 ;-)"
#define LONGUEUR_TEXTE  15
#define LARGEUR_ECRAN   16 
#define DELAI_CAR       150
#define DELAI_CYCLE     1000

rgb_lcd lcd;

void setup() {
    lcd.begin(LARGEUR_ECRAN, 2);
    lcd.print(TEXTE);
    delay(DELAI_CYCLE * 2);
}

void loop() {
    // Déplacer le texte vers la gauche
    for (int position = 0; position < LONGUEUR_TEXTE; position++) {
        // Déplacer de un car vers la gauche
        lcd.scrollDisplayLeft();
        delay(DELAI_CAR);
    }

    for (int position = 0; position < LONGUEUR_TEXTE + LARGEUR_ECRAN ; position++) {
        // Déplacer de un car vers la droite
        lcd.scrollDisplayRight();
        delay(DELAI_CAR);
    }

    // Replacer le texte au début de l'écran
    for (int position = 0; position < LARGEUR_ECRAN; position++) {
        lcd.scrollDisplayLeft();
        delay(DELAI_CAR);
    }

    delay(DELAI_CYCLE);
}
