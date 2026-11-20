#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

char message[]      = "La voix des Misterons";
int longueurMessage = 21;

void setup()
{
    lcd.begin(16, 2);
}

void loop()
{
    lcd.setCursor(0, 0);
    // Imprimer les car '0' à '9'
    for (int caractere = 0; caractere < 10; caractere++)
    {
        lcd.print(caractere);
        delay(300);
    }

    lcd.setCursor(16,1);
    // Activer le scroll automatique
    lcd.autoscroll();
 
    // Parcourir tous les caractères du message
    for (int caractere = 0; caractere < longueurMessage; caractere++)
    {
        // Afficher le caractère courant de la chaine
        lcd.print(message[caractere]);
        delay(200);
    }
    // désactiver le scroll automatique
    lcd.noAutoscroll();

    // Effacer l'écran
    lcd.clear();
}
