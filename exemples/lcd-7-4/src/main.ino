#include "Streaming.h"

enum Menu {
  option1,   // vaut 0
  option2,   // vaut 1
  option3    // vaut 2
};


void setup(){
  Serial.begin(9600);

  Menu unMenu = option2;

  switch (unMenu) {

    case option2: Serial << "Option 2"; break;

    default: Serial << "Choix invalide!";
  } // switch

} // setup()

void loop(){}
