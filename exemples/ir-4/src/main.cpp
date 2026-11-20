/*
    Fichier:      ir-lire-codes.cpp
    Auteur:       Alain Boudreault
    Date:         2026.11.07
    Clientèle:    Étudiant(e)s du cours 420-1C4: Objets connectés de CSTJ.
    --------------------------------------------------------------------------
    Description:  Afficher, dans la console série, le protocole et le code
                  des touches d'une télécommande infrarouge.
    Module:       Grove - Infrared Receiver sur D2
    Référence:    https://wiki.seeedstudio.com/Grove-Infrared_Receiver/
    --------------------------------------------------------------------------
*/
#include <Arduino.h>
// Toute la librairie: simple, mais le programme sera plus gros.
#include <IRLibAll.h>

#define BROCHE_RECEPTEUR_IR   2
#define VITESSE_UART          9600

IRrecvPCI recepteurIR(BROCHE_RECEPTEUR_IR);  // Le récepteur (utilise une interruption)
IRdecode  decodeurIR;                        // Le décodeur des protocoles (NEC, Sony, ...)

void setup() {
  Serial.begin(VITESSE_UART);
  recepteurIR.enableIRIn();                  // Démarrer la réception
  Serial.println(F("Prêt à recevoir les signaux infrarouges ..."));
} // setup()

void loop() {
  // getResults() retourne vrai lorsqu'un signal complet a été reçu
  if (recepteurIR.getResults()) {
    decodeurIR.decode();                     // Décoder le signal
    decodeurIR.dumpResults(false);           // Afficher le résultat (false = version courte)
    recepteurIR.enableIRIn();                // Redémarrer la réception
  }
} // loop()
