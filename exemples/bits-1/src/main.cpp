#include <arduino.h>
#include <Streaming.h>
#define VITESSE_SERIAL 9600
void setup() {
    Serial.begin(VITESSE_SERIAL);
    int a = 5;   // 0101 en binaire
    int b = 3;   // 0011 en binaire
    int result = a & b;  // 0001 en binaire
    Serial << "a & b = BIN: " << _BIN(result) << " DEC: " << result << endl; // Affiche 1
}
 
void loop(){}
