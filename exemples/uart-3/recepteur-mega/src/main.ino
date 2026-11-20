/*
 Laboratoire 3: Réception/transmission d'une chaine de caractères
 Code du récepteur (MEGA)
 Version chaine de caractères
*/

#include <SoftwareSerial.h>
#include "Streaming.h"

// Le RX du UNO doit être connecté au TX du MEGA et TX -> RX
// Il faut donc inverser les signaux:
#define UART_RX             10
#define UART_TX             11
#define UART_VITESSE        9600
#define UNE_SECONDE         1000

SoftwareSerial recepteur(UART_TX, UART_RX); // RX, TX

// --------------------------------------------------------
void setup() {
  Serial.begin(UART_VITESSE);
  Serial.println("Démarrage du récepteur...");
  // Initialiser le port serie 'SoftwareSerial'
  recepteur.begin(UART_VITESSE);
}

// --------------------------------------------------------
void loop() {  
  String unMessage;
  if (recepteur.available()) {
    // delay(50); // attendre la réception des données
    Serial << "Il y a " << recepteur.available() << " octets disponibles." << endl; 
    unMessage = recepteur.readString();
    // afficher les données lues
    Serial << "Message recu = " << unMessage << endl;
  } // si données disponibles sur le UART
}
// Fin du code
