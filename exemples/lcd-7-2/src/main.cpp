#include <Arduino.h>
#include "Streaming.h"

void setup() {
  Serial.begin(9600);
  boolean yo = true;
  Serial << "Start" << endl;
  Serial << (yo ? "Vrai" : "faux");
}

void loop() {
}
