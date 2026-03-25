/*
lib_deps = 
	robtillaart/ANSI@^0.3.2
	seeed-studio/Grove - LCD RGB Backlight @ ^1.0.2
	mikalhart/Streaming @ ^1.0.0
	seeed-studio/Grove SHT31 Temp Humi Sensor@^1.0.0
	seeed-studio/Grove - RTC DS1307@^1.0.0
*/

#include <Arduino.h>
#include "TM1637V2.h"
#define CLK                 8           // GPIO pour la TM1637V2
#define DIO                 9           // GPIO pour la TM1637V2
void AfficherSur4Digit(float unNombre);

TM1637V2  affichage(CLK, DIO);

void setup() {
}

void loop() {
  AfficherSur4Digit(12.34);

  /*
 // Étape 03 - Gestion non bloquante de l'affichage de l'heure sur le 4-Digit
  static unsigned long previous4DigitMillis = 0;
    // Nous utilisons une variable ici pour ne pas appeler la fonction millis() plusieurs fois
  unsigned long current4DigitMillis = millis(); 
  if (current4DigitMillis - previous4DigitMillis >= SECONDE / 2) {
    previous4DigitMillis = current4DigitMillis;
     AfficherSur4Digit(12.34);
  } // if  

  */
  // delay(500);
}

void AfficherSur4Digit(float unNombre) {
    affichage.displayNum(1234);
    delay(500);
    affichage.displayNum(12.34,2);
    delay(500);
  } // traiter4Digit


/*
// Étape 02
void AfficherSur4Digit(float unNombre) {
    static bool tick = false;
    int nombreInt = unNombre * 100 ;  // Pour affichage sans ':'
     // En fonction de la valeur de 'tick' afficher l'heure int ou float à 2 dec.
    affichage.displayNum(tick ? nombreInt : unNombre, tick ? 0 : 2);
    tick ^= true;  // Inverser la valeur de la variable boolean
} // traiter4Digit
*/

