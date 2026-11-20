#include <arduino.h>
#include <Streaming.h>
#define VITESSE_SERIAL 9600
void setup() {
    Serial.begin(VITESSE_SERIAL);
    int a = 5;   // 0101 en binaire
    int result = ~a;  // 1010 en binaire (en représentation complément à deux)
    // Tester avec unsigned int result
    Serial << "~a = BIN: " << _BIN(result) << " DEC: " << result << endl; // Affiche -6 (en complément à deux)
}
void loop(){}
