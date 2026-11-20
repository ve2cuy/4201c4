/*
    Fichier:      eeprom-intensite.cpp
    Auteur:       Alain Boudreault
    Date:         2026.11.07
    --------------------------------------------------------------------------
    Description:  Régler l'intensité d'une DEL avec le potentiomètre et
                  conserver ce réglage dans l'EEPROM.
    Modules:      Potentiomètre sur A0, DEL sur D3 (PWM)
    --------------------------------------------------------------------------
*/
#include <Arduino.h>
#include <EEPROM.h>

#define BROCHE_POT            A0
#define BROCHE_DEL            3
#define ADRESSE_INTENSITE     1     // La case 0 est réservée au compteur de démarrages
#define DELAI_LECTURE         100

void setup() {
  pinMode(BROCHE_DEL, OUTPUT);
  // Reprendre l'intensité conservée lors de la dernière utilisation
  analogWrite(BROCHE_DEL, EEPROM.read(ADRESSE_INTENSITE));
  delay(2000);
} // setup()

void loop() {
  // analogRead() retourne 0..1023, une case de l'EEPROM contient 0..255:
  // il faut diviser par 4 (ou utiliser map()).
  byte intensite = analogRead(BROCHE_POT) / 4;

  analogWrite(BROCHE_DEL, intensite);

  // Écrire seulement si l'intensité a changé
  EEPROM.update(ADRESSE_INTENSITE, intensite);

  delay(DELAI_LECTURE);
} // loop()
