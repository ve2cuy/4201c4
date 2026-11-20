#include <Arduino.h>
#include <Streaming.h> 
#define INIT_SERIAL Serial.begin(9600);  // Remarquer la MACRO!
#define DELAI_AFFICHAGE 1000
void setup() {
  INIT_SERIAL
} // setup

void loop() {
  // Une variable de type 'static' n'est initialisée qu'une seule fois durant l'exécution du programme 
  static unsigned long int unNombre = 0;
  Serial << unNombre << " est un nombre : ";
  
  if (unNombre % 2) {
    Serial  << "impair,\t";
  } else Serial  << "pair,  \t" ;

  Serial << unNombre << " % 2 = " << (unNombre % 2) << endl;
  unNombre++;
  delay(DELAI_AFFICHAGE);

} // loop
