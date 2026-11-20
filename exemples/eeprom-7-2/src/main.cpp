#include <Arduino.h>
#include <EEPROM.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  // Remettre toutes les cases à 255, la valeur d'une EEPROM neuve
  for (int adresse = 0; adresse < EEPROM.length(); adresse++) {
    EEPROM.update(adresse, 255);
  }
  digitalWrite(LED_BUILTIN, HIGH);   // La DEL intégrée (D13) indique la fin
} // setup()

void loop() {}
