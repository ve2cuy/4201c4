// Inclure les fonctions du LCD
#include "rgb_lcd.h"

// Définir un objet LCD (rgb_lcd).  
// Il servira à contrôler l'écran LCD.
rgb_lcd lcd;

const int colorR = 255;  // Intensité de rouge
const int colorG = 255;  // Intensité de vert
const int colorB = 255;  // Intensité de bleu

void setup() 
{
    // Initialiser le LCD en précisant le nb de lignes (2) de colonnes (16).
    lcd.begin(16, 2);
    
    // Renseigner la couleur de fond de l'écran LCD.
    lcd.setRGB(colorR, colorG, colorB);
    
    // Afficher un message sur l'écran LCD
    lcd.print("Bonjour 420 ;-)");

    delay(1000);
}

void loop() 
{
    // Placer le curseur sur la deuxième ligne, première colonne.
    // Ligne 1 = 0, Colonne 1 = 0
    lcd.setCursor(0, 1);
    // Afficher le nombre de secondes depuis le démarrage de l'application.
    // Note: La fn millis() retourne le nombre de ms écoulées depuis le début de l'application.
    lcd.print(millis()/1000);

    // Arrêter le programme pendant une seconde
    delay(1000);
}
