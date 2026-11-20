/*
    Fichier:      eeprom-configuration.cpp
    Auteur:       Alain Boudreault
    Date:         2026.11.07
    --------------------------------------------------------------------------
    Description:  Conserver la configuration d'un système dans l'EEPROM,
                  avec EEPROM.put() et EEPROM.get().
                  Un 'c' dans le moniteur série change la configuration,
                  un 'r' la remet aux valeurs par défaut.
    --------------------------------------------------------------------------
*/
#include <Arduino.h>
#include <EEPROM.h>

#define ADRESSE_CONFIGURATION   16      // Après le compteur (0) et l'intensité (1)
#define SIGNATURE               0x1C4A    // Pour reconnaître une configuration valide
#define VITESSE_UART            9600

struct Configuration {
  uint16_t signature;
  char     nomDuSysteme[10];
  byte     volume;                // 0..10
  float    seuilTemperature;      // En degrés Celsius
};

const Configuration CONFIGURATION_PAR_DEFAUT = { SIGNATURE, "E0000001", 5, 28.5 };

Configuration config;             // La configuration en mémoire vive (SRAM)

void afficherConfiguration() {
  Serial.print("Système: ");      Serial.println(config.nomDuSysteme);
  Serial.print("Volume: ");       Serial.println(config.volume);
  Serial.print("Seuil: ");        Serial.print(config.seuilTemperature);
  Serial.println(" C");
  Serial.print("Taille de la structure: ");
  Serial.print(sizeof(config));
  Serial.println(" octets\n");
} // afficherConfiguration()

void setup() {
  Serial.begin(VITESSE_UART);

  // 1 - Lire toute la structure d'un seul coup
  EEPROM.get(ADRESSE_CONFIGURATION, config);

  // 2 - Signature absente: l'EEPROM n'a jamais reçu de configuration
  if (config.signature != SIGNATURE) {
    Serial.println("Aucune configuration, utilisation des valeurs par défaut.");
    config = CONFIGURATION_PAR_DEFAUT;
    EEPROM.put(ADRESSE_CONFIGURATION, config);
  }
  afficherConfiguration();
} // setup()

void loop() {
  switch (Serial.read()) {
    case 'c':   // Changer la configuration et la conserver
      config.volume = (config.volume + 1) % 11;
      config.seuilTemperature += 0.5;
      EEPROM.put(ADRESSE_CONFIGURATION, config);
      Serial.println("Configuration modifiée et conservée:");
      afficherConfiguration();
      break;
    case 'r':   // Revenir aux valeurs par défaut
      config = CONFIGURATION_PAR_DEFAUT;
      EEPROM.put(ADRESSE_CONFIGURATION, config);
      Serial.println("Valeurs par défaut:");
      afficherConfiguration();
      break;
  } // switch
} // loop()
