#ifndef MAIN_H
#define MAIN_H
#include <Arduino.h>
#include <Wire.h>
#include "DS1307.h"
#include "Streaming.h"
#include "TM1637V2.h"
#include "ansi.h"
#include "rgb_lcd.h"

void traiter4Digit();
void traiterMoniteur();
void getPrintTimeLCD();

#define LED                 2           // GPIO pour la LED
#define BP                  3           // GPIO pour le bouton-poussoir
#define CLK                 8           // GPIO pour la TM1637V2
#define DIO                 9           // GPIO pour la TM1637V2
#define DEMI_SECONDE        500         // Délai pour le clignotement du séparateur ':'
#define SECONDE             1000        // Délai d'une seconde
#define DELAI_SCROLL        300         // Délai pour le défilement du texte sur le LCD
#define VITESSE_MONITEUR    115200      // Vitesse de transmission des données
#define ANSI_ROUGE          "\033[31m"
#define ANSI_VERT           "\033[32m"
#define ANSI_BLEU           "\033[34m"
#define ANSI_JAUNE          "\033[33m"
#define ANSI_BLANC          "\033[0m"
#define CURSEUR_ON          "\033[?25h"
#define CURSEUR_OFF         "\033[?25l"

const char* mois[] = {"", "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
const char* jour[] = {"", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};


#endif