#include <Arduino.h>
#include "Streaming.h"

enum Menu {
  option1 = 1, 
  option2 = 2, 
  option3 = 0 
};


void setup(){
  Serial.begin(9600);

  Menu unMenu = 0;

  switch (unMenu) {

    case option1: Serial << "Option 1"; break;
    case option2: Serial << "Option 2"; break;
    case option3: Serial << "Option 3"; break;

    default: Serial << "Choix invalide!";
  } // switch

} // setup()


void loop(){}
