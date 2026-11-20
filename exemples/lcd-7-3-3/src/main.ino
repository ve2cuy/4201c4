/*
    Fichier:  bouton-modulo.ino
    Auteur:   Alain Boudreault
    Date:     2021.09.28
    ---------------------------------------------------------------------------
    Description: Exemple d'un projet qui tient compte de l'état précédent
                 du bouton momentané pour implémenter une rotation de choix 
                 en utilisant le reste d'une division

                 La DEL clignote une, deux ou trois fois selon le reste
                 de la division par trois du nombre de fois
                 que le bouton a été appuyé.

                 Note: Le reste de la division du compteur d'utilisation
                 du bouton retourne, dans l'ordre, les valeurs: 1,2 et 0

    ---------------------------------------------------------------------------
    M-A-J:
    --------------------------------------------------------------------------    
*/

// --------------------------
// Inclusion des librairies
#include "Streaming.h"
#include "rgb_lcd.h"

// --------------------------
// Les Macros
#define ON                              HIGH
#define OFF                             LOW
#define BROCHE_BOUTON                   4
#define BROCHE_DEL                      3
#define LCD_MSG_DIVISION                "Reste DIV/3 = "
#define LCD_POSITION_COL_RESTE_DIVISION 14
#define LCD_POSITION_LIG_RESTE_DIVISION 0
#define MAXIMUM_DELAI_BOUTON_APPUYE     500
#define NB_OPTIONS_MENU                 3

// --------------------------
// Les variables globales
unsigned long int accumulateur        = 0;      // NB fois bouton appuyé
rgb_lcd ecran;                                  // Objet pour controller le LCD


// ----------------------
void setup()
{
  Serial.begin(9600);
  Serial << "Début du programme\n-----------------------\n\n";
  ecran.begin(16,2);
  ecran << LCD_MSG_DIVISION;
  pinMode(BROCHE_BOUTON, INPUT);    
  pinMode(BROCHE_DEL, OUTPUT);
}

// ----------------------
void loop()
{
  if (digitalRead(BROCHE_BOUTON))                       // Lire le bouton
  {
    accumulateur++;                                     // Augmenter le compteur touche bouton
    ecran.setCursor(LCD_POSITION_COL_RESTE_DIVISION,    // Déplacer le curseur LCD à la position de la valeur modulo
                    LCD_POSITION_LIG_RESTE_DIVISION);
    ecran << accumulateur % NB_OPTIONS_MENU;            // Afficher le reste de la division sur le LCD
    delay(MAXIMUM_DELAI_BOUTON_APPUYE);                 // Gérer les rebonts du bouton 
  } // if digitalRead()                                  
} // loop()
