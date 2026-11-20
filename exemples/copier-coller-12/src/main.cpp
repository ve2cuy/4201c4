#include <Arduino.h>
/*
  Projet:  C:\Users\alin_\Documents\PlatformIO\Projects\Projet02\src
  Fichier: main.cpp
  Auteur:  
  Date:    2025-01-28 17:06:27
-----------------------------------------------
  Description:

-----------------------------------------------
  M-A-J:
*/

#include "main.h"

rgb_lcd ecran;

void setup() {
  Serial.begin(VITESSE_UART);
  Serial.println(F("Début du programme ..."));
  ecran.begin(16,2);
} // setup()

void loop() {
  ecran.clear();
  ecran.print("Variation de RED");
  for (int i = 255; i > 0; i-=10)
    { 
      ecran.setRGB(i,0,0);
      ecran.setCursor(0,1);
      ecran.print("i = ");
      ecran.setCursor(4,1);
      ecran.print("   ");
      ecran.setCursor(4,1);
      ecran.print(i);
      AFFICHER(i);AFFICHER("\n");
      delay(UN_COURT_MOMENT);
    }
} // loop()

// FIN DU FICHIER
