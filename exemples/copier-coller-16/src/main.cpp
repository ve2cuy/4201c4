#include <Arduino.h>
#include <rgb_lcd.h>

#define SECONDES_PAR_JOUR    86400
#define SECONDES_PAR_HEURE   3600
#define SECONDES_PAR_MINUTE  60
#define CENTIEME_PAR_SECONDE 100
#define LCD_NB_COLONNE       16
#define LCD_NB_LIGNE         2

rgb_lcd ecran;

void setup() {
    ecran.begin(LCD_NB_COLONNE, LCD_NB_LIGNE);
} // setup()

void loop() {
   char temps[17] = ""; // Longueur d'une ligne du LCD + un (0 pour fin de chaine)

   unsigned long lesMillis  = millis();
   unsigned long secondes   = lesMillis / 1000;
   unsigned long sec100     = lesMillis / 10 ;

   int jours    = secondes / SECONDES_PAR_JOUR;
   secondes     %= SECONDES_PAR_JOUR;
   byte heures  = secondes / SECONDES_PAR_HEURE;
   secondes     %= SECONDES_PAR_HEURE;
   byte minutes = secondes / SECONDES_PAR_MINUTE;
   secondes     %= SECONDES_PAR_MINUTE;
   sec100       %= CENTIEME_PAR_SECONDE; 
 
   snprintf(temps, sizeof(temps), "%03dj %02d:%02d:%02lu.%02lu", jours, heures, minutes, secondes, sec100);
   ecran.setCursor(0,0);
   ecran.print(temps);

} // loop()
