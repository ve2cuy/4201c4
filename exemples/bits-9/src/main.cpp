#include <Arduino.h>
#include "Streaming.h"

#define APP_LED1          0b1 << 0 // 0000 0001
#define APP_LED2          0b1 << 1 // 0000 0010
#define APP_RELAI         0b1 << 2 // 0000 0100
#define APP_MOUVEMENT     0b1 << 3 // 0000 1000
#define ALARM_ARME        0b1 << 4 // 0001 0000

struct Appareils{
  byte  etatAppareils;  // Traitement sur les bits.
  float temperature;
};

struct Systeme {
  byte  codeMessage;
  byte  heure;
  byte  minute;
  byte  seconde;
  Appareils appareils;
};

const char * lesMessages[] = {
  "Information sur le système",
  "Température élevée",
  "Mouvement détecté",
  "En état de panique"
};

Systeme unSysteme = { 1, 10, 10, 59, { 0b00010001, 20.2} };

void setup() {
  Serial.begin(9600);
  Serial.println("Début du programme\n");

  if (unSysteme.appareils.etatAppareils & ALARM_ARME) {
    Serial.println("Le système d'alarme est armé");
  }

  if (unSysteme.appareils.etatAppareils & APP_LED1) {
    Serial.println("La DEL1 est ON");
  }

  if (unSysteme.appareils.etatAppareils & APP_LED2) {
    Serial.println("La DEL2 est ON");
  } else {
    Serial.println("La DEL2 est OFF");
  }
  Serial << "\nMessage reçu: " << lesMessages[unSysteme.codeMessage] << endl;
  Serial << "Il est " << unSysteme.heure << ":" << unSysteme.minute << ":" << unSysteme.seconde << endl;
}

void loop() {
  // Rien à faire ici ...
}
