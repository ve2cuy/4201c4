#include <Arduino.h>
#include <Streaming.h>
#define VITESSE_SERIAL  9600

void setup() {
    byte unByte = 99;
    Serial.begin(VITESSE_SERIAL);
    Serial << F("Début du programme ...\n");
    Serial << F("PI vaut : ") << PI << endl;
    Serial << "Fréquence CPU (Hz): " << F_CPU << '\n';
    Serial << "Utilisation d'un modificateur:" << endl;
    Serial << unByte << " est " << _BIN(unByte) << " en binaite et " << _HEX(unByte) << " en hex. " << endl;        
} // setup()

void loop() {
    static unsigned long i = 0;
    Serial << "i = " << ++i << endl; 
} // loop()
