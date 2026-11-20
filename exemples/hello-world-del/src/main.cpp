// -----------------------------------------------
// Projet: Introduction à Arduino
// Auteur: Alain Boudreault
// Date: 2026.01.25
// -----------------------------------------------
// Ajouter dans platformio.ini
// monitor_filters =
//  default   ; Retire les caractères de contrôle
//  time      ; Horodatage des lignes
//  log2file  ; Log les Serial.print dans le fichier “device-monitor-date-heure*.log” situé dans le dossier 'logs' du projet.

#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(13, 1); // OUTPUT
}

void loop() {
  static int i = 0;
  Serial.print("\nItération numéro: " + String(i++));
  digitalWrite(13, 1); // ON
  delay(500);
  digitalWrite(13, 0); // OFF
  delay(500);
}
