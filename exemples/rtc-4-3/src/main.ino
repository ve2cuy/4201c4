#include <Wire.h>
#include "DS1307.h"
#include "Streaming.h"

DS1307 clock; // Définir un objet de type DS1307
// Variable utilisée par sprintf()
char chaine[80];
char* NomDesJours[] = {"", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};

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
  AfficherLeTemps();
} // loop


// =============================================================
// Fonction: Afficher le temps dans la console série - version 2
// =============================================================
void AfficherLeTemps()
{
  clock.getTime();
  // Remplacer les Serial.print par un sprintf()
  sprintf(chaine, "%02d:%02d:%02d  %02d/%02d/%02d,  ",
    clock.hour, clock.minute, clock.second, 
    clock.month, clock.dayOfMonth, clock.year+2000
  );
  Serial << chaine;

  // Remplacer le switch par un tableau de char*
  Serial << NomDesJours[clock.dayOfWeek] << " le " << clock.dayOfMonth << endl;
  delay(1000);
}
