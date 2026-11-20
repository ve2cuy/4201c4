// Solution du laboratoire: 3.3

#include <LiquidCrystal_I2C.h>

#define LCD_LIGNE_NO_1                0
#define LCD_LIGNE_NO_2                1
#define LCD_DEBUT_LIGNE               0
#define LCD_NB_LIGNE                  4
#define LCD_NB_COLONNE                20
#define DELAI_MSG_OUVERTURE           1000
#define LCD_ADRESSE_I2C               0x27
#define NOM_PROJET                    "Labo DOC11.4.4.2"
#define VERSION_PROJET                "sprintf et snprintf"
#define LONGUEUR_MSG                  LCD_NB_COLONNE + 1

LiquidCrystal_I2C ecranLCD(LCD_ADRESSE_I2C,LCD_NB_COLONNE,LCD_NB_LIGNE);
char msg[LONGUEUR_MSG];

void setup() {
  ecranLCD.begin(LCD_NB_COLONNE, LCD_NB_LIGNE);
  ecranLCD.print(NOM_PROJET);
  ecranLCD.setCursor(LCD_DEBUT_LIGNE, LCD_LIGNE_NO_2);
  sprintf(msg, "%s", VERSION_PROJET);
  ecranLCD.print(msg);
  delay(DELAI_MSG_OUVERTURE);
  ecranLCD.clear();
} // setup()

void loop() {

  static int compteur = 0;
  int temperature = 22;
  String moi = "moi moi";  // char moi[] = "moi moi";
  float pi = 3.141592;

  // Exemple 01

  ecranLCD.setCursor(LCD_DEBUT_LIGNE, LCD_LIGNE_NO_1);
  sprintf(msg, "c: %d, t: %d", compteur++, temperature);
  ecranLCD.print(msg);
  ecranLCD.setCursor(LCD_DEBUT_LIGNE, LCD_LIGNE_NO_2);
  sprintf(msg, "Je suis %s", moi.c_str());
  ecranLCD.print(msg); 


  // Exemple 02 - Forcer des espaces à gauche
  /*
  ecranLCD.setCursor(LCD_DEBUT_LIGNE, LCD_LIGNE_NO_1);
  sprintf(msg, "c: %5d, t: %d", compteur++, temperature);
  ecranLCD.print(msg);
  */


  // Exemple 03 - Forcer des 0 à gauche
  /*
  ecranLCD.setCursor(LCD_DEBUT_LIGNE, LCD_LIGNE_NO_1);
  sprintf(msg, "c: %05d, t: %d", compteur++, temperature);
  ecranLCD.print(msg);
  */

  // Exemple 04 - Les nombres réels
  // La fonction sprintf de Arduino IDE ne supporte pas les nombres réels (float, double)
  /*
  ecranLCD.setCursor(LCD_DEBUT_LIGNE, LCD_LIGNE_NO_1);
  sprintf(msg, "PI = %f", pi);
  ecranLCD.print(msg); 
  */

  // Voici une solution
  /*
    ecranLCD.setCursor(LCD_DEBUT_LIGNE, LCD_LIGNE_NO_1);
    #define LONGUEUR_CHAINE 8
    #define NB_DECIMALES    6
    char szF[LONGUEUR_CHAINE + 1];
    dtostrf( pi, LONGUEUR_CHAINE, NB_DECIMALES, szF );
    sprintf( msg, "PI = %s", szF );
    ecranLCD.print(msg); 
  */
} // loop()
