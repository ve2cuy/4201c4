#define WOKWI

/*****************************************/
#define   BOUTON                2
#define   BOUTON_DELAI_REBOND   5
#define   DELAI_MSG_DEBUT       3000
#define   LCD_DELAI             50
#define   LCD_NB_LIGNE          2
#define   LCD_NB_COLONNE        16
#define   LCD_LIGNE2            1
#define   LCD_PREMIERE_COLONNE  0
#define   LCD_POSITION_COMPTEUR 10
#define   LCD_ADRESSE_I2C       0x27
/*****************************************/

#ifdef WOKWI
#include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C ecranLCD(LCD_ADRESSE_I2C,LCD_NB_COLONNE,LCD_NB_LIGNE);   
#else
#include "rgb_lcd.h"  
  rgb_lcd ecranLCD;    
#endif


void setup() {
  pinMode(BOUTON, INPUT);
  ecranLCD.begin(LCD_NB_COLONNE, LCD_NB_LIGNE);
  ecranLCD.print("Debut du projet");
  // Placer le curseur au début de la ligne no 2
  // Écrire votre prenom
  ecranLCD.setCursor(LCD_PREMIERE_COLONNE, LCD_LIGNE2);  
  ecranLCD.print("Version 1.0beta");
  delay(DELAI_MSG_DEBUT);
  ecranLCD.clear();  // Effacer l'écran
  ecranLCD.print("Alarme TI-CSTJ");
  ecranLCD.setCursor(LCD_PREMIERE_COLONNE, LCD_LIGNE2); 
  ecranLCD.print("Compteur: ");
} // setup()

void loop() {
  static unsigned int compteurBouton = 0;
  int etatBouton = digitalRead(BOUTON);
  delay(BOUTON_DELAI_REBOND);  // debounce du bouton
  ecranLCD.setCursor(LCD_POSITION_COMPTEUR, LCD_LIGNE2); 
  ecranLCD.print(compteurBouton);
  
  if ( etatBouton == HIGH) {
      compteurBouton++;
      while (digitalRead(BOUTON)) ;
      delay(BOUTON_DELAI_REBOND);
  }

} // loop()
