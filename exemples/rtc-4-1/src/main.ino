#include <Wire.h>
#include "DS1307.h"
#include "Streaming.h"

DS1307 horloge; // Définir un objet de type DS1307

void setup()
{
  Serial.begin(9600);
  Serial << "Debut du programme ...\n"; 

  horloge.begin();

  // 1 - Renseigner la date et l'heure
  // Note: À ne faire qu'une seule fois puis,
  // placer les lignes suivantes en commentaires
  horloge.fillByYMD(2025,02,26);
  horloge.fillByHMS(11,54,30);
  horloge.fillDayOfWeek(TUE);

  // 2 - Écrire le temps dans la puce RTC 
  horloge.setTime();

  // 3 - Lire le temps du RTC
  horloge.getTime();
  
  // 4 - Afficher l'heure
  Serial << "Il est " << horloge.hour << ":" << horloge.minute << ":" << horloge.second << endl;
  
} // setup

void loop() {} // loop
