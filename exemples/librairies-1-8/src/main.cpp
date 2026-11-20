#include <Arduino.h>
#include "MesUtilitaires.h"

void setup() {
  pinMode(13, OUTPUT);
  MesUtilitaires::clignoterLED(13, 5);
}

void loop() {
  // ...
}
