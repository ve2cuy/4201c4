/*
    Fichier:      eeprom-afficher.cpp
    Auteur:       Alain Boudreault
    Date:         2026.11.07
    --------------------------------------------------------------------------
    Description:  Afficher le contenu de l'EEPROM, 16 octets par ligne,
                  en hexadécimal.
    --------------------------------------------------------------------------
*/
#include <Arduino.h>
#include <EEPROM.h>

#define OCTETS_PAR_LIGNE    16
#define VITESSE_UART        9600

void setup() {
  char texte[8];
  Serial.begin(VITESSE_UART);
  Serial.print("Taille de l'EEPROM: ");
  Serial.print(EEPROM.length());
  Serial.println(" octets\n");

  for (int adresse = 0; adresse < EEPROM.length(); adresse++) {
    // Au début de chaque ligne, afficher l'adresse de la première case
    if (adresse % OCTETS_PAR_LIGNE == 0) {
      sprintf(texte, "\n%04X: ", adresse);
      Serial.print(texte);
    }
    sprintf(texte, "%02X ", EEPROM.read(adresse));
    Serial.print(texte);
  }
} // setup()

void loop() {}
