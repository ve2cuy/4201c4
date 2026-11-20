#include <Arduino.h>
#include "ansi.h"
#include <Streaming.h>

#define ANSI_ROUGE          "\033[31m"
#define ANSI_VERT           "\033[32m"
#define ANSI_BLEU           "\033[34m"
#define ANSI_JAUNE          "\033[33m"
#define ANSI_BLANC          "\033[0m"
#define CURSEUR_ON          "\033[?25h"
#define CURSEUR_OFF         "\033[?25l"

ANSI ansi(&Serial);

void setup() {
  Serial.begin(9600);
  ansi.clearScreen();
  Serial << CURSEUR_OFF << ANSI_BLANC;
  Serial << (F("╔══════════════════════════════════════════════════════╗\n"));
  Serial << (F("║      Exemple d'affichage avec séquences ANSI.        ║\n"));
  Serial << (F("╟──────────────────────────────────────────────────────╢\n"));
  Serial << (F("║                                                      ║\n"));
  Serial << (F("║                                                      ║\n"));
  Serial << (F("║ millis() =                                           ║\n"));
  Serial << (F("╚══════════════════════════════════════════════════════╝\n")); 
   ansi.gotoXY(3, 4);
  Serial << ANSI_ROUGE << "Je suis ROUGE";
  ansi.gotoXY(3, 5);
  Serial << ANSI_VERT << "Je suis VERT";
} // setup()

void loop(){
  ansi.gotoXY(14, 6);
  Serial << (millis() < 10000 ? ANSI_BLEU : ANSI_JAUNE) << millis();
} // loop()
