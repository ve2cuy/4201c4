/*
    Fichier:      ir-controler-del.cpp
    Auteur:       Alain Boudreault
    Date:         2026.11.07
    --------------------------------------------------------------------------
    Description:  Allumer et éteindre une DEL avec deux touches d'une
                  télécommande infrarouge de protocole NEC.
    Modules:      Grove - Infrared Receiver sur D2, DEL sur D4
    --------------------------------------------------------------------------
*/
#include <Arduino.h>
#include <IRLibDecodeBase.h>    // La base du décodeur
#include <IRLib_P01_NEC.h>      // Seulement le protocole utilisé: programme plus petit
#include <IRLibCombo.h>         // Après tous les protocoles
#include <IRLibRecvPCI.h>       // Le récepteur

#define BROCHE_RECEPTEUR_IR   2
#define BROCHE_DEL            4
#define VITESSE_UART          9600

// Codes des touches: à remplacer par ceux de votre télécommande (section 4)
#define TOUCHE_1              0xFF30CF
#define TOUCHE_2              0xFF18E7

IRrecvPCI recepteurIR(BROCHE_RECEPTEUR_IR);
IRdecode  decodeurIR;

void setup() {
  Serial.begin(VITESSE_UART);
  pinMode(BROCHE_DEL, OUTPUT);
  recepteurIR.enableIRIn();
  Serial.println(F("Touche 1: allumer, touche 2: éteindre"));
} // setup()

void loop() {
  if (recepteurIR.getResults()) {
    decodeurIR.decode();
    if (decodeurIR.protocolNum == NEC) {
      switch (decodeurIR.value) {
        case TOUCHE_1: digitalWrite(BROCHE_DEL, HIGH);
                       Serial.println(F("DEL allumée"));
                       break;
        case TOUCHE_2: digitalWrite(BROCHE_DEL, LOW);
                       Serial.println(F("DEL éteinte"));
                       break;
        default:       Serial.print(F("Touche non utilisée: 0x"));
                       Serial.println(decodeurIR.value, HEX);
      } // switch
    } // if NEC
    recepteurIR.enableIRIn();
  } // if getResults()
} // loop()
