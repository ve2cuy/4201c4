#include <Arduino.h>
#include "Streaming.h"
#include "rgb_lcd.h"

rgb_lcd LCD2x16;

void setup(){
  Serial.begin(9600);
  LCD2x16.begin(16,2);
  unsigned char option = 3;
  Serial << "Option: ";
  LCD2x16 << "Option: ";
  switch (option) {

    case 0: Serial << "1";
            LCD2x16 << "1"; 
            break;

    case 1: Serial << "2"; 
            LCD2x16 << "2"; 
            break;

    case 2: Serial << "3";
            LCD2x16 << "3"; 
            break;

    default: Serial << "Choix invalide!";
             LCD2x16 << "Invalide!"; 

  } // switch()


}

void loop(){}
