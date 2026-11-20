#include "MesUtilitaires.h"

void MesUtilitaires::clignoterLED(int pin, int fois) {
  for(int i = 0; i < fois; i++) {
    digitalWrite(pin, HIGH);
    delay(200);
    digitalWrite(pin, LOW);
    delay(200);
  }
}

float MesUtilitaires::convertirCelsiusVersF(float celsius) {
  return (celsius * 9.0 / 5.0) + 32.0;
}
