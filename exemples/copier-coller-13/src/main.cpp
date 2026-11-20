#include <Arduino.h>
#include "rgb_lcd.h"

rgb_lcd ecran;  // Déclaration de l'objet de contrôle du LCD 

void uneFonctionAmusante();
void setup() {
  ecran.begin(16,2);
  ecran.print("Coucou");
}

void loop() {
  static long unsigned int i = 1;
  ecran.clear();
  ecran.print("i = ");
  ecran.print(i++);
  delay(500);
  uneFonctionAmusante();
}

void uneFonctionAmusante(){
    
    ecran.setCursor(0, 0);  // Curseur à la position (0,0)

    // Afficher 0 à 9:
    for (int thisChar = 0; thisChar < 10; thisChar++) {
        ecran.print(thisChar);
        delay(50);
    } // for

    ecran.setCursor(16, 1); // Curseur à la position (16,1):
    ecran.autoscroll();     // Activer le défilement
    // Afficher 0 à 9:
    for (int thisChar = 0; thisChar < 10; thisChar++) {
        ecran.print(thisChar);
        delay(50);
    }
    ecran.noAutoscroll();   // Desactiver le défilement
    ecran.clear();          // Effacer l'écran:
} // uneFonctionAmusante
