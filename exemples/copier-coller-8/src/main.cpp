/*
    Projet:  
    Auteur: Alain Boudreault
    Date:   2025.01.22
    --------------------------------------------------------------
    Description:

    Démonstration de l'utilisation de la mémoire RAM/Flash 
    entre une déclaration de type char[] et String
    RAM : 218, Flash: 1546  -> char[]
    RAM : 234, Flash: 2878  -> String

    Utilisation de la Macro F() -> Chaine en Mem Flash
    RAM : 188, Flash: 1560  -> char[]
    --------------------------------------------------------------
    Advanced Memory Usage is available via 
    "PlatformIO Home > Project Inspect"
    RAM:   [=         ]   9.2% (used 188 bytes from 2048 bytes)
    Flash: [          ]   4.8% (used 1560 bytes from 32256 bytes)
*/

#include <Arduino.h>
#define MESSAGE "abcdef"

#define TESTER_F
//#define STRING

#ifndef TESTER_F
  #ifdef STRING
    String msg = MESSAGE;
  #else
    char msg[] = MESSAGE;
  #endif
#endif

int i = 50;

void setup() {
   Serial.begin(115200);
#ifndef TESTER_F
   Serial.println("Début du programme...");
   Serial.println(msg);
#else   
   Serial.println(F("Début du programme..."));
   Serial.println(F(MESSAGE));
#endif   
}

void loop() {
}
