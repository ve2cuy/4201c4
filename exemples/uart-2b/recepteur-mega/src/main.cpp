/*
 Code du RECEPTEUR - sur le Mega
*/

#include <Arduino.h>
#include <SoftwareSerial.h>

#define UART_VITESSE        9600
// Le UNO et le MEGA sont reliés par les ports D6/D7 <-> D11/D10
// ATTENTION aux ports disponibles sur le MEGA pour SoftwareSerial  
#define UART_RX             10 
#define UART_TX             11

SoftwareSerial recepteur(UART_TX, UART_RX); // l'inverse du transmetteur

// --------------------------------------------------------
void setup() {
  Serial.begin(UART_VITESSE);
  Serial.println("Démarrage du récepteur...");
  recepteur.begin(UART_VITESSE);
}

// --------------------------------------------------------
void loop() {  
  byte unCode;
  if (recepteur.available()) {
    unCode = recepteur.read();
    // afficher la valeur du byte reçu
    Serial.print("Code recu = ");
    Serial.println(unCode);
   } // si byte disponible sur le UART
}
