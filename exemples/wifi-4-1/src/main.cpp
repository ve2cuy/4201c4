/*
  ESP8266 AT Command Tester
  
  Ce programme permet de tester les commandes AT de l'ESP8266
  en utilisant un module ESP8266 connecté au port Serial1.

  Voici les commandes AT les plus courantes:
  - AT        : test de communication
  - AT+GMR    : affiche la version du firmware
  - AT+CWLAP  : scan des réseaux wifi
  - AT+CWJAP="SSID","password" : connexion à un réseau wifi
  - AT+CIFSR  : affiche l'adresse IP de l'ESP8266 et l'adresse MAC
  
  NOTE: AJOUTER LES LIGNES SUIVANTES DANS LE FICHIER platformio.ini
  
    monitor_filters = send_on_enter
    monitor_echo = yes
*/

#include <Arduino.h>
#define VITESSE_MONITEUR  9600
#define VITESSE_ESP8266   115200
#define DELAI_BUFFER      500

void setup()
{
  Serial.begin(VITESSE_MONITEUR);     // Pour afficher les messages dans le moniteur série
  Serial1.begin(VITESSE_ESP8266);     // Pour communiquer avec l'ESP8266
  Serial.println("\nTester des commandes AT avec un ESP8266");
  Serial.println("\nEntrez une commande AT ou un message à envoyer à l'ESP8266");
  Serial.println("\nExemple: AT, AT+GMR, AT+CWLAP, AT+CWJAP=\"SSID\",\"password\", AT+CIFSR\n\n: ");
} // Fin de la fonction setup

void loop()
{
  if(Serial1.available())  // Vérifie si l'ESP8266 a envoyé des données
  {
    while(Serial1.available())
    {
      char c = Serial1.read();  // lit les données de l'ESP8266
      Serial.write(c);          // affiche les données dans le moniteur série
    }
  }

  if(Serial.available())
  {
    delay(DELAI_BUFFER);  // Attendre DELAI_BUFFER pour recevoir toutes les données
    // Lire les données du moniteur série et les stocker dans une chaîne de caractères
    String cmd = "";
    while(Serial.available())
    {
      cmd += (char)Serial.read();
    }
    // Envoyer la commande AT à l'ESP8266
    Serial1.println(cmd); 
  }
} // Fin de la fonction loop
