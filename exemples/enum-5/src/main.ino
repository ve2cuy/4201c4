/*
    Projet: Enum+Menu
    Auteur: Alain Boudreault
    Date:   2022.10.23
    ------------------------------------
    Description:  Exemple d'utilisation de l'instruction 'enum' pour la gestion
                  d'un menu affiché sur un LCD. 

*/

#define DEBUG
#define WOKWI
#include <Streaming.h>
#include "projet.h"       // Les 'define's du projet sont dans un fichier à part.

#ifdef WOKWI
#include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C ecranLCD(LCD_ADRESSE_I2C,LCD_NB_COLONNE,LCD_NB_LIGNE);   
#else
#include "rgb_lcd.h"  
  rgb_lcd ecranLCD;    
#endif


void setup() {
#ifdef DEBUG  
  Serial.begin(UART_VITESSE);
  Serial << "Début du projet enum+menu\n";
#endif
  pinMode(BOUTON, INPUT);
  ecranLCD.begin(LCD_NB_COLONNE, LCD_NB_LIGNE);
  ecranLCD.cursor_on();
  ecranLCD << "Ex d'un Menu";
  ecranLCD.setCursor(LCD_PREMIERE_COLONNE, LCD_LIGNE2);  
  ecranLCD << "Version 1.00";
  delay(DELAI_MSG_DEBUT);
  ecranLCD.clear();  // Effacer l'écran
  ecranLCD << "Menu1 Menu2 Menu3";
  ecranLCD.setCursor(LCD_PREMIERE_COLONNE, LCD_LIGNE1);
  ecranLCD.blink_on(); 
} // setup()

void loop() {
  static optionMenu choixMenu = menu1;
  static unsigned long compteurBouton = 0;
  
  int etatBouton = digitalRead(BOUTON);
  if ( etatBouton == HIGH) {
    delay(BOUTON_DELAI_REBOND);
    while (digitalRead(BOUTON)) ;
    delay(BOUTON_DELAI_REBOND);

    compteurBouton++;

    // Calculer le choix menu en fonction du reste d'une division par trois (3)
    // Note: Il y a trois options au Menu.
    choixMenu = compteurBouton % 3;

#ifdef DEBUG
    Serial << "\nChoix menu = " << choixMenu;
#endif
    // Afficher le choix courant sur le LCD
    ecranLCD.setCursor(LCD_PREMIERE_COLONNE, LCD_LIGNE3);                  
    ecranLCD << MSG_CHOIX_MENU_SELECTIONNE << choixMenu+1;


    // Déplacer le curseur du LCD en fonction de la sélection menu
    switch (choixMenu) {

      case menu1: ecranLCD.setCursor(MENU_POS_OPTION_1, LCD_POS_LIG_MENU);
                  break;
      case menu2: ecranLCD.setCursor(MENU_POS_OPTION_2, LCD_POS_LIG_MENU);
                  break;
      case menu3: ecranLCD.setCursor(MENU_POS_OPTION_3, LCD_POS_LIG_MENU);      
                  break;

      default: break;  // ERREUR!!!

    } // switch (choixMenu)
  } // if

} // loop()
