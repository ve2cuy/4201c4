#include <Arduino.h>
#define DEL_ROUGE 13
#define SORTIE 1
#define ALLUMER 1
#define ETEINDRE 0
#define DELAI 500

void setup() {
  pinMode(DEL_ROUGE, SORTIE);
}

void loop() {
  digitalWrite(DEL_ROUGE, ALLUMER);
  delay(DELAI);
  digitalWrite(DEL_ROUGE, ETEINDRE);
  delay(DELAI);
}
