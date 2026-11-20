#include <Arduino.h>
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int unCaractere = 'a';

void setup() 
{
    // Définir la taille de l'écran
    lcd.begin(16, 2);
    // afficher le curseur
    lcd.cursor();
}

void loop() 
{
    // changer la direction d'affichage si 'm':
    if (unCaractere == 'm') 
    {
        // afficher de roite à gauche
        lcd.rightToLeft();
    }
    // changer la direction d'affichage si 's':
    if (unCaractere == 's') 
    {
        // afficher de gauche à droite
        lcd.leftToRight();
    }
    // Si 'z' alors reset
    if (unCaractere > 'z')
    {
        // aller à (0,0):
        lcd.home();
        // Recommencer avec 'a'
        unCaractere = 'a';
    }
    // Afficher le car
    lcd.write(unCaractere);
    // Attendre un peu
    delay(500);
    // Incrémenter la valeur du caractère
    unCaractere++;
}
