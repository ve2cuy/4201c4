#include <Arduino.h>
#include <Wire.h>
#include "DS1307.h"
#include "Streaming.h"

// Prototypes des fonctions (exigés en C++ : une fonction est déclarée avant d'être appelée)
void AfficherLeTemps();

DS1307 clock; // Définir un objet de type DS1307

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
// Fonction: Afficher le temps dans la console série - version 1
// =============================================================
void AfficherLeTemps()
{
	clock.getTime();
	Serial.print(clock.hour, DEC);
	Serial.print(":");
	Serial.print(clock.minute, DEC);
	Serial.print(":");
	Serial.print(clock.second, DEC);
	Serial.print("	");
	Serial.print(clock.month, DEC);
	Serial.print("/");
	Serial.print(clock.dayOfMonth, DEC);
	Serial.print("/");
	Serial.print(clock.year+2000, DEC);
	Serial.print(" ");

  String nomDuJour;
	switch (clock.dayOfWeek)
	{
		case MON:
      nomDuJour = "Lundi";
		  break;
		case TUE:
		  nomDuJour = "Mardi";
		  break;
		case WED:
		  nomDuJour = "Mercredi";
		  break;
		case THU:
		  nomDuJour = "Jeudi";
		  break;
		case FRI:
		  nomDuJour = "Vendredi";
		  break;
		case SAT:
		  nomDuJour = "Samedi";
		  break;
		case SUN:
		  nomDuJour = "Dimanche";
		  break;
	}
	Serial << nomDuJour << " le " << clock.dayOfMonth << endl;
  delay(1000);
}
