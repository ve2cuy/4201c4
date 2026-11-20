#include <Arduino.h>
#include "Streaming.h"

void setup(){
  Serial.begin(9600);
  unsigned char option = 2;
  Serial << "Option: ";

  switch (option) {

    case 0: Serial << "1" ;break;
    case 1: Serial << "2" ;break;
    case 2: Serial << "3" ;break;

    default: Serial << "Choix invalide!";

  } // switch()

} // setup()

void loop(){}
