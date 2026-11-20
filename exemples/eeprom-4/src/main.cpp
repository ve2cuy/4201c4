/*
    Fichier:      eeprom-compteur.cpp
    Auteur:       Alain Boudreault
    Date:         2026.11.07
    Clientèle:    Étudiant(e)s du cours 420-1C4: Objets connectés de CSTJ.
    --------------------------------------------------------------------------
    Description:  Compter le nombre de démarrages de l'Arduino.
                  Le compteur est conservé dans l'EEPROM, il survit donc
                  à un RESET ou à une coupure de courant.
    --------------------------------------------------------------------------
*/
#include <Arduino.h>
#include <EEPROM.h>

#define ADRESSE_COMPTEUR    0       // La case de l'EEPROM réservée au compteur
#define VITESSE_UART        9600

void setup() {
  Serial.begin(VITESSE_UART);

  // 1 - Lire la valeur conservée dans l'EEPROM
  byte nbDemarrages = EEPROM.read(ADRESSE_COMPTEUR);

  // 2 - Augmenter le compteur
  nbDemarrages++;

  // 3 - Conserver la nouvelle valeur. Une seule écriture par démarrage.
  EEPROM.write(ADRESSE_COMPTEUR, nbDemarrages);

  Serial.print("Nombre de démarrages: ");
  Serial.println(nbDemarrages);
} // setup()

void loop() {
  // Rien à faire ici, et surtout pas d'écriture dans l'EEPROM!
} // loop()
