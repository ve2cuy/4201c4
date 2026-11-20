// Exemple d'utilisation de l'instruction 'enum'
#include <Streaming.h>

enum desFruits {
  pomme,
  cerise,
  kiwi,
  banane,
  fraise = 99
};

void setup() {
  Serial.begin(115200);

  desFruits unFruit = kiwi;

  switch (unFruit) {

    case kiwi: Serial << "Je suis un kiwi ;-)"; break;

    default: Serial << "Je suis un fruit non traité";
  } // switch

  Serial << " et j'ai la valeur: " << unFruit << endl; 
} // setup()

void loop() {
  // put your main code here, to run repeatedly:

}
