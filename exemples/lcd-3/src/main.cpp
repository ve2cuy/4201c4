#include <Arduino.h>
// Inclure les fonctions (librairie) du LCD
#include "rgb_lcd.h"                

/*****************************************/
#define   UNE_SECONDE           1000
#define   LCD_NB_LIGNE          2
#define   LCD_NB_COLONNE        16
#define   LCD_LIGNE2            1
#define   LCD_PREMIERE_COLONNE  0
/*****************************************/

// Définir une variable globale* pour gérer le LCD - 
// * Explications en classe
rgb_lcd lcd;                                            
                                                        
void setup() {                    

    // Définir les specifications du LCD (16 colonnes, 2 lignes)  
    lcd.begin(LCD_NB_COLONNE,                     
              LCD_NB_LIGNE);                            

    // Aficher sur le LCD
    lcd.print("Bonjour 420 ;-)");                       
    delay(UNE_SECONDE);

    // Déplacer le curseur du LCD sur la ligne 1, colonne 0
    lcd.setCursor( LCD_PREMIERE_COLONNE , LCD_LIGNE2 ); 
    lcd.print("Objets connectes");                      

} // setup()

void loop() {}
