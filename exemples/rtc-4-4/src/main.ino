#include <Wire.h>
#include "DS1307.h"
#include "Streaming.h"
char* AfficherLeTemps();

DS1307 clock; // Définir un objet de type DS1307

// Variable utilisée par sprintf()
char chaine[80];

const char* NomDesJours[] = {"", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};

void setup()
{
  Serial.begin(9600);
  Serial << "Debut du programme ...\n"; 
	clock.begin();
  /*
	clock.fillByYMD(2021,10,26);
	clock.fillByHMS(11,54,30);
	clock.fillDayOfWeek(TUE); 
	clock.setTime(); //Écrire le temps dans la puce RTC
  */
} // setup

void loop()
{
  Serial << AfficherLeTemps() << endl;
  delay(1000);
} // loop


// =============================================================
// Fonction: Forme une chaine représentant le temps courant - V3
// Retour:   Un pointeur vers une chaine de caractères décrivant
//           le temps courant.
// =============================================================
char* AfficherLeTemps()
{
  clock.getTime();
  sprintf(chaine, "%02d:%02d:%02d  %02d/%02d/%02d,  %s le %02d",
    clock.hour, clock.minute, clock.second, 
    clock.month, clock.dayOfMonth, clock.year+2000,
    NomDesJours[clock.dayOfWeek], clock.dayOfMonth
  );

  return chaine;

} // AfficherLeTemps
