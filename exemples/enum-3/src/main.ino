#include "Streaming.h"

enum Menu {
  option1 = 1, 
  option2 = 2, 
  option3 = 0 
};


void setup(){
  Serial.begin(9600);

  Menu unMenu = option3;

  switch (unMenu) {

    case option1: Serial << "Option 1\n"; break;
    case option2: Serial << "Option 2\n"; break;
    case option3: Serial << "Option 3\n"; break;

    default: Serial << "Choix invalide!\n";
  } // switch

} // setup()


void loop(){}
