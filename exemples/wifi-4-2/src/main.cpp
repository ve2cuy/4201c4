/*
 WiFiEsp exemple: Recherche des réseaux Wifi disponibles

 Auteur: Alain Boudreault
 Date:   2025.02.20
 ----------------------------
 Description:

 Ce programme recherche et affiche, aux DELAI_RECHERCHE_RESEAUX millisecondes,
 l'adresse MAC du module Wifi et recherche les réseaux Wifi disponibles.

  Le module ESP8266 est connecté à un Arduino Mega 2560 sur Serial1

  platformio.ini:
  [env:megaatmega2560]
  platform = atmelavr
  board = megaatmega2560
  framework = arduino
  monitor_speed = 115200
  lib_deps = 
    bportaluri/WiFiEsp@^2.2.2  
*/

#include <Arduino.h>
#include "WiFiEsp.h"

// Déclaration des constantes
#define VITESSE_SERIE           115200
#define DELAI_RECHERCHE_RESEAUX 10000
#define SECONDE                 1000

// Déclaration des fonctions
void afficherAdresseMAC();
void listerReseaux();
void afficherTydeDeCryptage(int thisType);

void setup() {
  Serial.begin(VITESSE_SERIE);   // Pour les messages de debug
  Serial1.begin(VITESSE_SERIE);  // Pour les commandes AT du module ESP8266
  Serial.println(F("\n\nExemple WiFiEsp: Recherche des réseaux Wifi disponibles\nAuteur: Alain Boudreault\nDate:   2025.02.20\n----------------------------\nDescription:\n\nCe programme recherche et affiche, aux DELAI_RECHERCHE_RESEAUX millisecondes,\nl'adresse MAC du module Wifi et recherche les réseaux Wifi disponibles.\n\nLe module ESP8266 est connecté à un Arduino Mega 2560 sur Serial1\n\n"));

  delay(SECONDE);
  WiFi.init(&Serial1);    // initialisation de la communication avec le module ESP8266


  Serial.println(F("\nInitialisation du module ESP8266..."));

  // Vérification de la présence du module ESP8266
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println(F("Module ESP8266 non détecté."));
    while (true);  // Ne pas continuer
  }

  afficherAdresseMAC();      // Affichage de l'adresse MAC du module ESP8266
} // Fin de la fonction setup()

void loop()
{
  // Recherche des réseaux disponibles
  Serial.println("\n----------------------------------");
  Serial.println("Recherche des réseaux disponibles:");
  Serial.println("----------------------------------\n");
  listerReseaux();
  delay(DELAI_RECHERCHE_RESEAUX);
} // Fin de la fonction loop()

void afficherAdresseMAC()
{
  // Obtenir l'adresse MAC du module ESP8266
  byte mac[6];
  WiFi.macAddress(mac);
  
  // print MAC address
  char buf[20];
  snprintf(buf, sizeof(buf) ,"%02X:%02X:%02X:%02X:%02X:%02X", mac[5], mac[4], mac[3], mac[2], mac[1], mac[0]);
  Serial.print("\nMAC adresse: ");
  Serial.println(buf);
} // Fin de la fonction afficherAdresseMAC()

void listerReseaux()
{
  // Recherche des réseaux disponibles
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1) {
    Serial.println("Impossible de scanner les réseaux disponibles");
    while (true);
  }

  // Affichage du nombre de réseaux disponibles
  Serial.print("Nombre de réseaux disponibles: ");
  Serial.print(numSsid);
  Serial.println("\n");

  // Affichage des réseaux disponibles et de leur force de signal
  for (int reseauCourant = 0; reseauCourant < numSsid; reseauCourant++) {
    Serial.print(reseauCourant);
    Serial.print(") ");
    Serial.print(WiFi.SSID(reseauCourant));
    Serial.print("\tSignal: ");
    Serial.print(WiFi.RSSI(reseauCourant));
    Serial.print(" dBm");
    Serial.print("\tCryptage: ");
    afficherTydeDeCryptage(WiFi.encryptionType(reseauCourant));
  }
} // Fin de la fonction listerReseaux()

void afficherTydeDeCryptage(int thisType) {
  // Tester le cryptage et afficher son type
  switch (thisType) {
    case ENC_TYPE_WEP:
      Serial.print("WEP");
      break;
    case ENC_TYPE_WPA_PSK:
      Serial.print("WPA_PSK");
      break;
    case ENC_TYPE_WPA2_PSK:
      Serial.print("WPA2_PSK");
      break;
    case ENC_TYPE_WPA_WPA2_PSK:
      Serial.print("WPA_WPA2_PSK");
      break;
    case ENC_TYPE_NONE:
      Serial.print("None");
      break;
  }
  Serial.println();
} // Fin de la fonction afficherTydeDeCryptage()

// Fin du programme
