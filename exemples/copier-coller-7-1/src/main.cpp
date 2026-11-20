/*
    Nos premiers pas avec un bouton interrupteur
    Lorsqu'appuyé, le bouton vaut 1 sinon, il vaut 0.
*/

#include <Arduino.h>
#include <Streaming.h>
#define LED             4
#define BOUTON          3
#define RELAI           2
#define VITESSE_SERIAL  9600

void setup() {
    Serial.begin(VITESSE_SERIAL);
    Serial << F("Début du programme ...\n");
    pinMode(LED, OUTPUT);
    pinMode(RELAI, OUTPUT);
    pinMode(BOUTON, INPUT);
    digitalWrite(LED,HIGH);
} // setup()

void loop() {
    static unsigned long i = 0;
    if (digitalRead(BOUTON)) {
      Serial << "Bouton appuyé " << ++i << " fois" << endl; 
      digitalWrite(RELAI, HIGH);
      while(digitalRead(BOUTON)); // tant que BOUTON appuyé
      delay(50);  // Debounce
      digitalWrite(RELAI, LOW);
    } // if
} // loop()
